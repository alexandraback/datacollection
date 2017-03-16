//BBB
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long LL;
const int MAX=100+10;
typedef pair<int,int> PAIR;
const double INF=1e20;

double H;
int R,C;
bool vis[MAX][MAX];
double cc[MAX][MAX],ff[MAX][MAX];
double ans[MAX][MAX];


int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


double getTime(int x,int y,int tx,int ty,double now)
{
	if(cc[tx][ty]-ff[tx][ty]<50) return INF;
	if(cc[x][y]-ff[tx][ty]<50) return INF;
	if(cc[tx][ty]-ff[x][y]<50) return INF;
	
	double time=0;
	double hh=H-now*10;
	if(hh<0) hh=0;
	if(hh<ff[x][y])
	{
		if(now==0.0) time=0;
		else time=now+10;
	}
	else
	{
		if(cc[tx][ty]-hh>=50)
		{
			if(hh-ff[x][y]>=20)
			{
				if(now==0.0) time=0;
				else time=now+1;
			}
			else
			{
				if(now==0.0) time=0;
				else time=now+10;
			}
		}
		else
		{
			double wait=(50-(cc[tx][ty]-hh))/10.0;
			double hh=cc[tx][ty]-50;
			if(hh-ff[x][y]>=20)
			{
				time=now+wait+1;
			}
			else
			{
				time=now+wait+10;
			}
		}
	}		
	return time;
}
bool okay(int x,int y)
{
	return (x>=1&&x<=R&&y>=1&&y<=C);
}

void SPFA()
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=C;j++) ans[i][j]=INF;
	}
	ans[1][1]=0;
	queue<PAIR> Q;
	Q.push(make_pair(1,1));
	
	while(!Q.empty())
	{
		PAIR tmp=Q.front();Q.pop();
		int x=tmp.first;
		int y=tmp.second;
		vis[x][y]=0;
		
		for(int k=0;k<4;k++)
		{
			int tx=x+dx[k];
			int ty=y+dy[k];
			if(!okay(tx,ty)) continue;
			
			double time=getTime(x,y,tx,ty,ans[x][y]);
			if(time<ans[tx][ty])
			{
				ans[tx][ty]=time;
				if(vis[tx][ty]==0)
				{
					vis[tx][ty]=1;
					Q.push(make_pair(tx,ty));
				}
			}
		}
	}
}


int main()
{
	int CN=0;
	int T;scanf("%d",&T);
	
	while(T--)
	{
		scanf("%lf%d%d",&H,&R,&C);
		for(int i=1;i<=R;i++)
		{
			for(int j=1;j<=C;j++) scanf("%lf",&cc[i][j]);
		}
		
		for(int i=1;i<=R;i++)
		{
			for(int j=1;j<=C;j++) scanf("%lf",&ff[i][j]);
		}
		
		
		SPFA();
		
		printf("Case #%d: %f\n",++CN,ans[R][C]);
	}
	
	return 0;
}
