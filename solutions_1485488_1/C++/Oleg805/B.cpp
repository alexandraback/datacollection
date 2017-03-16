#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;

#pragma comment(linker,"/STACK:100000000")

const int inf = 1e9;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int c[205][205], f[205][205];
int d[205][205];
set <pair <int, int> > S;
int h;
int n, m;

void dfs(int i, int j)
{
	d[i][j] = 0;
	for (int u = 0; u < 4; ++u)
	{
		int ni = i + di[u];
		int nj = j + dj[u];
		if (ni >= 0 && ni < n && nj >= 0 && nj < m && 
			h + 50 <= c[ni][nj] && f[i][j] + 50 <= c[ni][nj] && 
			f[ni][nj] + 50 <= c[ni][nj] && f[ni][nj] + 50 <= c[i][j] &&
			d[ni][nj] != 0)
		{
			dfs(ni, nj);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int tt, T;
	scanf("%d", &T);
	for (tt = 0; tt < T; ++tt)
	{
		int i, j, u;
		scanf("%d%d%d", &h, &n, &m);
		for (i = 0; i < n; ++i)
			for (j = 0; j < m; ++j)
				scanf("%d", &c[i][j]);
		for (i = 0; i < n; ++i)
			for (j = 0; j < m; ++j)
				scanf("%d", &f[i][j]);
		for (i = 0; i < n; ++i)
			for (j = 0; j < m; ++j)
				d[i][j] = inf;
		dfs(0, 0);
		int left = 0, right = 0;
		for (i = 0; i < n; ++i)
			for (j = 0; j < m; ++j)
				if (d[i][j] == 0)
				{
					S.insert(make_pair(0, i*m + j));
				}
		while (!S.empty())
		{
			int ver = S.begin() -> second;
			i = ver/m;
			j = ver%m;
			int hh = h - (S.begin() -> first);
			S.erase(S.begin());
			for (u = 0; u < 4; ++u)
			{
				int ni = i + di[u];
				int nj = j + dj[u];
				if (ni >= 0 && ni < n && nj >= 0 && nj < m && 
					f[i][j] + 50 <= c[ni][nj] && 
					f[ni][nj] + 50 <= c[ni][nj] && f[ni][nj] + 50 <= c[i][j])
				{
					int nd = d[i][j] + max(hh - c[ni][nj] + 50, 0);
					int nh = hh - max(hh - c[ni][nj] + 50, 0);
					if (nh - f[i][j] >= 20)
						nd += 10;
					else
						nd += 100;
					if (d[ni][nj] > nd)
					{
						S.erase(make_pair(d[ni][nj], ni*m + nj));
						d[ni][nj] = nd;
						S.insert(make_pair(d[ni][nj], ni*m + nj));
					}
				}
			}
		}
		printf("Case #%d: %d.%d\n", tt + 1, d[n - 1][m - 1]/10, d[n - 1][m - 1]%10);
		fflush(stdout);
	}
	return 0;
}