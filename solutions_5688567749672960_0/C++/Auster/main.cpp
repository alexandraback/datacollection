#pragma comment(linker, "/STACK:134217728")

#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <complex>
#include <memory.h>
#include <time.h>

using namespace std;

typedef long long LL;

int t, n;

int dp[1 << 20];
int r[1 << 20];

int go(int x)
{
	if (x >= (1 << 20))
		return (int)1e9;
	if (x == n)
		return 1;
	int & res = dp[x];
	if (res != -1)
		return res;
	res = (int)1e9;
	if (r[x] > x)
		res = min(res, go(r[x]) + 1);
	res = min(res, go(x + 1) + 1);
	return res;
}

int main()
{
	freopen("A-small-attempt0 (5).in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);

	for(int i = 0; i < 1 << 20; ++i)
	{
		int x = i;
		int y = 0;
		while (x)
		{
			y = y * 10 + x % 10;
			x /= 10;
		}
		r[i] = y;
	}

	for(int it = 1; it <= t; ++it)
	{
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		printf("Case #%d: %d\n", it, go(1));
	}
	return 0;
}