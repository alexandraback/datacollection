
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long big;
int n,X,Y;
int a[50000];
double ans=0;
const int O=20000;
void dfs(int dep,int x,double now)
{
    //printf("%d #%d %d %d# %f\n",x,a[x-1],a[x],a[x+1],now);
    //getchar();
	if(a[x+1]>a[x]&&a[x-1]>a[x])
	{
		a[x]+=2;
		if(dep<n)dfs(dep+1,0+O,now);
		if(dep==n)
		{
		    //printf("%d %d %f %d\n",dep,x,now,a[x]);
			if(a[X+O]>=Y)ans+=now;
		}
		a[x]-=2;
		return ;
	}
	if(a[x+1]>a[x]&&a[x-1]<a[x])
	{
		dfs(dep,x-1,now);
	}
	else if(a[x+1]<a[x]&&a[x-1]>a[x])
	{
		dfs(dep,x+1,now);
	}
	else if(a[x]>a[x-1]&&a[x]>a[x+1])
	{
		dfs(dep,x-1,now/2.0);
		dfs(dep,x+1,now/2.0);
	}
}
int main()
{
	int now,cas,cass,i,j,s;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&cas);
	for(cass=1;cass<=cas;cass++)
	{
		ans=0;
		memset(a,-1,sizeof(a));
		printf("Case #%d: ",cass);
		scanf("%d%d%d",&n,&X,&Y);
		for(i=0;i<=n*5;i+=2)a[i+O]=-2;
		for(i=0;i>=-n*5;i-=2)a[i+O]=-2;
		dfs(1,0+O,1);
		printf("%.8f\n",ans);
	}
}
