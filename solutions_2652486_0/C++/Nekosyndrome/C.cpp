#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdio>
#include<vector>
#include<cassert>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<iostream>
#include<algorithm>
#include<functional>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 105
using namespace std;
typedef long long LL;
int t,r,n,m,k,in[M],ans[M];
bool suc,vis[M];
void dfs2(int d,int num)
{
	REP(i,1,k)
		if(num == in[i])
			vis[i]=true;
	//vis[num]=true;
	if(d>=n)return;
	dfs2(d+1,num*ans[d]);
	dfs2(d+1,num);
}
void dfs(int d)
{
	if(suc)return;
	if(d==n)
	{
		MSET(vis,false);
		dfs2(0,1);
		bool flag=true;
		REP(i,1,k)
			if(!vis[i])
			{
				flag=false;
				break;
			}

		if(flag)suc=true;
		return;
	}
	REP(i,2,m)
	{
		ans[d]=i;
		dfs(d+1);
		if(suc)return;
	}
}
int main()
{
	scanf("%d",&t);
	REP(tt,1,t)
	{
		scanf("%d %d %d %d",&r,&n,&m,&k);
		printf("Case #%d:\n",tt);
		
		while(r--)
		{
			suc=false;
			REP(i,1,k)scanf("%d",&in[i]);
			dfs(0);
			REP(i,0,n-1)printf("%d",ans[i]);puts("");
		}
	}
	return 0;
}

