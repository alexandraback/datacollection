#include <set>
#include <cmath>
#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <vector>
#include <ctime>
#include <queue>
#include <list>
#include <map>
#define pi acos(-1.0)
#define INF 0x3f3f3f3f
#define clr(x)  memset(x,0,sizeof(x));
#define clrto(x,siz,y)  for(int xx=0;xx<=siz;xx++)  x[xx]=y;
#define clrset(x,siz)  for(int xx=0;xx<=siz;xx++)  x[xx]=xx;
#define clr_1(x) memset(x,-1,sizeof(x));
#define clrmax(x) memset(x,0x3f,sizeof(x));
#define clrvec(x,siz) for(int xx=0;xx<=siz;xx++)  x[xx].clear();
#define fop2   freopen(".in","r",stdin); //freopen(".out","w",stdout);
#define fop   freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
#define myprogram By_135678942570
#define clrcpy(x,siz,y)  for(int xx=0;xx<siz;xx++)  x[xx]=y[xx];
#define pb push_back
using namespace std;
int mp[55][55];
int vis[55][55];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};

int N,M,P;
int bfs(int now)
{
	int Q[10011]={0};
	int front=0,rear=0;
	Q[++front]=now;
	int sum=1;
	int flag=1;
	vis[now/M][now%M]=1;
	while(front>rear)
	{
		int now=Q[++rear];
		int nx=now/M;
		int ny=now%M;
		for(int i=0;i<4;i++)
		{
			int xx=nx+dx[i];
			int yy=ny+dy[i];
			if(xx<0||yy<0||xx>=N||yy>=M)
			{
				flag=0;
				continue;
			}
			if(vis[xx][yy]==1||mp[xx][yy]==1)
				continue;
			sum++;
			Q[++front]=xx*M+yy;
			vis[xx][yy]=1;
		}
	}
	return flag*sum;
}
int main()
{
	fop;
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&N,&M,&P);
		int res=P;
		for(int i=0;i<1<<(N*M);i++)
		{
			int tmp=__builtin_popcount(i);
			if(tmp>=res)
				continue;
			for(int j=0;j<N;j++)
				for(int k=0;k<M;k++)
					if(i&(1<<(j*M+k)))
						mp[j][k]=1;
					else mp[j][k]=0;
			int sum=0;
			clr(vis);
			for(int j=0;j<N;j++)
				for(int k=0;k<M;k++)
					if(mp[j][k])
						sum++;
					else if(vis[j][k]==0)
						sum+=bfs(j*M+k);
			if(sum>=P)
				res=tmp;
		}
		printf("Case #%d: %d\n",++cas,res);
	}
}
