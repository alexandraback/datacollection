#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 1001
#define INF 1e9

int dx[4] = {-1, 0, 0, 1};
int dy[4] = { 0,-1, 1, 0};

int h, n, m;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
double c[MAXN][MAXN];
double d[MAXN][MAXN];
bool was[MAXN][MAXN];

inline double solve()
{
	scanf("%d%d%d", &h, &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			was[i][j] = 0;
			c[i][j] = 0;
			d[i][j] = INF;
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &b[i][j]);

	queue <int> q;
	q.push(0);
	c[0][0] = h;
	d[0][0] = 0;
	was[0][0] = 1;

	while(!q.empty())
	{
		int x = q.front() / m, y = q.front() % m;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int sx = x + dx[i], sy = y + dy[i];
			if (sx >= 0 && sx < n && sy >= 0 && sy < m && !was[sx][sy] && a[sx][sy] - b[sx][sy] >= 50 && a[sx][sy] - b[x][y] >= 50 && a[x][y] - b[sx][sy] >= 50 && a[sx][sy] - c[x][y] >= 50)
			{
				q.push(sx * m + sy);
				was[sx][sy] = 1;
				d[sx][sy] = 0;
				c[sx][sy] = h;
			}
		}
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (was[i][j])
				q.push(i * m + j);

	while(!q.empty())
	{
		int x = q.front() / m, y = q.front() % m;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int sx = x + dx[i], sy = y + dy[i];
			if (sx >= 0 && sx < n && sy >= 0 && sy < m && a[sx][sy] - b[sx][sy] >= 50 && a[sx][sy] - b[x][y] >= 50 && a[x][y] - b[sx][sy] >= 50)
			{
				if (a[sx][sy] - c[x][y] >= 50)
				{
					if (d[x][y] + ((c[x][y] - b[x][y]) >= 20 ? 1 : 10) >= d[sx][sy]) continue;

					q.push(sx * m + sy);
					was[sx][sy] = 1;
					d[sx][sy] = d[x][y] + ((c[x][y] - b[x][y]) >= 20 ? 1 : 10);
					c[sx][sy] = max(0.0, c[x][y] - 10 * ((c[x][y] - b[x][y]) >= 20 ? 1 : 10));
				}
				else
				{
					double nh = a[sx][sy] - 50;
					double et = (c[x][y] - nh) / 10.0;

					if (d[x][y] + ((nh - b[x][y]) >= 20 ? 1 : 10) + et >= d[sx][sy]) continue;

					q.push(sx * m + sy);
					was[sx][sy] = 1;
					d[sx][sy] = d[x][y] + ((nh - b[x][y]) >= 20 ? 1 : 10) + et;
					c[sx][sy] = max(0.0, nh - 10 * ((nh - b[x][y]) >= 20 ? 1 : 10));
				}
			}
		}
	}
	return d[n - 1][m - 1];
}

int main()
{
	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
		printf("Case #%d: %.10lf\n", t + 1, solve());
	return 0;
}
