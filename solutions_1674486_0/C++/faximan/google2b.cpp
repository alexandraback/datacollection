//
//  google2b.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-05.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

int n;

struct edge;
struct vertex
{
	int cost;
	edge *prev; // The edge used to come to this vertex
};
struct edge
{
	vertex *from, *to;
	int weight;
};
vertex v[1002];
int numv = 0;
edge e[1001*1001];
int nume = 0;

bool ShortestPath(vertex* source, vertex* dest)
{
	for(int i = 0; i < numv; ++i)
	{
		v[i].cost = 0x3FFFFFFF;
		v[i].prev = 0;
	}
	source->cost = 0; // The next line sets the source visited
	source->prev = (edge*)-1; // reinterpret_cast<edge*>(-1)
	for(int n = 1; n <= numv; ++n)
	{
		// Improving the costs iteration 1..numv-1,
		// checking for negative cycles the last iteration
		for(int i = 0; i < nume; ++i)
		{
			if(e[i].from->prev) // Have visited the vertex?
			{
				int newCost= e[i].from->cost + e[i].weight;
				if(newCost < e[i].to->cost)
				{
					if (n == numv) 
						// Can still improve the cost,
						return false; // negative cycle exist
					e[i].to->cost = newCost;
					e[i].to->prev = &e[i]; // Save predecessor
				}
			}
		}
	}
	if(!dest->prev)
		return false; // Could not reach the end
	return true;
}

using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int tt = 1; tt<= t; tt++)
	{
		cout << "Case #" << tt << ": ";
		cin >> numv;
		nume = 0;
		for(int i = 0; i < numv; i++)
		{
			int ee;
			cin >> ee;
			for(int j = 0; j < ee; j++)
			{
				int cur;
				cin >> cur;
				cur--;
				edge newedge;
				
				newedge.weight = 1;
				newedge.from = &v[i];
				newedge.to = &v[cur];
				e[nume++] = newedge;
			}
		}
		
		bool ok = false;
		for(int i = 0; i < numv; i++)
		{
			for(int j = 0; j < numv; j++)
			{
				if(i==j)continue;
				if(ShortestPath(&v[i], &v[j]))
				{
					edge *myedge = v[j].prev;
					vertex *myvertex = v[j].prev->from; 
					myedge->from = &v[1001];
					if(ShortestPath(&v[i], &v[j]))
					{
						ok = true;
						break;
					}
					myedge->from = myvertex;
				}
			}
		}
		
		if(ok)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		
	}
	
	return 0;
}