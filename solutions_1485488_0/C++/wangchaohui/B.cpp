#include <stdio.h>
#include <algorithm>
using namespace std;

int N,M,H;
int F[100][100];
int C[100][100];
int f[128][100][100];

#define MASK 127

int ux[4]={0,0,1,-1};
int uy[4]={1,-1,0,0};

#define ok(x,y) (0<=x && x<N && 0<=y && y<M)
#define check(c1,f1,c2,f2) (c2-f2>=50 && c2-f1>=50 && c1-f2>=50)

void dfs(int i,int j)
{
	f[H&MASK][i][j]=0;
	int k;
	for(k=0;k<4;k++)
	{
		int nx=i+ux[k];
		int ny=j+uy[k];
		if(!ok(nx,ny) || !check(C[i][j],max(F[i][j],H),C[nx][ny],max(F[nx][ny],H)))continue;
		if(f[H&MASK][nx][ny]==0)continue;
		dfs(nx,ny);
	}
}

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	int T,TC=0;
	scanf("%d",&T);
	while(++TC<=T)
	{
		printf("Case #%d: ",TC);
		scanf("%d %d %d",&H,&N,&M);
		int i,j,h,k;
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{
				scanf("%d",&C[i][j]);
			}
		}
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{
				scanf("%d",&F[i][j]);
			}
		}
		memset(f,-1,sizeof(f));
		dfs(0,0);
		int ans=2000000000;
		for(h=H;h>0;h--)
		{
			for(i=0;i<N;i++)
			{
				for(j=0;j<M;j++)
				{
					if(!~f[h&MASK][i][j])continue;
					for(k=0;k<4;k++)
					{
						int nx=i+ux[k];
						int ny=j+uy[k];
						if(!ok(nx,ny) || !check(C[i][j],max(F[i][j],h),C[nx][ny],max(F[nx][ny],h)))continue;
						int nh=h-100,t=100;
						if(h-F[i][j]>=20)nh=h-10,t=10;
						if(nh<0)nh=0;
						if(!~f[nh&MASK][nx][ny] || f[nh&MASK][nx][ny]>f[h&MASK][i][j]+t)
						{
							f[nh&MASK][nx][ny]=f[h&MASK][i][j]+t;
						}
					}
					int nh=h-1;
					if(!~f[nh&MASK][i][j] || f[nh&MASK][i][j]>f[h&MASK][i][j]+1)
					{
						f[nh&MASK][j][i]=f[h&MASK][i][j]+1;
					}
				}
			}
			if(~f[h&MASK][N-1][M-1] && f[h&MASK][N-1][M-1]<ans)
			{
				ans=f[h&MASK][N-1][M-1];
			}
			memset(f[h&MASK],-1,sizeof(f[h&MASK]));
		}
 		for(h=10000;h>0;h--)
		{
			for(i=0;i<N;i++)
			{
				for(j=0;j<M;j++)
				{
					if(!~f[0][i][j])continue;
					for(k=0;k<4;k++)
					{
						int nx=i+ux[k];
						int ny=j+uy[k];
						if(!ok(nx,ny) || !check(C[i][j],F[i][j],C[nx][ny],F[nx][ny]))continue;

						if(!~f[0][nx][ny] || f[0][nx][ny]>f[0][i][j]+100)
						{
							f[0][nx][ny]=f[0][i][j]+100;
						}
					}
				}
			}
		}
		if(f[0][N-1][M-1]<ans)ans=f[0][N-1][M-1];
		printf("%lf\n",ans/10.0);
	}
	return 0;
}