#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[12][6], val[11];

int main()
{
	freopen("d://test/b-small.in", "r", stdin);
	freopen("d://test/b-small.out", "w", stdout);
	int t, cnt = 0;
	int e, r, n;
	int ans;
	
	cin >> t;
	while(t--)
	{
		cin >> e >> r >> n;
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++)
			cin >> val[i];
		for(int i = 1; i <= n; i++)
			for(int j = 0; j <= e; j++)
				for(int k = 0; k <= j; k++)
					dp[i+1][min(e, j-k+r)] = max(dp[i+1][min(e, j-k+r)], dp[i][j]+k*val[i]);
		ans = 0;
		for(int i = 0; i <= e; i++)
			ans = max(ans, dp[n+1][i]);
		printf("Case #%d: %d\n", ++cnt, ans);
	}
	return 0;
}