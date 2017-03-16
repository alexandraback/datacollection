//shashwat001

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back
#define MOD 1000000007

typedef long long int lli;
typedef pair<int,int> pi;

struct gp
{
	int f,l;
};
 lli fac[10004];
lli ways = 1;
int dfs1(int far[],int lar[],gp g[],int visited[],int data[],int idx)
{
	if(lar[idx] == -1)
	{
		return idx;
	}
	int gidx = lar[idx];
	int  first = g[gidx].f;
	if(visited[first])
		return idx;
	visited[first] = 1;
	return dfs1(far,lar,g,visited,data,first);
}


int dfs(int far[],int lar[],gp g[],int visited[],int data[],int idx,int depth)
{
	if(depth>0)
	{
		ways = (ways * fac[data[idx]])%MOD;
		data[idx] = 0;
	}
	if(far[idx]==-1)
		return depth;
	depth++;
	int gidx = far[idx];
	int  last = g[gidx].l;
	if(depth == 1)
	{
		ways = (ways * fac[data[idx]])%MOD;
		data[idx] = 0;
	}
	
	if(visited[last])
	{
		ways = (ways*depth)%MOD;
		return depth;
	}
	visited[last] = 1;
	return dfs(far,lar,g,visited,data,last,depth);
}
int main ()
{
	fac[0] = 1;
	for(int i = 1;i <=1000;i++)
	{
		fac[i] = (fac[i-1]*i) % MOD;
	}
	int t;
	scanf("%d",&t);
	for(int T = 1; T <= t;T++)
	{
		int n;
		scanf("%d",&n);
		char temps[103];
		gp g[105];
		int cg = 0;
		int lar[26],far[26];
		int data[26];
		fill(data,data+26,0);
		
		fill(lar,lar+26,-1);
		fill(far,far+26,-1);
		int visited[26] = {0};
		int visited1[26] = {0};
		int blocked[26] = {0};
		int flag = 0;
		
		for(int i = 0;i < n;i++)
		{
			scanf("%s",temps);
			int len = strlen(temps);
			char curc = temps[0];
			char first = temps[0];
			char last = temps[len-1];

			int j = 0;
			
			while(j < len && temps[j] == first)
			{
				j++;
			}
			while(j < len && temps[j] != last)
			{
				curc = temps[j];
				if(blocked[curc-'a'])
				{
					flag = 1;
					break;
				}
				blocked[curc-'a'] = 1;
				while(j < len && temps[j] == curc)
					j++;
			}
			while(j < len)
			{
				if(temps[j] != last)
				{
					flag = 1;
					break;
				}
				j++;
			}

			if(first == last)
			{
				data[first-'a']++;
			}
			else
			{
				if(blocked[first-'a']==1 || blocked[last-'a']==1)
					flag = 1;
				g[cg].f = first-'a';
				g[cg].l = last-'a';
				if(far[first-'a'] != -1)
					flag = 1;
				else
					far[first-'a'] = cg;
				if(lar[last-'a'] != -1)
					flag = 1;
				else
					lar[last-'a'] = cg;	
				cg++;
			}
		}
		if(flag == 1)
		{
			printf("Case #%d: 0\n",T);
		}
		else
		{
			int cntg = 0;
			ways = 1;
			for(int i = 0;i < 26;i++)
			{
				if(visited[i]==0)
				{
					visited1[i] = 1;
					int root = dfs1(far,lar,g,visited1,data,i);
					visited[root] = 1;
					int depth = dfs(far,lar,g,visited,data,root,0);
					if(depth > 0)
						cntg++;
				}
			}
			for(int i = 0;i < 26;i++)
			{
				if(data[i] > 0)
				{
					cntg++;
					ways = (ways*fac[data[i]])%MOD;
				}
			}
			ways = (ways*fac[cntg])%MOD;
			printf("Case #%d: %lld\n",T,ways);
		}
	}
	return 0;
}
