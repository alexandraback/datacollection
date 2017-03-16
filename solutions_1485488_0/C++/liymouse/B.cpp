#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

typedef struct 
{
	int x , y;
}node;

int main()
{
	freopen("B-small-attempt0.in" , "r" , stdin);
	//freopen("input.txt" , "r" , stdin);
	freopen("B-small-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	int p[4][2] = {{-1 , 0} , {0 , 1} , {1 , 0} , {0 , -1}};
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
		int t , m , n;
		int ce[101][101];
		int fl[101][101];
		scanf("%d %d %d" , &t , &m , &n);
		for (int i = 0; i < m; i ++) for (int j = 0; j < n; j ++) scanf("%d" , &ce[i][j]);
		for (int i = 0; i < m; i ++) for (int j = 0; j < n; j ++) scanf("%d" , &fl[i][j]);
		double f[101][101];
		for (int i = 0; i < m; i ++) for (int j = 0; j < n; j ++) f[i][j] = -1;
		f[0][0] = 0;
		queue<node> q;
		node a;
		a.x = 0; a.y = 0;
		q.push(a);
		while (!q.empty())
		{
			node k = q.front();
			q.pop();
			for (int i = 0; i < 4; i ++)
			{
				int x = k.x + p[i][0];
				int y = k.y + p[i][1];
				if (x < 0 || x >= m || y < 0 || y >= n) continue;
				if (ce[x][y] - fl[x][y] < 50 || ce[x][y] - fl[k.x][k.y] < 50 || ce[k.x][k.y] - fl[x][y] < 50) continue;
				double water = t - f[k.x][k.y] * 10;
				double nextL = max(water , (double)fl[x][y]);
				int ti = 0;
				if (ce[x][y] - nextL < 50)
				{
					ti = -2;
				}
				else
				{
					ti = 0;
				}
				if (f[x][y] == -1 && ti == 0)
				{
					f[x][y] = ti;
					node nn;
					nn.x = x; nn.y = y;
					q.push(nn);
				}
			}
		}
		for (int i = 0; i < m; i ++)
			for (int j = 0; j < n; j ++)
				if (f[i][j] == 0)
				{
					node a;
					a.x = i; a.y = j;
					q.push(a);
				}
		while (!q.empty())
		{
			node k = q.front();
			q.pop();
			for (int i = 0; i < 4; i ++)
			{
				int x = k.x + p[i][0];
				int y = k.y + p[i][1];
				if (x < 0 || x >= m || y < 0 || y >= n) continue;
				if (ce[x][y] - fl[x][y] < 50 || ce[x][y] - fl[k.x][k.y] < 50 || ce[k.x][k.y] - fl[x][y] < 50) continue;
				double water = t - f[k.x][k.y] * 10;
				double nextL = max(water , (double)fl[x][y]);
				double ti = f[k.x][k.y];
				if (ce[x][y] - nextL < 50)
				{
					double wait = (50 - ce[x][y] + nextL) / 10.0;
					ti += wait;
					if (water - wait * 10 - fl[k.x][k.y] < 20) ti += 10;
					else ti += 1;
				}
				else
				{
					if (water - fl[k.x][k.y] < 20) ti += 10;
					else ti += 1;
				}
				if (f[x][y] == -1 || ti < f[x][y])
				{
					f[x][y] = ti;
					node nn;
					nn.x = x; nn.y = y;
					q.push(nn);
				}
			}
		}
		printf("%lf\n" , f[m-1][n-1]);
	}
	return 0;
}