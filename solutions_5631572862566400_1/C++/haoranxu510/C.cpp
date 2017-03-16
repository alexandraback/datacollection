#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif

#define maxn 1010

map<int,int> d[maxn];
int ans, cnt;
int stack[maxn], vis[maxn], where[maxn], next[maxn];
vector<int> roots;

void fcycle(int cur)
{
	int top=0; roots.clear();
	while (1)
	{
		vis[cur]=1; top++; stack[top]=cur; where[cur]=top;
		int nex=next[cur];
		if (vis[nex])
		{
			rep(i,where[nex],top)
			{
				int z=i+1; if (i==top) z=where[nex];
				d[stack[i]][stack[z]]=0;
				d[stack[z]][stack[i]]=0;
				roots.push_back(stack[i]);
				cnt++;
			}
			return;
		}
		else	cur=nex;
	}
}

int maxdep;

void solve(int cur, int pre, int dep)
{
	vis[cur]=2; maxdep=max(maxdep,dep);
	rept(it,d[cur])
		if (it->first!=pre && it->second>0)
		{
			int next=it->first;
			assert(vis[next]!=2);
			solve(next,cur,dep+1);
		}
}
	
void lemon()
{
	int n; scanf("%d",&n);
	rep(i,1,n) d[i].clear();
	rep(i,1,n)
	{
		int x; scanf("%d",&x);
		next[i]=x; d[i][x]=1; d[x][i]=1;
	}
	ans=2; int t=0;
	rep(i,1,n) vis[i]=0;
	rep(i,1,n) 
		if (!vis[i])
		{
			cnt=0; fcycle(i);
			vector<int> zz; zz.clear();
			rept(it,roots)
			{
				maxdep = 0;
				solve(*it, -1, 0);
				zz.push_back(maxdep);
			}
			if (zz.size()==2)
			{
				t+=zz[0]+zz[1]+2;
			}
			else
			{
				ans=max(ans,cnt);
			}
		}
	
	ans=max(ans,t);
	printf("%d\n",ans);
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("C.in","r",stdin);
	#endif
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase)
	{
		printf("Case #%d: ",nowcase);
		lemon();
	}
	return 0;
}

