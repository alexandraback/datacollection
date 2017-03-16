#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

#define LONG long long
#define MAXN 100
#define MAXM 100

LONG tc, tt, vis[MAXN+5][MAXM+5], memo[MAXN+5][MAXM+5], i, n, m, ba[MAXN+5], bb[MAXN+5], ta[MAXM+5], tb[MAXM+5], tans;

void dp(LONG pp, LONG qq, LONG ans)
{
	LONG ret,t;
	if (pp == n || qq == m) 
	{tans = max(tans,ans); return; }
	
	//if (vis[pp][qq]) return memo[pp][qq];
	
	if (bb[pp] != tb[qq]) 
	{
		dp(pp+1,qq,ans); dp(pp,qq+1,ans);
	}
	if (bb[pp] == tb[qq]) 
	{
		t = min(ba[pp], ta[qq]);
		ba[pp] -= t;
		ta[qq] -= t;
		dp(pp+1,qq,ans+t);
		dp(pp,qq+1,ans+t);
		ba[pp] += t;
		ta[qq] += t;
	}
	
	//memo[pp][qq] = ret; vis[pp][qq] = 1;
	return;
}

int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%lld", &tc);
	for (tt = 1; tt <= tc; tt++)
	{
		tans = 0;
		memset(memo,0,sizeof(memo));
		memset(vis,0,sizeof(vis));
		
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++)
			scanf("%lld %lld", &ba[i], &bb[i]);
			
		for (i = 0; i < m; i++)
			scanf("%lld %lld", &ta[i], &tb[i]);
		
		dp(0,0,0);
		printf("Case #%lld: %lld\n", tt, tans);
	}
}