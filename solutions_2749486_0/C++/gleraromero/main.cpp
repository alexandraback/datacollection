#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

#define slong long long int
#define mapParents map< pair<int,int> , pair<int,int> >
using namespace std;

struct Pos
{
	slong x;
	slong y;
	slong step;
	
	Pos(slong _x, slong _y, slong _step)
	{
		x = _x;
		y = _y;
		step = _step;
	}
};

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << (t+1) << ": ";
		
		slong X, Y;
		cin >> X >> Y;
		
		mapParents parents;
		queue<Pos> pendientes;
		pendientes.push(Pos(0,0,1));
		parents[make_pair(0,0)] = make_pair(-1e10,-1e10);
		
		// 			Arriba, Abajo, Izq, Der
		slong dx[] = { 0, 0, -1, 1 };
		slong dy[] = { 1, -1, 0, 0 };
		
		bool found = false;
		while (!pendientes.empty())
		{
			Pos a = pendientes.front(); 
			pendientes.pop();
			
			for (int i = 0; i < 4; ++i)
			{
				slong nx = a.x + dx[i]*a.step;
				slong ny = a.y + dy[i]*a.step;
				
				if (parents.find(make_pair(nx,ny)) == parents.end())
				{
					parents[make_pair(nx,ny)] = make_pair(a.x,a.y);
				
					if (nx == X && ny == Y)
					{
						found = true;
						break;
					}
				
					pendientes.push(Pos(nx,ny,a.step+1));
				}
			}
			if (found)
				break;
		}
		
		string res;
		pair<int,int> p = make_pair(X,Y);
		pair<int,int> pp = parents[p];
		while (true)
		{
			// Vine de abajo.
			if (pp.second < p.second)
				res += "N";
			else if (pp.second > p.second)
				res += "S";
			else if (pp.first < p.first)
				res += "E";
			else
				res += "W";
			
			if (pp.first == 0 && pp.second == 0)
				break;
			
			p = pp;
			pp = parents[p];
		}
		
		cout << string ( res.rbegin(), res.rend() ) << endl;
	}
	return 0;
}
