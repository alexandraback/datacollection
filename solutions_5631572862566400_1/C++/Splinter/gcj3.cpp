#include <bits/stdc++.h>
using namespace std;

int n , f[1011];
int du[1011];
vector<int> edges[1011];

int maxdep[1011];

int q[1011] , l , r;bool tree[1011];

int dfs(int o , int st)
{
	if(f[o] == st)return 1;
	return dfs(f[o] , st) + 1;
}

int main()
{
	int test;scanf("%d" , &test);
	for(int tt = 1 ; tt <= test ; tt++)
	{
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++)
			edges[i].clear();
		memset(du , 0 , sizeof du);
		for(int i = 1 ; i <= n ; i++)
		{
			int x;scanf("%d" , &x);
			f[i] = x;
			edges[i].push_back(x);
			du[x]++;
		}
		memset(maxdep , 0 , sizeof maxdep);
		memset(tree , 0 , sizeof tree);
		l = 0;r = 0;
		for(int i = 1 ; i <= n ; i++)
			if(du[i] == 0){q[r++] = i;maxdep[i] = 0;}
		while(l < r)
		{
			int j = q[l++];
			for(auto i : edges[j])
			{
				du[i]--;
				if(maxdep[j] + 1 > maxdep[i])
					maxdep[i] = maxdep[j] + 1;
				if(du[i] == 0)q[r++] = i;
			}
		}
		for(int i = 0 ; i < r ; i++)
			tree[q[i]] = true;
		/*
		for(int i = 1 ; i <= n ; i++)
		{
			printf("tree(%d) = %d,maxdep(%d) = %d\n" , 
				i,tree[i],i,maxdep[i]);
		}*/
		int ans = 0;
		int ans2 = 0;
		for(int i = 1 ; i <= n; i++)
			if(!tree[i])
			{
				//printf("dfs %d\n" , i);
				int sz = dfs(i , i);
				if(sz == 2)
				{
					ans2 += maxdep[i] + maxdep[f[i]] + 2;
					tree[f[i]] = true;
					tree[i] = true;
				}
				else
				{
					if(sz > ans)ans = sz;
				}
			}
		printf("Case #%d: %d\n" , tt , max(ans , ans2));
	}
	return 0;
}