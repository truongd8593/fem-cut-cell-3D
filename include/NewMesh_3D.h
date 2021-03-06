/* The fem-cut-cell-3D software
 * Author	  : Afonso Alborghetti Londero (afonsoal@gmail.com)
 * Last update:	08/Sep/2015
 *
 * NewMesh_3D.h
 *
 * This file is part of the fem-cut-cell-3D software, built using the deal.ii
 * library. You are free to use it under the GNU Lesser General Public License
 * as described in the LICENSE File.
 * Copyright (c) <2015> <Afonso Alborghetti Londero>
 *
 * ---------------------------------------------------------------------
 * deal.ii license information
 *
 * Copyright (C) 1999 - 2013 by the deal.II authors
 *
 * The deal.II library is free software; you can use it, redistribute
 * it, and/or modify it under the terms of the GNU Lesser General
 * Public License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * The full text of the license can be found in the file LICENSE at
 * the top level of the deal.II distribution.
 *
 * ---------------------------------------------------------------------
 *
 */

#ifndef NEWMESH_3D_H_
#define NEWMESH_3D_H_

#include <deal.II/base/config.h>
#include <deal.II/base/exceptions.h>
#include <deal.II/base/point.h>
#include <deal.II/base/table.h>
#include <deal.II/grid/tria.h>
#include <map>

using namespace dealii;
class NewMesh_3D
{
private:

	int dofs_per_cell;
	int new_cell_counter;
	int new_vertices_index;

	// Structure containing the information relevant to create a new triangulation.
	struct new_cell_struct
	{
		std::vector <Point<3>> new_vertices_cell; // size = 8; will repeat between cells
		CellData<3> new_cells; // 8 vertices
		bool cell_is_boundary;
		int custom_cell_index;
	};
	std::vector <Point<3>> new_vertices_vector;
	std::vector <int> new_vertices_vector_index;
//	enum
//	{
//	not_surface_domain_id,
//	surface_domain_id
//	};

public:
	std::vector<new_cell_struct> vector_new_cell_struct;
	std::vector<Point<3> > support_points;
	NewMesh_3D();
	void reinit();
	void set_variables(const std::vector<Point<3> > & _support_points,
		const int _dofs_per_cell);

	void set_new_mesh (std::vector<types::global_dof_index> cell_global_dof_indices,
			const bool cell_is_boundary );
	void create_new_triangulation (Triangulation<3> &tria);
	void set_triangulation_indices (Triangulation<3> &tria);

};

#endif

