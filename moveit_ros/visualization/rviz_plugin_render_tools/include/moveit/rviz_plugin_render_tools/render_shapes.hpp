/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2012, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Ioan Sucan */

#pragma once

#include <moveit/rviz_plugin_render_tools/octomap_render.hpp>
#include <moveit/macros/class_forward.hpp>
#include <geometric_shapes/shapes.h>
#include <rviz_common/properties/color_property.hpp>
#include <rviz_common/display_context.hpp>
#include <rviz_rendering/objects/shape.hpp>
#include <OgreColourValue.h>
#include <Eigen/Geometry>
#include <memory>

namespace moveit_rviz_plugin
{
MOVEIT_CLASS_FORWARD(OcTreeRender);  // Defines OcTreeRenderPtr, ConstPtr, WeakPtr... etc
MOVEIT_CLASS_FORWARD(RenderShapes);  // Defines RenderShapesPtr, ConstPtr, WeakPtr... etc

class RenderShapes
{
public:
  RenderShapes(rviz_common::DisplayContext* context);
  ~RenderShapes();

  void renderShape(Ogre::SceneNode* node, const shapes::Shape* s, const Eigen::Isometry3d& p,
                   OctreeVoxelRenderMode octree_voxel_rendering, OctreeVoxelColorMode octree_color_mode,
                   const Ogre::ColourValue& color, double alpha);
  void updateShapeColors(double r, double g, double b, double a);
  void clear();

private:
  rviz_common::DisplayContext* context_;

  std::vector<std::unique_ptr<rviz_rendering::Shape> > scene_shapes_;
  std::vector<OcTreeRenderPtr> octree_voxel_grids_;
};
}  // namespace moveit_rviz_plugin
