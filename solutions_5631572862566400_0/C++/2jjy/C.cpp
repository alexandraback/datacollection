#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);++i)
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
int ind[1001];
int n;
int visit[1001];
int st;
int maxloop;
void dfs(int iv)
{
	if(ind[iv]==st)
	{
		maxloop=max(maxloop,visit[iv]);
	}
	if(!visit[ind[iv]])
	{
		visit[ind[iv]]=visit[iv]+1;
		dfs(ind[iv]);
	}
}
int tmax;
void dfs2(int iv)
{
	tmax=max(tmax,visit[iv]);
	rep(i,n)
	{
		if(!visit[i]&&ind[i]==iv)
		{
			visit[i]=visit[iv]+1;
			dfs2(i);
		}
	}
}
void task()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&ind[i]);
	maxloop=0;
	rep(i,n)
	{
		memset(visit,0,sizeof visit);
		visit[i]=1;
		st=i;
		dfs(i);
	}
	int tot=0;
	rep(i,n)
	{
		if(ind[i]>i&&ind[ind[i]]==i)
		{
			memset(visit,0,sizeof visit);
			visit[ind[i]]=1;
			visit[i]=1;
			tmax=0;
			dfs2(i);
			tot+=tmax;
			
			memset(visit,0,sizeof visit);
			visit[ind[i]]=1;
			visit[i]=1;
			tmax=0;
			dfs2(ind[i]);
			tot+=tmax;
			
		}
	}
	maxloop=max(maxloop,tot);
	printf("%d\n",maxloop);
}
int main()
{
	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	int nt;scanf("%d",&nt);
	rep(i,nt)
	{
		printf("Case #%d: ",i);
		task();
	}
}
