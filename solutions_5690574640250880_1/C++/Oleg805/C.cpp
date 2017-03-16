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

char a[55][55];

void draw_rect(int n, int m, int n1, int m1)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = '.';
	for (int j = 0; j < m1; ++j)
		a[n][j] = '.';
	for (int i = 0; i < n1; ++i)
		a[i][m] = '.';
	a[0][0] = 'c';
}

void solve(int T)
{
	printf("Case #%d:\n", T);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	k = n*m - k;
	memset(a, '*', sizeof(a));
	bool f = false;
	if (k == 0)
		f = true;
	for (int i = 1; i <= n && !f; ++i)
	{
		for (int j = 1; j <= m && !f; ++j)
		{
			if (i*j > k || (i == 1 && j > 1 && n > 1) || (i > 1 && j == 1 && m > 1))
				continue;
//			printf("%d %d\n", i, j);
			int rem = k - i*j;
			if (i + j <= rem)
				continue;
			if (rem == 0)
			{
				draw_rect(i, j, 0, 0);
				f = true;
			}
			for (int u = 0; u <= rem && !f; ++u)
			{
				if (u != 1 && rem - u != 1 && u < i && rem  - u < j && (u == 0 || j < m) && (rem - u == 0 || i < n))
				{
					draw_rect(i, j, u, rem - u);
					f = true;
				}
			}
		}
	}
	if (!f)
	{
		printf("Impossible\n");
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				printf("%c", a[i][j]);
			printf("\n");
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
		solve(i + 1);
	return 0;
}