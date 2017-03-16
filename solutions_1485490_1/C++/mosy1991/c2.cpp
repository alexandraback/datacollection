#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL; 

int	n,m; 
LL data[2][105][2];
LL dp[105][105];

void check(LL &x , LL y) 
{
	if ( x < y ) x = y; 
}

void solve(int i, int j, LL k, int kind, LL now) 
{
	if (kind == 0) 
	{
		for (int t = i; t < n; ++t) 
		{
			if (data[0][t][1] == data[1][j][1]) 
			{
				if (k > data[0][t][0]) 
				{
					now += data[0][t][0];
					k -= data[0][t][0];
					check(dp[t + 1][j + 1], now); 
				}
				else if (k < data[0][t][0]) 
				{	
					check(dp[t + 1][j + 1] , now + k); 
					solve(t, j + 1, data[0][t][0] - k, 1, now + k); 
					break; 
				}
				else
				{
					check(dp[t + 1][j + 1] , now + k); 
					break; 
				}
			}
			else 
				check(dp[t + 1][j + 1], now); 
		}
	}
	else
	{
		for (int t = j; t < m; ++t) 
		{
			if (data[1][t][1] == data[0][i][1]) 
			{
				if (k > data[1][t][0]) 
				{
					now += data[1][t][0];
					k -= data[1][t][0]; 
					check(dp[i + 1][t + 1], now); 
				}
				else if (k < data[1][t][0]) 
				{	
					check(dp[i + 1][t + 1], now + k); 
					solve(i + 1, t, data[1][t][0] - k, 0, now + k); 
					break; 
				}
				else
				{
					check(dp[i + 1][t + 1], now + k); 
					break; 
				}
			}
			else 
				check(dp[i + 1][t + 1], now); 
		}
	}
}
int	main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int	T, cases = 0; 
	scanf("%d", &T);
	while (T--) 
	{
		scanf("%d%d", &n ,&m);
		for (int i = 0; i < n; ++i) 
			scanf("%lld%lld", &data[0][i][0], &data[0][i][1]);
		for (int i = 0; i < m; ++i)
			scanf("%lld%lld", &data[1][i][0], &data[1][i][1]);
		memset(dp , 0 , sizeof(dp));
		for (int i = 0; i <= n; ++i) 
			for (int j = 0; j <= m; ++j) 
			{
				check(dp[i + 1][j], dp[i][j]); 
				check(dp[i][j + 1], dp[i][j]); 
				if (i == n || j == m) continue; 
				solve(i, j, data[1][j][0], 0, dp[i][j]); 
				solve(i, j, data[0][i][0], 1, dp[i][j]); 
			}
		printf("Case #%d: ", ++cases);
		printf("%lld\n" , dp[n][m] ); 
	}
}
