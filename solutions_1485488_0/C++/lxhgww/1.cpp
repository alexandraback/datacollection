#include<stdio.h>
#include<queue>

using namespace std;

int h[101][101];
int l[101][101];
bool u[101][101];
double tt[101][101];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int main()
{
	int t,p;
	int n,m;
	int i,j;
	double w;
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%lf",&w);
		scanf("%d%d",&n,&m);
		for (i=0;i<n;i++)
			for (j=0;j<m;j++)
				scanf("%d",&h[i][j]);
		for (i=0;i<n;i++)
			for (j=0;j<m;j++)
				scanf("%d",&l[i][j]);
		memset(u,true,sizeof(u));
		u[0][0]=false;
		for (i=0;i<n;i++)
			for (j=0;j<m;j++)
				tt[i][j]=10000;
		tt[0][0]=0;
		queue<int> que;
		que.push(0);
		while (!que.empty())
		{
			int x=que.front();
			que.pop();
			int y=x%m;
			x=x/m;
			u[x][y]=true;
			for (i=0;i<4;i++)
			{
				int xx=x+dx[i];
				int yy=y+dy[i];
				if (xx<0||xx>=n||yy<0||yy>=m) continue;
				if (h[x][y]-l[xx][yy]<50) continue;
				if (h[xx][yy]-l[x][y]<50) continue;
				if (h[xx][yy]-l[xx][yy]<50) continue;
				double t1,t2;
				if (h[xx][yy]-(w-10*tt[x][y])<50)
				{
					if (h[xx][yy]<50) continue;
					t1=(w-(h[xx][yy]-50))/10;
				}
				else t1=tt[x][y];
				if (t1==0) t2=0;
				else
				{
					if (w-10*t1-l[x][y]>=20) t2=t1+1;
					else t2=t1+10;
				}
				if (tt[xx][yy]>t2)
				{
					tt[xx][yy]=t2;
					if (u[xx][yy])
					{
						que.push(xx*m+yy);
						u[xx][yy]=false;
					}
				}
			}
		}
		printf("Case #%d: %.6lf\n",p,tt[n-1][m-1]);
	}
	return 0;
}



