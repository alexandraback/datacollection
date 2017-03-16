#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 100010
#define ll long long
#define INF (1<<30)
#define pii pair<int, int>
#define MP make_pair
int xx[] = {1,1,0,-1,-1,-1,0,1}, yy[] = {0,1,1,1,0,-1,-1,-1}; //eight direction

using namespace std;

vector<int>adj[1005];
int col[1005];

int dfs(int u, int now)
{
	int i, ret=0, v;
	for(i=0;i<SZ(adj[u]);i++)
	{
		v = adj[u][i];
		if(col[v]!=0)
		{
			if(col[v]==now) continue;
			else return ret=1;
		}
		col[v]=now;
		ret = dfs(v, now);
		if(ret==1) return ret;
	}
	return ret;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("Alarge.out", "w", stdout);
    int t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
    	int n, i, j, cur, u, v;
		scanf("%d", &n);
		for(i=0;i<=n;i++) adj[i].clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d", &cur);
			for(j=0;j<cur;j++)
			{
				scanf("%d", &u);
				adj[i].pb(u);
			}
		}
		int now, ans=0;
		for(i=1;i<=n;i++)
		{
			memset(col, 0, sizeof col);
			for(j=0,now=1;j<SZ(adj[i]);j++,now++)
			{
				col[i]=now;
				u = adj[i][j];
				if(col[u]!=0)
				{
					ans=1;
					break;
				}
				col[u]=now;
				ans = dfs(u, now);
				if(ans==1) break;
			}
			if(ans==1) break;
		}
		if(ans==0) printf("Case #%d: No\n", cas++);
		else printf("Case #%d: Yes\n", cas++);
    }
    return 0;
}

