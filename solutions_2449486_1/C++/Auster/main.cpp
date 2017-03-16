#pragma comment(linker, "/STACK:33554432")

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <memory.h>
#include <iostream>
#include <sstream>
#include <complex>
#include <queue>
#include <stack>

using namespace std;

typedef vector<int> vint;
typedef vector<vint> vvint;
typedef long long LL;

int t;

int n, m;
int a[1 << 7][1 << 7];
int b[1 << 7][1 << 7];
int c[1 << 7][1 << 7];

int ok()
{
	for(int h = 100; h >= 1; --h)
	{
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				b[i][j] = a[i][j] <= h;
		memset(c, 0, sizeof(c));
		for(int i = 0; i < n; ++i)
		{
			int full = 1;
			for(int j = 0; j < m; ++j)
				full &= b[i][j];
			if (full)
				for(int j = 0; j < m; ++j)
					c[i][j] = 1;
		}
		for(int i = 0; i < m; ++i)
		{
			int full = 1;
			for(int j = 0; j < n; ++j)
				full &= b[j][i];
			if (full)
				for(int j = 0; j < n; ++j)
					c[j][i] = 1;
		}
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if (b[i][j] && !c[i][j])
					return 0;
	}
	return 1;
}

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				scanf("%d", &a[i][j]);
		printf("Case #%d: ", i + 1);
		if (ok())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}