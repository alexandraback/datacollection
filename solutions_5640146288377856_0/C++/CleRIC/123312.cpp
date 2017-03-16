#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <memory.h>

#include <time.h>
#pragma comment(linker, "/STACK:20000000")

#define fr(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define fd(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define mp make_pair
#define pb push_back
#define ll long long

using namespace std;

int ri(){int x;scanf("%d",&x);return x;}
ll rll(){ll x;scanf("%lld",&x);return x;}

int dp[21][1<<21];
int n,m,w;

int go(int pos,int MASK)
{
	if (dp[pos][MASK] != -1)
		return dp[pos][MASK];
	int res = 1e9;

	if (pos + 1 == n)
	{
		bool check = true;
		int cnt = 0;
		for(int j = 0;j < m - w + 1;j++)
		{
			bool wtf = true;
			for(int k = j;k < j + w;k++)
				if (!(MASK & (1<<k)))
					wtf = false;
			cnt += wtf;
		}
		if (cnt > 1)
		{
			for(int j = 0;j < m;j++)
				if (MASK & (1<<j))
					res = min(res,go(pos,MASK ^ (1<<j)) + 1);
		}
		else
		if (cnt == 1)
		{
			res = w;
			/*for(int j = 0;j < m;j++)
				if (MASK & (1<<j))
				{
					res = min(res,go(pos,MASK ^ (1<<j)) + 1);
				}*/

		}
		return dp[pos][MASK] = res;
	}
	
	bool wtf = true;
	for(int j = 0;j < m;j++)
		if (MASK & (1<<j))
		{
			bool ok = true;
			for(int k = j + 1;k < j + w;k++)
				if (!(MASK & (1<<k)))
					ok = false;
			if (ok)
			{
				wtf = false;
				res = min(res,go(pos,MASK ^ (1<<j)) + 1);
			}
		}
	if (wtf)
		res = go(pos + 1,(1<<m) - 1);
	return dp[pos][MASK] = res;
}

void solve()
{
	int test = ri();
	fr(testing,1,test)
	{
		n = ri(),m = ri(),w = ri();
		memset(dp,-1,sizeof(dp));
		int res = go(0,(1<<m) - 1);
		printf("Case #%d: %d\n",testing,res);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("C:/Users/CleRIC/Desktop/Универ/acm.timus.ru/input.txt","rt",stdin);
		freopen("C:/Users/CleRIC/Desktop/Универ/acm.timus.ru/output.txt","wt",stdout);
	#else
		//freopen("input.in","rt",stdin);
		//freopen("output.out","wt",stdout);
	#endif

	solve();

	#ifndef ONLINE_JUDGE
		printf("\n\ntime-%.3lf",clock()*1e-3);
	#endif

	return 0;
}