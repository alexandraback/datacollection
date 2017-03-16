#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>                                                                                                                                                                                  
#include <map>                                                                                                                                                                                    
#include <iostream>                                                                                                                                                                               
#include <set>                                                                                                                                                                                    
#include <cmath>                                                                                                                                                                                  
#include <cassert>                                                                                                                                                                                
#include <ctime>                                                                                                                                                                                  
#include <string>                                                                                                                                                                                 
using namespace std;    
int nextint(){int _;scanf("%d",&_);return _;}
double nextdouble(){double _;scanf("%lf",&_);return _;}

void addBomb(vector<vector<bool> > &bomb, vector<vector<int> > &g, int i, int j)
{
	bomb[i][j] = true;

	for(int ii = -1; ii <= 1; ii++)
		for(int jj = -1; jj <= 1; jj++)
			if(0 <= i+ii && i+ii < g.size() && 0 <= j+jj && j+jj < g[0].size())
				g[i+ii][j+jj]++;
}

void removeBomb(vector<vector<bool> > &bomb, vector<vector<int> > &g, int i, int j)
{
	bomb[i][j] = false;

	for(int ii = -1; ii <= 1; ii++)
		for(int jj = -1; jj <= 1; jj++)
			if(0 <= i+ii && i+ii < g.size() && 0 <= j+jj && j+jj < g[0].size())
				g[i+ii][j+jj]--;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t = nextint();
	for(int test = 1; test <= t; test++)
	{
		int n = nextint();
		int m = nextint();
		int c = nextint();
		int wac = c;

		vector<vector<bool> > bomb(n, vector<bool> (m));
		vector<vector<int> > g(n, vector<int> (m));

		bool ok = true;
		if(n*m - c == 1)
		{
			bomb = vector<vector<bool> > (n, vector<bool> (m, true));
			g = vector<vector<int> > (n, vector<int> (m, 1));
			bomb[0][0] = false;
			g[0][0] = 0;
		}
		else
		{
			if(n == 1 || m == 1)
			{
				if(n == 1)
					for(int i = 0; i < c; i++)
						addBomb(bomb, g, 0, i);
				else
					for(int i = 0; i < c; i++)
						addBomb(bomb, g, i, 0);
			}
			else if (n == 2 || m == 2)
			{
				if(c%2 == 1)
				{
					ok = false;
				}
				else
				{
					if(n == 2)
					{
						for(int i = 0; i < c/2; i++)
						{
							addBomb(bomb, g, 0, i);
							addBomb(bomb, g, 1, i);
						}
					}
					else
					{
						for(int i = 0; i < c/2; i++)
						{
							addBomb(bomb, g, i, 0);
							addBomb(bomb, g, i, 1);
						}
					}
				}
			}
			else
			{
				for(int i = 0; i < n-3; i++)
				{
					if(c == 0) break;
					for(int j = 0; j < m; j++)
					{
						if(c == 0) break;

						addBomb(bomb, g, i, j);
						c--;
					}
				}

				if(c > 0)
				{
					int frees = 3*m - c;

					if(frees < 4 || frees == 5 || frees == 7)
					{
						ok = false;
					}
					else
					{
						int tris = frees/3;
						frees%=3;
						int twos = 0;
						if(frees%2 == 1)
						{
							tris--;
							frees += 3;
						}
						twos = frees/2;
						frees = 0;

						for(int i = 0; i < m; i++)
						{
							if(tris > 0)
							{
								tris--;
							}
							else if(twos > 0)
							{
								twos--;
								addBomb(bomb, g, n-3, i);
							}
							else
							{
								addBomb(bomb, g, n-1, i);
								addBomb(bomb, g, n-2, i);
								addBomb(bomb, g, n-3, i);
							}
						}
					}
				}
				else // c==0
				{
					if(wac%m == m-1)
					{
						removeBomb(bomb, g, wac/m, m-2);
						addBomb(bomb, g, wac/m+1, 0);
					}
				}
			}
		}

		pair<int, int> cc(-1, -1);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(g[i][j] == 0)
					cc = make_pair(i, j);

		printf("Case #%d:\n", test);
		if(!ok || cc.first == -1)
		{
			puts("Impossible");
		}
		else
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < m; j++)
				{
					if(bomb[i][j])
						putchar('*');
					else if(cc.first == i && cc.second == j)
						putchar('c');
					else
						putchar('.');
				}
				puts("");
			}
		}
	}

	return 0;
}
