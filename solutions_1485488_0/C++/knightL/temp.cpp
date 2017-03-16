#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

int f[101][101];
int c[101][101];
double res[101][101];

struct info
{
	int x, y;
	double d;
	info(int x=0,int y=0,double d=0):x(x),y(y),d(d){}
	bool operator<(const info& b) const
	{
		return d<b.d;
	}
};

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int h,n,m;

double canmovetime(int sx,int sy,int dx,int dy,double ct)
{
	if(0<=dx&&dx<n&&0<=dy&&dy<m)
	{
		if(f[sx][sy]+50>c[dx][dy])
			return 1e200;
		if(f[dx][dy]+50>c[dx][dy])
			return 1e200;
		if(f[dx][dy]+50>c[sx][sy])
			return 1e200;
		return max(ct,(h-c[dx][dy]+50)/10.0);
	}
	else return 1e200;
}


int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{

		scanf("%d%d%d",&h,&n,&m);
		REP(i,n) REP(j,m)
			scanf("%d",&c[i][j]);
		REP(i,n) REP(j,m)
			scanf("%d",&f[i][j]);
		REP(i,n) REP(j,m) res[i][j]=1e100;
		res[0][0]=0;
		priority_queue<info> q;
		{
			queue <pair<int,int> > q2;
			q2.push(make_pair(0,0));
			q.push(info(0,0,0));
			while(!q2.empty())
			{
				int x=q2.front().first,y=q2.front().second;
				q2.pop();
				for(int i=0;i<4;i++)
				{
					int cx=x+dx[i];
					int cy=y+dy[i];
					if(canmovetime(x,y,cx,cy,0)<1e-6&&res[cx][cy]>1e10)
					{
						res[cx][cy]=0;
						q.push(info(cx,cy,0));
						q2.push(make_pair(cx,cy));
					}
				}
			}
		}
		{
			while(!q.empty())
			{
				info cur=q.top();
				q.pop();
				if(fabs(cur.d-res[cur.x][cur.y])>1e-6) continue;
				for(int i=0;i<4;i++)
				{
					int cx=cur.x+dx[i];
					int cy=cur.y+dy[i];
					double tm=canmovetime(cur.x,cur.y,cx,cy,res[cur.x][cur.y]);
					if(tm>1e100) continue;
					if(h-10*tm-20+1e-6>f[cur.x][cur.y])
						tm+=1;
					else
						tm+=10;
					if(res[cx][cy]+1e-6>tm)
					{
						res[cx][cy]=tm;
						q.push(info(cx,cy,res[cx][cy]));
					}
				}
			}
			printf("Case #%d: %.13lf\n",t,res[n-1][m-1]);
		}
	}
}

