#include <stdio.h>
#include <string.h>

int dp[20][20];
int n, c, r;

int calc(int c, int n)
{
	if(dp[c][n])
		return dp[c][n];
	if(c >= n * 2)
		return dp[c][n] = calc(c - n, n) + 1;
	if(c <= n + 1)
		return dp[c][n] = c;
	return dp[c][n] = calc(c - 1, n);
}

int main()
{
	int k, l;
	scanf("%d", &k);
	memset(dp, 0, sizeof dp);
	for(l = 1; l <= k; l++)
	{
		scanf("%d%d%d", &r, &c, &n);
		printf("Case #%d: %d\n", l, calc(c, n));
	}
	return 0;
}
