#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>


using namespace std;


int cnt[146];
bool counted[1 << 21], dp[1 << 21];
vector<int> v[146];
int t[146];
vector<int> ans;
int n;


bool possible(int mask)
{
	if(counted[mask])
		return false;
	counted[mask] = true;
	if(mask == (1 << n) - 1)
		return true;
	for(int i = 0; i < n; i++)
		if((mask & (1 << i)) == 0)
		{
			if(cnt[t[i]] > 0)
			{
				cnt[t[i]]--;
				for(int j = 0; j < v[i].size(); j++)
					cnt[v[i][j]]++;
				if(possible(mask | (1 << i)))
				{
					ans.push_back(i);
					return true;
				}
				cnt[t[i]]++;
				for(int j = 0; j < v[i].size(); j++)
					cnt[v[i][j]]--;
			}
		}
	return false;
}


void solve(int tt)
{
	memset(counted, false, sizeof(counted));
	memset(dp, false, sizeof(dp));
	memset(cnt, 0, sizeof(cnt));
	int k;
	scanf("%d%d", &k, &n);
	for(int i = 0; i < k; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
		int c;
		scanf("%d", &c);
		v[i].clear();
		for(int j = 0; j < c; j++)
		{
			int x;
			scanf("%d", &x);
			v[i].push_back(x);
		}
	}
	ans.clear();
	if(possible(0))
	{
		printf("Case #%d: ", tt);
		reverse(ans.begin(), ans.end());
		for(int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i] + 1);
		printf("\n");
	}
	else
		printf("Case #%d: IMPOSSIBLE\n", tt);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		solve(i + 1);
}