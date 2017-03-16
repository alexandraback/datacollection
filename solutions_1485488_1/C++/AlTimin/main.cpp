#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>

#define all(x) (x).begin(),(x).end()

using namespace std;

const int nmax = 1e3;

int u[nmax][nmax];
int d[nmax][nmax];
double t[nmax][nmax];
bool ok[nmax][nmax];
bool used[nmax][nmax];
int n,m;
int water_level;

bool valid(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

const double eps = 1e-8;
const double inf = 1e18;

bool _eq(double a, double b)
{
	return abs(a - b) < eps;
}

double min_move_time(int x, int y, int dx, int dy)
{
	if (!valid(x + dx, y + dy)) return inf;
	int nx = x + dx;
	int ny = y + dy;
	if (u[nx][ny] - d[nx][ny] < 50) return inf;
	if (u[nx][ny] - d[x][y] < 50) return inf;
	if (u[x][y] - d[nx][ny] < 50) return inf;
	return max(water_level - (u[nx][ny] - 50), 0) / double(10);
}

const int k = 4;
int dx[] = { -1, 1, 0 , 0};
int dy[] = {0, 0, -1, 1 };

void dfs(int x, int y)
{
	used[x][y] = 1;
	for (int i = 0; i < k; i ++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!used[nx][ny] && _eq(min_move_time(x, y, dx[i], dy[i]), 0))
			dfs(nx, ny);
	}
}

void solve(int cn)
{
	cin >> water_level >> n >> m;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
		{
			used[i][j] = 0;
			ok[i][j] = 0;
			t[i][j] = inf;
			cin >> u[i][j];
		}
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			cin >> d[i][j];
	dfs(0,0);

	typedef pair<double, pair<int,int> > T;
	priority_queue< T, vector <T>, greater<T> > q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j ++)
			if (used[i][j])
			{
				t[i][j] = 0;
				q.push(make_pair(double(0), make_pair(i,j)));
			}
	while (!q.empty())
	{
		T obj = q.top(); q.pop();
		if (ok[obj.second.first][obj.second.second]) continue;
		ok[obj.second.first][obj.second.second] = 1;
		int x = obj.second.first;
		int y = obj.second.second;
		for (int i = 0; i < k; i ++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];	
			if (valid(nx, ny))
			{
				double trtime = max(t[x][y], min_move_time(x, y, dx[i], dy[i]));
				double mtime;
				int wlevel = round(water_level - trtime * 10);
				if (wlevel >= d[x][y] + 20)
					mtime = 1;
				else
					mtime = 10;
				t[nx][ny] = min(t[nx][ny], trtime + mtime);
				q.push(make_pair(t[nx][ny], make_pair(nx, ny)));
			}
		}
	}
	printf("Case #%d: %.10lf\n", cn, t[n-1][m-1]);
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i ++)
		solve(i + 1);
	return 0;
};
