#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define fi(i,a,b) for (int i=a;i<=b;i++)
#define fd(i,a,b) for (int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof(a))
#define mc(a,b) memcpy(a,b,sizeof(a))
using namespace std;

int n,x,y,cnt,h;
bool g[500][500];
double ans;

void dfs(int dep,double k,int tx,int ty)
{
	if (dep>n) return;
	if (ty==0)
	{
		if (x==tx && y==ty) { ans+=k;return;}
		g[tx][ty]=true;
		dfs(dep+1,k,200,h+2);
		g[tx][ty]=false;
		return;
	}

	if (g[tx-1][ty-1] && g[tx+1][ty-1])
	{
		if (x==tx && y==ty) { ans+=k;return;}
		g[tx][ty]=true;if (tx==200) h+=2;
		dfs(dep+1,k,200,h+2);
		g[tx][ty]=false;if (tx==200) h-=2;
	}
	else if (g[tx-1][ty-1]) dfs(dep,k,tx+1,ty-1);
	else if (g[tx+1][ty-1]) dfs(dep,k,tx-1,ty-1);
	else
	{
		dfs(dep,k/2,tx+1,ty-1);
		dfs(dep,k/2,tx-1,ty-1);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	fi(i,1,T)
	{
		scanf("%d%d%d",&n,&x,&y);x+=200;
		ms(g,0);
		ans=0;h=0;
		if (x==200 && y==0) ans=1;
		else
		{
			g[200][0]=1;
			dfs(2,1,200,h+2);
		}
		printf("Case #%d: %.8lf\n",i,ans);

	}

	return 0;
}
