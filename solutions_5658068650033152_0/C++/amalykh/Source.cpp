#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <assert.h>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
#define mp make_pair

bool a[24][24];

int was[24][24];

int n, m, k;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

bool exists(pair<int, int> v)
{
	if (v.first >= n || v.first < 0 || v.second >= m || v.second < 0)
		return 0;
	return 1;
}

bool edged(pair<int, int> v)
{
	if (n - v.first == 1 || m - v.second == 1 || v.first == 0 || v.second == 0)
		return 1;
	return 0;
}

int step = 0;

int dfs(pair<int, int> v)
{
	int res = 1;
	was[v.first][v.second] = step;
	if (edged(v) && !a[v.first][v.second])
		return -1e5;
	for (int i = 0; i < 4; i++)
	{
		pair<int, int> next = mp(v.first + dx[i], v.second + dy[i]);
		if (!exists(next))
			continue;
		if (was[next.first][next.second] == step)
			continue;
		if (a[v.first][v.second] && !a[next.first][next.second])
			continue;
		res += dfs(next);
	}
	return res;
}

int ok()
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		was[i][j] = 0;
	int res = 0;
	step = 1;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		//if (was[i][j] && !a[i][j])
			res = max(res, dfs(mp(i, j)));
		step++;
		if (res >= k)
			return 1;
	}
	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int q = 0; q < tests; q++)
	{
		printf("Case #%d: ", q + 1);
		scanf("%d %d %d", &n, &m, &k);
		int ans = 1e5;

		for (int mask = 0; mask < 1 << (n * m + 1); mask++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
					a[i][j] = (mask >> (i * m + j)) & 1;
			}
			int ones = 0;
			for (int i = 0; i < n * m; i++)
			if ((mask >> i) & 1)
				ones++;
			if (ok())
			{
				ans = min(ones, ans);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}