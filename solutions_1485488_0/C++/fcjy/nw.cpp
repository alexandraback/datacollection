#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>

#define PI pair<int, int>
#define MP make_pair

const double eps = 1e-10;
const int INF = (1<<30);

using namespace std;

int height[128][128][2];
bool vis[128][128];

int xx[4] = {-1, 0, 1, 0};
int yy[4] = {0, 1, 0, -1};

struct point
{
	int x, y;
	double time;

	bool operator<( const point& p ) const
	{
		return time > p.time;
	}
};

int dblcmp( double x )
{
	if( fabs(x) < eps )
		return 0;
	return x > 0 ? 1 : -1;
}

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);

	int T, cases = 1;
	int n, m, i, j, k, x, y;
	double h1, h2, h, t;
	point tmp, p;

	priority_queue<point> Q;
	cin >> T;
	while( T-- )
	{
		while( !Q.empty() )
			Q.pop();

		cin >> h >> n >> m;
		for( i = 0; i < n; ++i )
			for( j = 0; j < m; ++j )
				cin >> height[i][j][1];
		for( i = 0; i < n; ++i )
			for( j = 0; j < m; ++j )
				cin >> height[i][j][0];

		memset(vis, 0, sizeof(vis));




		tmp.x = 0, tmp.y = 0, tmp.time = 0;
		Q.push(tmp);
		while( !Q.empty() )
		{
			p = Q.top();	Q.pop();
			if( vis[p.x][p.y] == 0 )
				vis[p.x][p.y] = 1;
			else
				continue;

			for( i = 0; i < 4; ++i )
			{
				x = p.x + xx[i];
				y = p.y + yy[i];

				if( x < 0 || y < 0 )
					continue;
				if( x >= n || y >= m )
					continue;

				if( vis[x][y] )
					continue;

				if( height[x][y][1] - height[x][y][0] < 50 )
					continue;
				else if( height[p.x][p.y][1] - height[x][y][0] < 50 )
					continue;
				else if( height[x][y][1] - height[p.x][p.y][0] < 50 )
					continue;
				else
				{
					if( dblcmp(h - height[p.x][p.y][0]) <= 0 )
					{
						tmp.x = x;	tmp.y = y;
						Q.push(tmp);
					}
					else if( dblcmp(height[x][y][1] - h - 50) >= 0 )
					{
						tmp.x = x;	tmp.y = y;
						Q.push(tmp);
					}
				}
			}
		}


		for( i = 0; i < n; ++i )
			for( j = 0; j < m; ++j )	if( vis[i][j] )
			{
				tmp.x = i;	tmp.y = j;	tmp.time = 0;
				Q.push(tmp);
			}

		memset(vis, 0, sizeof(vis));

		while( !Q.empty() )
		{
			p = Q.top();	Q.pop();
			if( p.x == n-1 && p.y == m-1 )
				break;
			if( vis[p.x][p.y] == 0 )
				vis[p.x][p.y] = 1;
			else
				continue;

			for( i = 0; i < 4; ++i )
			{
				x = p.x + xx[i];
				y = p.y + yy[i];

				if( x < 0 || y < 0 )
					continue;
				if( x >= n || y >= m )
					continue;

				if( vis[x][y] )
					continue;

				if( height[x][y][1] - height[x][y][0] < 50 )
					continue;
				else if( height[p.x][p.y][1] - height[x][y][0] < 50 )
					continue;
				else if( height[x][y][1] - height[p.x][p.y][0] < 50 )
					continue;
				else
				{
					h1 = h-p.time*10.;

					if( dblcmp(h1 - height[p.x][p.y][0]) <= 0 )
					{
						tmp.x = x;	tmp.y = y;
						tmp.time = p.time + 10;
						Q.push(tmp);
					}
					else if( dblcmp(height[x][y][1] - h1 - 50) >= 0 )
					{
						if( dblcmp(h1 - height[p.x][p.y][0] - 20) >= 0 )
						{
							tmp.x = x;	tmp.y = y;
							tmp.time = p.time + 1;
							Q.push(tmp);
						}
						else
						{
							tmp.x = x;	tmp.y = y;
							tmp.time = p.time + 10;
							Q.push(tmp);
						}
					}
					else
					{
						t = 50. - (height[x][y][1] - h1);
						h1 -= t;
						t /= 10.;
						if( dblcmp(h1 - height[p.x][p.y][0] - 20) >= 0 )
						{
							tmp.x = x;	tmp.y = y;
							tmp.time = p.time + t + 1;
							Q.push(tmp);
						}
						else
						{
							tmp.x = x;	tmp.y = y;
							tmp.time = p.time + t + 10;
							Q.push(tmp);
						}
					}
				}
			}
		}

		printf("Case #%d: %.10lf\n", cases++, p.time);
	}

	return 0;
}