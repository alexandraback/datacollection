#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<queue>
#define eps 1e-8
#define MOD 1000000007
#define LL __int64
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1010
using namespace std;

char str[110];
int dp[1<<10], vis[1<<10];

void bfs(int sta, int len)
{
	int all = 1<<len;
	for(int i = 0; i < all; i ++)
	{
		vis[i] = 0;
		dp[i] = 99999999;
	}
	dp[sta] = 0;
	queue<int> q;
	q.push(sta);
	vis[sta] = 1;
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		vis[temp] = 0;
		for(int i = 0; i < len; i ++)
		{
			int re = 0;
			int ans = temp;
			for(int j = 0; j <= i; j ++)
			{
				if(temp&(1<<j))
				{
					ans -= (1<<j);
				}
				else
				{
					re += (1<<(i - j));
				}
			}
			ans += re;
			if(dp[ans] > dp[temp] + 1)
			{
				dp[ans] = dp[temp] + 1;
				if(!vis[ans])
				{
					q.push(ans);
					vis[ans] = 1;
				}
			}
		}
	}
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ii = 1; ii <= t; ii ++)
	{
		scanf("%s",str);
		int len;
		int sta = 0;
		for(len = 0; str[len]; len ++)
		{
			if(str[len] == '+')
			{
				sta += (1<<len);
			}
		}
		bfs(sta, len);
		int all = 1<<len;
		printf("Case #%d: %d\n",ii, dp[all - 1]);
	}
	return 0;
}