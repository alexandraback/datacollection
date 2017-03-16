//Grzegorz Prusak
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

#define REP(i,n)    for(int i=0; i<(n); ++i)
#define FOR(i,p,k)  for(int i=(p); i<=(k); ++i)
#define FORD(i,p,k) for(int i=(p); i>=(k); --i)

typedef long long LL;

enum { n_max = 120 };

int C[n_max][n_max];
int F[n_max][n_max];

int H,N,M;
bool valid(int n, int m){ return 0<=n && n<N && 0<=m && m<M; }

int color[n_max][n_max];

struct Node
{
	Node(){}
	Node(int _n, int _m, int _t) : n(_n), m(_m), t(_t) {}
	int n,m;
	int t;

	bool operator<(const Node &b) const { return t>b.t; }
};

int dir[][2] = {{-1,0},{1,0},{0,-1},{0,1}};

enum { dir_count = 4 };

int main()
{
	int T; scanf("%d",&T);
	FOR(_,1,T)
	{
		scanf("%d%d%d",&H,&N,&M);
		REP(n,N) REP(m,M) scanf("%d",&C[n][m]);
		REP(n,N) REP(m,M) scanf("%d",&F[n][m]);

		memset(color,0,sizeof color);

		std::priority_queue<Node> Q;
		Q.push(Node(0,0,0));
		int res = -1;
		while(!Q.empty())
		{
			Node x = Q.top(); Q.pop();
			if(x.n==N-1 && x.m==M-1){ res = x.t; break; }
			if(color[x.n][x.m]) continue;
			color[x.n][x.m] = 1;
			REP(i,dir_count)
			{
				Node y(x.n+dir[i][0],x.m+dir[i][1],x.t);
				if(!valid(y.n,y.m)) continue;
				if(color[y.n][y.m]) continue;
				if(C[y.n][y.m]-F[y.n][y.m]<50) continue;
				if(C[y.n][y.m]-F[x.n][x.m]<50) continue;
				if(C[x.n][x.m]-F[y.n][y.m]<50) continue;
				if(C[y.n][y.m]-H>=50 && x.t==0)
				{
					y.t = 0; Q.push(y);
				}
				else
				{
					int h = H-x.t*10;
					int t = std::max(x.t,50-(C[y.n][y.m]-H));
					y.t = t + (H-t-F[x.n][x.m]>=20 ? 10 : 100);
					Q.push(y);
				}
			}
		}

		printf("Case #%d: %.1lf\n",_,res*.1);
	}
	return 0;
}

