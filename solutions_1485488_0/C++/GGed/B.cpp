#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define N 105
using namespace std;

struct node{
	int x, y, t;
	node(){}
	node(int x, int y, int t) : x(x), y(y), t(t){}
	bool operator < (node const &T) const{return t > T.t;}
};


int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


int ntc, h, n, m, x, y, tx, ty, t;
int a[N][N], b[N][N], u[N][N], v[N][N];
priority_queue<node> Q;


int main(){
	scanf("%d", &ntc);
	FOE(tc,1,ntc){
		scanf("%d%d%d", &h, &n, &m);
		FOR(i,0,n) FOR(j,0,m) scanf("%d", &a[i][j]);
		FOR(i,0,n) FOR(j,0,m) scanf("%d", &b[i][j]);
		
		CLR(u, 0);
		
		Q.push(node(0, 0, 0));
		while (!Q.empty()){
			node cur = Q.top();
			Q.pop();
			
			x = cur.x, y = cur.y;
			if (u[x][y]) continue;
			u[x][y] = 1;
			v[x][y] = cur.t;
			
			FOR(i,0,4){
				tx = x + dx[i];
				ty = y + dy[i];
				if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
				if (u[tx][ty]) continue;
				
				// Rule B
				if (a[x][y] - b[tx][ty] < 50) continue;

				int t = cur.t;
				// Rule A1
				if (a[tx][ty] - b[tx][ty] < 50) continue;

				// Rule A2
				t = max(t, h - (a[tx][ty] - 50));
				
				// Rule A3
				if (a[tx][ty] - b[x][y] < 50) continue;

				if (t == 0) Q.push(node(tx, ty, 0));
				else if (h - t - b[x][y] >= 20) Q.push(node(tx, ty, t + 10));
				else Q.push(node(tx, ty, t + 100));
			}
		}
		
		printf("Case #%d: %d.%d\n", tc, v[n-1][m-1]/10, v[n-1][m-1]%10);
	}
	return 0;
}

