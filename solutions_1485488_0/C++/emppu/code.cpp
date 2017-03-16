#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <assert.h>

//#pragma warning(disable:4996)
using namespace std;

#define TIME fprintf(stderr,"\n-----------\ntime : %.2f sec\n",double(clock())/CLOCKS_PER_SEC);
#define EXIT exit(0);
#define FIN freopen("input.txt","r",stdin);
#define FOUT freopen("output.txt","w",stdout);
#define INP(_X) scanf("%d",& _X);
#define OUT(_X) printf("%d ",_X);
#define LINE printf("\n");
#define DOUT(_X) fprintf(stderr,"%d ",_X);
#define DLINE fprintf(stderr,"\n");

#define M 102
#define MOD 0
#define ADD(_X,_Y) _X=(_X+_Y)%MOD;

#define abs(_Z) (((_Z)<0)?-(_Z):(_Z))
#define f0(_X,_Y) for(_X=0;_X<_Y;++_X)
#define f1(_X,_Y) for(_X=1;_X<=_Y;++_X)
#define ff(_X,_Y,_Z) for(_X=_Y;_X<=_Z;++_X)
#define fF(_X,_Y,_Z) for(_X=_Y;_X<_Z;++_X)
#define pb push_back
#define sz(_X) _X.size()
typedef long long ll;

int n,m,H,ceil[M][M],floor[M][M],v[M][M];
double d[M][M];
struct P{int x,y;
	bool friend operator< (const P &p,const P &q)
	{
		if(d[p.y][p.x]!=d[q.y][q.x]) return d[p.y][p.x]<d[q.y][q.x];
		if(p.y!=q.y) return p.y<q.y;
		return p.x<q.x;
	}
}node,next;
const int DY[]={0,1,0,-1},DX[]={1,0,-1,0};
set<P> q;
int main()
{
	int t,T,i,j,H;
	double h,ntime;

	FIN
	FOUT

	INP(t)
	f1(T,t)
	{
		INP(H)
		INP(n) INP(m)
		f1(i,n) f1(j,m) INP(ceil[i][j])
		f1(i,n) f1(j,m) INP(floor[i][j])
		f1(i,n) f1(j,m) v[i][j]=0, d[i][j]=123123123.*123123123.;
		q.clear(); node.y=1; node.x=1; d[1][1]=0; q.insert(node);
		while(!q.empty())
		{
			node=*q.begin();
			v[node.y][node.x]=true;
			//fprintf(stderr,"%d %d, %.3f\n",node.y,node.x,d[node.y][node.x]);
			q.erase(q.begin());
			f0(i,4)
			{
				next.x=node.x+DX[i];
				next.y=node.y+DY[i];
				if(next.x && next.y && next.x<=m && next.y<=n
					&& !v[next.y][next.x]
					&& ceil[node.y][node.x]>=floor[next.y][next.x]+50
					&& floor[node.y][node.x]+50<=ceil[next.y][next.x]
					&& floor[next.y][next.x]+50<=ceil[next.y][next.x])
					{
						if(H-d[node.y][node.x]*10+50<=ceil[next.y][next.x]) ntime=d[node.y][node.x];
						else ntime=(H-ceil[next.y][next.x]+50)/10.;

						if(ntime>0)
							if(H-ntime*10>=floor[node.y][node.x]+20) ntime+=1; else ntime+=10;

						if(ntime<d[next.y][next.x])
						{
							if(q.find(next)!=q.end()) q.erase(q.find(next));
							d[next.y][next.x]=ntime;
							q.insert(next);
						}
					}
			}
		}
		printf("Case #%d: %.8f\n",T,d[n][m]);
	}
	return 0;
}
