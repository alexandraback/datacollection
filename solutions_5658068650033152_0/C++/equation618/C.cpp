#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int D[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int N,M,K,ans,q[25][2];
bool c[25][25],b[25][25];

int calc()
{
	int l=1,r=0;
	memcpy(c,b,sizeof(b));
	for (int i=1; i<=N; i++)
	{
		if (!c[i][1]) q[++r][0]=i,q[r][1]=1,c[i][1]=1;
		if (!c[i][M]) q[++r][0]=i,q[r][1]=M,c[i][M]=1;
	}
	for (int i=1; i<=M; i++)
	{
		if (!c[1][i]) q[++r][0]=1,q[r][1]=i,c[1][i]=1;
		if (!c[N][i]) q[++r][0]=N,q[r][1]=i,c[N][i]=1;
	}
	for (;l<=r; l++)
	{
		int x=q[l][0],y=q[l][1];
		for (int i=0; i<4; i++)
		{
			int xx=x+D[i][0],yy=y+D[i][1];
			if (1<=xx&&xx<=N&&1<=yy&&yy<=M&&!c[xx][yy]) c[xx][yy]=1,q[++r][0]=xx,q[r][1]=yy;
		}
	}
	return N*M-r;
}

void dfs(int x,int y,int s)
{
	if (s>ans) return;
	if (y>M) {dfs(x+1,1,s); return;}
	if (x>N)
	{
		if (calc()>=K) ans=s;
		return;
	}
	dfs(x,y+1,s);
	b[x][y]=1,dfs(x,y+1,s+1),b[x][y]=0;
}

void doit()
{
	scanf("%d%d%d",&N,&M,&K);
	ans=1e9;dfs(1,1,0);
	printf("%d\n",ans);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1; i<=T; i++) printf("Case #%d: ",i),doit();
	return 0;
}

