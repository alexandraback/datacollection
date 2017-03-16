#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;

int const size = 1000 + 5;

bool edge[size][size];
int used[size];

int n;

bool dfs (int v, int d)
{
	int i;
	if (used[v] == d)
		return true;
	used[v] = d;
	for (i = 0; i < n; i++)
		if (edge[v][i])
			if ( dfs(i, d))
				return true;
	return false;
}

int main ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t, it, i, j, m;
	int a, b;

	scanf("%d", &t);
	for (it = 1; it <= t; it++)
	{
		printf("Case #%d: ", it);
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				edge[i][j] = false;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &m);
			for (j = 0; j < m; j++)
			{
				scanf("%d", &a);
				edge[i][a - 1] = true;
			}
			used[i] = -1;
		}
		bool ok = true;
		for (i = 0; i < n; i++)
		{
			bool flag = true;
			for (j = 0; j < n; j++)
				if (edge[j][i])
				{
					flag = false;
					break;
				}
			if (flag)
				if (dfs(i, i))
				{
					ok = false;
					break;
				}
		}
		if (!ok)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}