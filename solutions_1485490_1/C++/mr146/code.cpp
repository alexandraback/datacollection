#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>


using namespace std;


long long dp[146][146];
vector<int> va[146], vb[146];
pair<long long, int> a[146], b[146];


void solve(int test)
{
	printf("Case #%d: ", test + 1);
	memset(dp, 0, sizeof(dp));
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < 146; i++)
	{
		va[i].clear();
		vb[i].clear();
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%lld%d", &a[i].first, &a[i].second);
		va[a[i].second].push_back(i);
	}
	for(int i = 0; i < m; i++)
	{
		scanf("%lld%d", &b[i].first, &b[i].second);
		vb[b[i].second].push_back(i);
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			if(a[i].second != b[j].second)
			{
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
			}
			else
			{
				int fa = lower_bound(va[a[i].second].begin(), va[a[i].second].end(), i) - va[a[i].second].begin();
				int fb = lower_bound(vb[b[j].second].begin(), vb[b[j].second].end(), j) - vb[b[j].second].begin();
                long long suma = 0;
                for(int k = fa; k < va[a[i].second].size(); k++)
                {
                	suma += a[va[a[i].second][k]].first;
                	long long sumb = 0;
                	for(int l = fb; l < vb[b[j].second].size(); l++)
                	{
                		sumb += b[vb[b[j].second][l]].first;
                		dp[va[a[i].second][k] + 1][vb[b[j].second][l] + 1] = max(dp[va[a[i].second][k] + 1][vb[b[j].second][l] + 1], dp[i][j] + min(suma, sumb));
                	}
                }
			}
		}
	long long ans = 0;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			ans = max(ans, dp[i][j]);
	printf("%lld\n", ans);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		solve(i);
	}
}