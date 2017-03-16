/* AnilKishore * India */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define EACH(it,v) for(typeof((v).begin()) it = (v).begin();it!=(v).end();it++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 502

int F[MX][MX], C[MX][MX], N, M, H;
int del = (int)1e9;
bool done[MX][MX];
double dis[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

struct node
{
	double time; int x, y;
	node(){}
	node(double tt,int xx,int yy){ time=tt; x=xx; y=yy; }
};
bool operator < (const node& a, const node& b){ return a.time > b.time; }

double solve()
{
	SET(done,false);
	REP(i,N) REP(j,M) dis[i][j] = ((double)del)*((double)del);
	
	priority_queue<node> pq;
	pq.push(node(0,0,0));
	dis[0][0] = 0;
	
	while(!pq.empty())
	{
		node cur = pq.top(); pq.pop();
		if(done[cur.x][cur.y]) continue;
		done[cur.x][cur.y]= true;
		int cx = cur.x, cy = cur.y;
		REP(k,4)
		{
			int nx = cur.x + dx[k], ny = cur.y + dy[k];
			if(nx<0 || nx>=N || ny<0 || ny>=M || done[nx][ny]) continue;
			if(C[nx][ny]-F[cx][cy]<50 || C[nx][ny]-F[nx][ny]<50 || C[cx][cy]-F[nx][ny]<50) continue;
			double cw = H; if(cur.time>=del) cw = max(0.0,cw-(10.*(cur.time-del)));
			
			double nt = cur.time;
			
			if(cur.time<del)
			{
				if(C[nx][ny]-cw<50)
				{
					nt = del + (.1*(cw-(C[nx][ny]-50.)));
				}
				else nt = cur.time;
			}
			else
			{
				if(C[nx][ny]-cw<50)
				{
					nt = cur.time + (.1*(cw-(C[nx][ny]-50.)));
				}
				else nt = cur.time;	
			}
			
			if(nt>=del)
			{
				double fcw = H - 10.*(nt-del);
				//printf("%d,%d --> %d,%d : ct = %lf, nt = %lf, fcw = %lf\n",cx,cy,nx,ny,cur.time,nt,fcw);
				if((fcw-F[cx][cy])>=20) nt+=1; else nt+=10;
			}
			
			if(nt<dis[nx][ny]){ dis[nx][ny] = nt; pq.push(node(nt,nx,ny)); }
		}			
	}
	
	if(dis[N-1][M-1]<del) return 0.0;
	return dis[N-1][M-1] - del;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	//freopen("in1.in","r",stdin);
	freopen("out1.out","w",stdout);
	
	for(int kases=SI,kase=1;kase<=kases;kase++)
	{
		H = SI; N = SI; M = SI;
		REP(i,N) REP(j,M) C[i][j] = SI;
		REP(i,N) REP(j,M) F[i][j] = SI;
		printf("Case #%d: %lf\n",kase,solve());
	}
	
	return 0;
}
