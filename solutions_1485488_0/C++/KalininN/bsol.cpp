#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn=205;
const int dx[4]={0,-1,0,1};
const int dy[4]={-1,0,1,0};
const int inf=1e9;

int c[maxn][maxn],f[maxn][maxn],dist[maxn][maxn];
bool was[maxn][maxn],was2[maxn][maxn];
int ans[maxn][maxn];
int n,m,H;

void go1(int x,int y)
{
	if (was[x][y]) return;
	was[x][y]=true;
	for (int d=0;d<4;d++)
	{
		int ni=x+dx[d];
		int nj=y+dy[d];
		if (c[ni][nj]-H<50 || c[ni][nj]-f[ni][nj]<50 || c[ni][nj]-f[x][y]<50 || c[x][y]-f[ni][nj]<50) continue;
		go1(ni,nj);
	}
	return;
}

void go2()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			dist[i][j]=inf;
		}
	}
	dist[n][m]=0;
	int curx=n;
	int cury=m;
	memset(was2,0,sizeof(was2));
	while (curx!=-1)
	{
		was2[curx][cury]=true;
		for (int d=0;d<4;d++)
		{
			int ni=curx+dx[d];
			int nj=cury+dy[d];
			if (c[ni][nj]-f[ni][nj]<50 || c[ni][nj]-f[curx][cury]<50 || c[curx][cury]-f[ni][nj]<50) continue;
			if (dist[ni][nj]<=dist[curx][cury]+100) continue;
			dist[ni][nj]=dist[curx][cury]+100;
		}
		int mind=inf;
		curx=-1;
		cury=-1;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++) if ((!was2[i][j]) && dist[i][j]<mind)
			{
				mind=dist[i][j];
				curx=i;
				cury=j;
			}
		}
	}
}

int main()
{
	int NT=0;
	scanf("%d",&NT);
	for (int T=1;T<=NT;T++)
	{
		scanf("%d%d%d",&H,&n,&m);
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				scanf("%d",&c[i][j]);
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				scanf("%d",&f[i][j]);
			}
		}
		memset(was,0,sizeof(was));
		go1(1,1);
		go2();
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				if (was[i][j]) ans[i][j]=0;
				else ans[i][j]=inf;
			}
		}
		for (int h=H;h>0;h--)
		{
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=m;j++) if (ans[i][j]<=H-h)
				{
					for (int d=0;d<4;d++)
					{
						int ni=i+dx[d];
						int nj=j+dy[d];
						if (c[ni][nj]-h<50 || c[ni][nj]-f[ni][nj]<50 || c[ni][nj]-f[i][j]<50 || c[i][j]-f[ni][nj]<50) continue;
						int time=H-h+10;
						if (h<f[i][j]+20) time=H-h+100;
						ans[ni][nj]=min(ans[ni][nj],time);
					}
				}
			}
		}
		int answer=ans[n][m];
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
// 				cout << "(" << ans[i][j] << ' ' << dist[i][j] << ' ' << H+dist[i][j] << ") ";
				answer=min(answer,max(ans[i][j],H)+dist[i][j]);
// 				printf("from
			}
// 			cout << endl;
		}
		printf("Case #%d: %.1f\n",T,((double)(answer))/10);
	}
	return 0;
}