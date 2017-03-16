#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[50][50];
int v[50];

int e, r, n;

int f(int i, int k)
{
	if (i == n)
		return 0;
	if (dp[i][k] != -1)
		return dp[i][k];
		
	int res = 0;
	for (int g = 0; g <= k; ++g)
	{
		res = max(res, f(i + 1, min(e, k - g + r)) + g * v[i]);
	}
	dp[i][k] = res;
	return res;
}

int main()
{
	int t;
	scanf("%d", &t);
	
	for (int i = 0; i < t; ++i)
	{
		scanf("%d %d %d", &e, &r, &n);
		
		memset(dp, -1, sizeof(dp));
		
		for (int j = 0; j < n; ++j)
			scanf("%d", &v[j]);
			
		printf("Case #%d: %d\n", i + 1, f(0, e));
	}
	
	return 0;
}
