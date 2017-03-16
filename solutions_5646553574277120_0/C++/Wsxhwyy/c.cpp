#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;
ofstream fout("c.out");

int have[1000];
int d[10],v[1000],newv[1000];
int dfsv[10][1000];
int mindep;
int T,C,D,V;

void dfs(int depth, int can)
{
	if (can == V)
	{
		if (mindep > depth)
		{
			mindep = depth;
			for (int i = 0; i <= V; i++)
			{
				if (have[i])
				{
					bool find = false;
					for (int j = 0; j < D; j++)
						if (d[j] == i)
							find = true;
					if (!find)
						cout << i << ' ';
				}
			}
			cout << endl;
		}
	}
	else
	{
		if (depth >= mindep)
			return;
		else
		{
			int newcan = can;
			for (int i = 1; i <= V; i++)
				if (!have[i])
				{
					int add = i;
					memcpy(newv, dfsv[depth], sizeof v);
					for (int j = 0; j + add <= V; j++)
					{
						if (dfsv[depth][j]){
							if(!dfsv[depth][j + add])
							{
								newv[j + add] = 1;
								newcan++;
							}
						} 
					}
					memcpy(dfsv[depth + 1], newv, sizeof v);
					have[add] = 1;
					dfs(depth + 1, newcan);
					have[add] = 0;
				}
		}
	}
}

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> C >> D >> V;
		memset(v, 0, sizeof v);
		memset(dfsv, 0, sizeof dfsv);
		memset(have, 0, sizeof have);
		for (int i = 0; i < D; i++)
		{
			cin >> d[i];
			have[d[i]] = 1;
		}
		v[0] = 1;
		int can = 0;
		for (int i = 0; i < D; i++)
		{
			memcpy(newv, v, sizeof v);
			for (int j = 0; j + d[i] <= V; j++)
			{
				if (v[j]){
					if(!v[j + d[i]])
					{
						newv[j + d[i]] = 1;
						can++;
					}
				} 
			}
			memcpy(v, newv, sizeof v);
		}
		int tot = 0;
		mindep = 6;
		memcpy(dfsv[0], v, sizeof v);
		dfs(0, can);
		fout << "Case #" << t << ": " << mindep << endl;
		cout << "Case #" << t << ": " << mindep << endl;
	}
}
