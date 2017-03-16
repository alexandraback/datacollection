#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int T;
int n, x, y;
int h, rem;

double dp[1 << 11][1 << 11];

double go(int L, int R)
{
	if (L + R == rem)
	{
		if (x < 0)
			return y < L;
		return y < R;
	}
	double & res = dp[L][R];
	if (res != -1.0)
		return res;
	if (L == h + 1)
		res = go(L, R + 1);
	else if (R == h + 1)
		res = go(L + 1, R);
	else 
		res = 0.5 * (go(L + 1, R) + go(L, R + 1));
	return res;
}

double solve(int n)
{
	h = 1;
	while (h * (h + 1) / 2 <= n)
		h += 2;
	h -= 2;
	if (abs(x) + abs(y) <= h - 1)
		return 1;
	if (h + 1 < abs(x) + abs(y))
		return 0;
	rem = n - h * (h + 1) / 2;
	for(int i = 0; i < 1 << 11; ++i)
		for(int j = 0; j < 1 << 11; ++j)
			dp[i][j] = -1.0;
	return go(0, 0);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(int I = 1; I <= T; ++I)
	{
		scanf("%d%d%d", &n, &x, &y);
		printf("Case #%d: ", I);
		printf("%.7lf\n", solve(n));
	}
	return 0;
}
