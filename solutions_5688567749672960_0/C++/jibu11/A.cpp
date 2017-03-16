#include <stdio.h>
#include <string.h>

int c, n, dp[1000010];

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int inv(int a)
{
	int t1 = a;
	if(a % 10 == 0)
		return -1;
	int b = 0;
	while(a)
	{
		b *= 10;
		b += a % 10;
		a /= 10;
	}
	if(t1 <= b)
		return -1;
	return b;
}

int calc(int cur)
{
	//printf("%d\n", cur);
	if(cur == -1 || cur > n)
		return 1000000000;
	if(dp[cur])
		return dp[cur];
	dp[cur] = calc(inv(cur));
	int t5 = calc(cur - 1);
	if(t5 < dp[cur])
		dp[cur] = t5;
	dp[cur]++;
	return dp[cur];
}

int main()
{
	scanf("%d", &c);
	int k;
	memset(dp, 0, sizeof dp);
	for(k = 1; k <= 10; k++)
		dp[k] = k;
	for(k = 1; k <= c; k++)
	{
		scanf("%d", &n);
		int sol = calc(n);
		printf("Case #%d: %d\n", k, sol);
	}
	return 0;
}
