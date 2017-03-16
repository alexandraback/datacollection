#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX (int) 1e6+10

int v[MAX], n, dp[110][MAX];

int solve(int i, long long int m)
{
	int change;
	
	if(i == n)
		return 0;
	if(dp[i][m] != -1)
		return dp[i][m];
	
	if(v[i] >= m)
	{
		if(m-1 > 0)
			change = 1 + min(solve(i+1, m), solve(i, m+m-1));
		else
			change = 1 + solve(i+1, m);
	}
	else
		change = solve(i+1, m+v[i]);
	
	return dp[i][m] = change;
}

int main()
{
	int t;
	long long int m;
	
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		scanf("%lld %d", &m, &n);
		for(int i=0; i<n; ++i)
			scanf("%d", &v[i]);
		sort(v, v+n);
		for(int i=0; i<=n; ++i)
			memset(dp[i], -1, sizeof(dp[i]));
		
		printf("Case #%d: %d\n", tc, solve(0, m));
	}
	
	return 0;
}