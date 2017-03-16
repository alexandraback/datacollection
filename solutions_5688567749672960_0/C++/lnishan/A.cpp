#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long LLU;

const int N = 1000002;

LLU dp[N];

int rev(int n)
{
	int i, d[10], dc = 0, ret = 0;
	while (n)
	{
		d[dc++] = n % 10;
		n /= 10;
	}
	for (i = 0; i < dc; i++)
		ret = ret * 10 + d[i];
	return ret;
}

int main()
{
	int i, t, n, r;
	dp[1] = 1;
	for (i = 2; i < N; i++)
	{
		dp[i] = dp[i-1] + 1;
		if (i % 10)
		{
			r = rev(i);
			if (r < i) dp[i] = min(dp[i], dp[r]+1);
		}
	}
	scanf("%d", &t);
	for (int c = 1; c <= t; c++)
	{
		scanf("%d", &n);
		printf("Case #%d: %llu\n", c, dp[n]);
	}
	return 0;
}
