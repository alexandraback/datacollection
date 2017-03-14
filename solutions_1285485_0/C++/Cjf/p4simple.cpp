#include "p4simple.h"
#include "Segment2d.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <assert.h>
using namespace std;

#define reflect(pivot,x) ( (pivot)*2-(x) )

p4simple::p4simple(void)
{
}


p4simple::~p4simple(void)
{
}

void p4simple::solve()
{
	ifstream fin("D-small-attempt0 (1).in");
	ofstream fout("D-small-attempt0 (1).out");

	int t;
	fin >> t;
	for ( int tests = 1; tests <= t; ++tests ) 
	{
		int n, m; int d;
		fin >> n >> m >> d;

		vector<Segment2d> walls;
		walls.push_back( Segment2d( Point2d(1, 1), Point2d(1, m-1) ) );
		walls.push_back( Segment2d( Point2d(1, 1), Point2d(n-1, 1) ) );
		walls.push_back( Segment2d( Point2d(n-1, m-1), Point2d(1, m-1) ) );
		walls.push_back( Segment2d( Point2d(n-1, m-1), Point2d(n-1, 1) ) );
		
		Point2d me;
		char corr;
		for ( int i=1; i<=n; ++i )
			for ( int j=1; j<=m; ++j )
			{
				fin >> corr;
				if ( corr=='X' ) me = Point2d(i-0.5, j-0.5);
			}

		vector<Point2d> dedicates, intersections;
		for ( int i=-d-3; i<=d+3; ++i )
			for ( int j=-d-3; j<=d+3; ++j )
			{
				//Grid Points
				dedicates.push_back( Point2d(1+(n-2)*i, 1+(m-2)*j) );

				//Reflections:					
				Point2d newp;
				if ( (i+10000)%2 == 0 ) newp.x = me.x + (n-2)*i;
				else newp.x = reflect( 1+(n-2)*i, me.x + (n-2)*(i-1));
				if ( (j+10000)%2 == 0 ) newp.y = me.y + (m-2)*j;
				else newp.y = reflect( 1+(m-2)*j, me.y + (m-2)*(j-1));
				dedicates.push_back(newp);
			}
		
		for ( int dc=0; dc<dedicates.size(); ++dc )
		{
			Point2d ee = dedicates[dc];
			if ( ee==me ) continue;
			Segment2d seg = Segment2d(me, ee);

			double dist = seg.length();
			if ( (dc%2)==0 ) dist*=2;
			if ( !leq(dist, d) ) continue;

			Point2d ins;
			int w;
			for ( w=0; w<4; ++w )
				if ( walls[w].intersectWith(seg, ins) )
					break;
			assert(w<4);
			
			bool already = 0;
			for ( int j=0; j<intersections.size(); ++j )
				if ( intersections[j]==ins )
				{
					already = 1;
					break;
				}
			if ( !already ) intersections.push_back(ins);
		}
		fout << "Case #" << tests << ": " << intersections.size() << endl;
	}
}