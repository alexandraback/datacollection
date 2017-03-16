#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#define N 100
#define M 1000000000
using namespace std;
int a[N][N], b[N][N], r, c, h, w[N][N], e[N][N];
struct T
{
	int i, j, t;
	T(int i=0, int j=0, int t=0): i(i), j(j), t(t) {}
};
bool operator <(T a, T b) { return a.t>b.t; }
priority_queue <T> q;
void upd(T v)
{
	if(v.t<w[v.i][v.j]) { w[v.i][v.j]=v.t; q.push(v); }
}
int main()
{
	int ts, t, i, j, di[]={-1, 1, 0, 0}, dj[]={0, 0, -1, 1};
	T v, g;
	for(scanf("%d", &ts), t=1; t<=ts; t++)
	{
		for(scanf("%d%d%d", &h, &r, &c), i=0; i<r; i++)
			for(j=0; j<c; scanf("%d", &b[i][j]), j++);
		for(i=0; i<r; i++)
			for(j=0; j<c; scanf("%d", &a[i][j]), j++);
		for(i=0; i<r; i++)
			for(j=0; j<c; w[i][j]=M, j++)
				if(b[i][j]-a[i][j]<50) e[i][j]=M;
				else if(b[i][j]-h>=50) e[i][j]=0;
				else e[i][j]=h+50-b[i][j];
		for(upd(T(0, 0, 0)); !q.empty(); )
		{
			v=q.top(); q.pop();
			if(v.t!=w[v.i][v.j]) continue;
			for(i=0; i<4; i++)
			{
				g=T(v.i+di[i], v.j+dj[i], v.t);
				if(g.i>=0 && g.i<r && g.j>=0 && g.j<c && b[g.i][g.j]>=a[v.i][v.j]+50 && b[v.i][v.j]>=a[g.i][g.j]+50)
				{
					if(g.t<e[g.i][g.j]) g.t=e[g.i][g.j];
					if(g.t>0)
						if(h-g.t-a[v.i][v.j]>=20) g.t+=10;
						else g.t+=100;
					upd(g);
				}
			}
		}
		printf("Case #%d: %.13lf\n", t, w[r-1][c-1]/10.0);
	}
	return 0;
}