#pragma comment(linker, "/STACK:134217728")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <complex>
#include <functional>
#include <cmath>
#include <time.h>

using namespace std;

typedef long long LL;

const string problem = "C-small-attempt0";

int F[1 << 10];
int used[1 << 10];
vector<int> G[1 << 10];

int dfs(int x)
{
	used[x] = 1;
	int res = 1;
	for (int i = 0; i < G[x].size(); ++i)
	{
		int to = G[x][i];
		if (!used[to])
			res = max(1 + dfs(to), res);
	}
	return res;
}


int go(int x, int y)
{
	memset(used, 0, sizeof(used));
	used[y] = 1;
	int res = dfs(x);
	memset(used, 0, sizeof(used));
	used[x] = 1;
	res += dfs(y);
	return res;
}

int d[1 << 10];

int cycle(int x)
{
	memset(d, 0, sizeof(d));
	d[x] = 1;
	while (!d[F[x]])
	{
		d[F[x]] = d[x] + 1;
		x = F[x];
	}
	return d[x] - d[F[x]] + 1;
}

int main()
{
#ifndef _DEBUG
	freopen((problem + ".in").c_str(), "r", stdin);
	freopen((problem + ".out").c_str(), "w", stdout);
#endif
	int T;
	cin >> T;

	int n;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			G[i].clear();
		for (int i = 0; i < n; ++i)
		{
			cin >> F[i];
			F[i]--;
			G[F[i]].push_back(i);
		}
		
		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (F[i] == j && F[j] == i)
					res += go(i, j);

		for (int i = 0; i < n; ++i)
			res = max(res, cycle(i));

		cout << "Case #" << test_case << ": " << res << endl;
	}

	

	return 0;
}
