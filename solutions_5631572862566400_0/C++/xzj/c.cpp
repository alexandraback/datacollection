#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;
typedef long long LL;
struct Edge{
	int v,next,kk;
	Edge(){}	
	Edge(int v,int next,int kk):v(v),next(next),kk(kk){}
}edge[2100];
int edn,p[2100],f[2100];
bool init[1100];
void addedge(int u,int v,int c)
{
	edge[edn] = Edge(v,p[u],c);
	p[u] = edn++;
}
int ans;
int tmp;
void dfs(int x,int fir,int num)
{
	init[x] =1;
	for(int i=p[x];~i;i=edge[i].next)
	if(edge[i].kk)
	{
		int y = edge[i].v;
		if(init[y])
		{
			if (y == fir)ans = max(ans,num);
		}
		else dfs(y,fir,num+1);
	}
}
void work(int x,int other,int num)
{
	tmp = max(tmp,num);
	for(int i=p[x];~i;i=edge[i].next)
	if(!edge[i].kk)
	{
		int y = edge[i].v;
		if(y!=other) work(y,other,num+1);
	}
}
int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int numcase;
	cin>>numcase;
	for(int ii=1;ii<=numcase;ii++)
	{
		edn=0;
		memset(p,-1,sizeof(p));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int t;
			scanf("%d",&t);
			f[i]=t;
			addedge(i,t,1);
			addedge(t,i,0);
		}
		ans = 0;
		for(int i=1;i<=n;i++)
		{
			memset(init,0,sizeof(init));
			dfs(i,i,1);
		}
		
		int r=0;
		for(int i=1;i<=n;i++)
		{
			if (f[f[i]]==i)
			{
				int j = f[i];
				tmp = 0;
				work(i,j,0);
				int a1=tmp;
				tmp = 0;
				work(j,i,0);
				int a2=tmp;
				r = r+2+a1+a2;
			}
		}
		ans = max(ans,r/2);
		printf("Case #%d: %d\n",ii,ans);
	}
	return 0;
}
/*
1
4
3 3 4 3
*/
