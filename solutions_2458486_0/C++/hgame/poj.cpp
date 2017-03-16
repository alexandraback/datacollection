#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <set>
#include <complex>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
int init[40];
int ans[20];
int _keys[20][40];
set<vector<int>> dp[1<<20];
bool operator <(const vector<int> &a,const vector<int> &b)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>b[i]) return 0;
	}
	return 1;
}
struct Chest
{
	int self,keycnt;
	pair<int,int> keys[40];
}chest[20];
int k,n,keysz=0;
bool dfs(int deep,int msk,vector<int> &state)
{
	if(deep==n) return 1;
	vector<int> state2=vector<int>(keysz,0);
	for(int i=0;i<n;i++)
	{
		if(!(1<<i&msk)) state2[chest[i].self]++;
	}
	for(int i=0;i<keysz;i++)
	{
		if(state[i]>state2[i]) state[i]=state2[i];
	}
	for(set<vector<int>>::iterator p=dp[msk].begin();p!=dp[msk].end();p++)
	{
		if(state<*p) return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(!(1<<i&msk))
		{
			if(state[chest[i].self]>0)
			{
				state2=state;
				state2[chest[i].self]--;
				for(int j=0;j<chest[i].keycnt;j++) state2[chest[i].keys[j].first]+=chest[i].keys[j].second;
				ans[deep]=i;
				if(dfs(deep+1,msk|1<<i,state2)) return 1;
			}
		}
	}
	dp[msk].insert(state);
	return 0;
}
int main()
{
	int cas;
	freopen("D-small-attempt1.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&cas);
	for(int cs=1;cs<=cas;cs++)
	{
		keysz=0;
		scanf("%d %d",&k,&n);
		map<int,int> mp;
		for(int i=0;i<k;i++) scanf("%d",init+i);
		for(int i=0;i<1<<n;i++) dp[i].clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&chest[i].self,&chest[i].keycnt);
			if(mp.find(chest[i].self)==mp.end()) mp[chest[i].self]=keysz++;
			chest[i].self=mp[chest[i].self];
			for(int j=0;j<chest[i].keycnt;j++) scanf("%d",&_keys[i][j]);
		}
		for(int i=0;i<n;i++)
		{
			int _keycnt=0;
			int _a[20];
			memset(_a,0,keysz<<2);
			for(int j=0;j<chest[i].keycnt;j++)
			{
				if(mp.find(_keys[i][j])!=mp.end()) _a[mp[_keys[i][j]]]++;
			}
			chest[i].keycnt=0;
			for(int j=0;j<keysz;j++)
			{
				if(_a[j]!=0)
				{
					chest[i].keys[chest[i].keycnt++]=make_pair(j,_a[j]);
				}
			}
		}
		vector<int> state=vector<int>(keysz,0);
		for(int i=0;i<k;i++)
		{
			if(mp.find(init[i])!=mp.end()) state[mp[init[i]]]++;
		}
		printf("Case #%d: ",cs);
		if(!dfs(0,0,state)) puts("IMPOSSIBLE");
		else
		{
			for(int i=0;i<n;i++) printf("%d ",ans[i]+1);
			putchar('\n');
		}
	}
}