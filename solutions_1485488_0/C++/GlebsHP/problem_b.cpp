#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 200;
const int inf = 1000 * 1000 * 1000;
const int px[] = {1, 0, -1, 0};
const int py[] = {0, 1, 0, -1};

int c[size][size], f[size][size];
int n, m, h;
bool used[size][size];
int ans[size][size];

inline bool onfield(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}


void dfs(int x, int y)
{
	if (used[x][y])
		return;
	used[x][y] = true;
	for (int i = 0; i < 4; i++)
		if (onfield(x + px[i], y + py[i]))
		if (max(max(f[x][y], f[x + px[i]][y + py[i]]), h) <= min(c[x][y], c[x + px[i]][y + py[i]]) - 50)
			dfs(x + px[i], y + py[i]);
}

inline int timetomove(int x, int y, int t)
{
	if (h - t - f[x][y] >= 20)
		return 10;
	else
		return 100;
}

inline bool willstart(int xs, int ys, int xf, int yf, int &tm)
{
	if (max(f[xs][ys], f[xf][yf]) > min(c[xs][ys], c[xf][yf]) - 50)
		return false;
	if (max(max(f[xs][ys], f[xf][yf]), h - tm) > min(c[xs][ys], c[xf][yf]) - 50)
		tm += max(max(f[xs][ys], f[xf][yf]), h - tm) - (min(c[xs][ys], c[xf][yf]) - 50);
	return true;
}

int process()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			used[i][j] = false;
	dfs(0, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (used[i][j])
				ans[i][j] = 0;
			else
				ans[i][j] = inf;
			used[i][j] = false;
		}
	while (true)
	{
		int x = 0, y = 0;
		bool flag = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!used[i][j] && (!flag || ans[i][j] < ans[x][y]))
				{
					flag = true;
					x = i;
					y = j;
				}
		if (!flag)
			break;
		used[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			int tm = ans[x][y];
			if (onfield(x + px[i], y + py[i]) && willstart(x, y, x + px[i], y + py[i], tm))
			{
				ans[x + px[i]][y + py[i]] = min(ans[x + px[i]][y + py[i]], tm + timetomove(x, y, tm));
			}
		}
	}
	return ans[n - 1][m - 1];
}

int main() {
	int tc;
	
	freopen("problem_b.in", "r", stdin);
	freopen("problem_b.out", "w", stdout);
	
	cin >> tc;
	cout.precision(20);
	for (int t = 0; t < tc; t++)
	{
		cin >> h >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> c[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> f[i][j];
		cout << "Case #" << t + 1 << ": " << process() / 10.0 << endl;
	}

	return 0;
}