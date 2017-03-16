#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <stack>

#pragma comment(linker, "/STACK:64777216")
using namespace std;


typedef long long ll;
typedef unsigned long long ull;

template<typename T> int size(T & a) { return (int) a.size(); }
template<typename T> T sqr(T a) {return a * a; }

#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pii > 
#define _(a, b) memset((a), (b), sizeof(a))
#define REP(i, a, b) for(int i=(a); i<(b); ++i)
#define all(a) a.begin(),a.end()


const int MAXN = 10, MAXH = 1001;
double dist[MAXN][MAXN][MAXH];
bool inQ[MAXN][MAXN][MAXH];
int low[MAXN][MAXN];
int high[MAXN][MAXN];
int n, m, h;

bool field(int x, int y) {
	return 0 <= x && x < m && 0 <= y && y < n;
}

const int MAXQ = MAXN * MAXN * MAXH;
int x[MAXQ];
int y[MAXQ];
int t[MAXQ];
const int dx[4] = {+1, -1, 0, 0};
const int dy[4] = {0, 0, +1, -1};

bool valid(int x1, int y1, int x2, int y2, int h){
	return h + 50 <= high[y2][x2] && 
		low[y1][x1] + 50 <= high[y2][x2] && 
		low[y2][x2] + 50 <= high[y2][x2] && 
		low[y2][x2] + 50 <= high[y1][x1];
}
int getWeight(int x, int y, int h){
	if (::h == h) return 0;
	int d = max(0, h-low[y][x]);
	return d >= 20 ? 1 : 10;
}
void ford() {
	int H=0, T=0;
	REP(i, 0, n) REP(j, 0, m) REP(v, 0, h+1)
		dist[j][i][v] = 1e20;
	dist[0][0][h]=0;
	x[H]=0;y[H]=0;t[H++]=h;
	inQ[0][0][h]=true;
	for(; H != T; ) {
		int xx=x[T];
		int yy=y[T];
		int tt=t[T];
		++T;
		if(T==MAXQ)T=0;
		inQ[xx][yy][tt]=false;
		if(tt>0) {
			double nd=dist[xx][yy][tt] + 0.1;
			if (nd < dist[xx][yy][tt - 1]) {
				dist[xx][yy][tt - 1]=nd;
				if (!inQ[xx][yy][tt - 1]){
					inQ[xx][yy][tt-1]=true;
					x[H]=xx;y[H]=yy;t[H++]=tt-1;
					if(H==MAXQ)H=0;
				}
			}
		}
		REP(v, 0, 4) {
			int nx = xx + dx[v];
			int ny = yy + dy[v];
			if (!field(nx, ny)) continue;
			if (!valid(xx, yy, nx, ny, tt)) continue;
			int gw = getWeight(xx, yy, tt);
			int nt=max(0, tt-gw*10);
			double nd = dist[xx][yy][tt] + gw;
			if (nd < dist[nx][ny][nt]) {
				dist[nx][ny][nt] = nd;
				if (!inQ[nx][ny][nt]){
					inQ[nx][ny][nt]=true;
					x[H]=nx;y[H]=ny;t[H++]=nt;
					if(H==MAXQ)H=0;
				}
			}
		}
	}
}
void solve(int tn) {
		
	cin >> h >> n >> m;
	REP(i, 0 ,n) REP(j ,0, m) cin >> high[i][j];
	REP(i, 0 ,n) REP(j, 0, m) cin >> low[i][j];

	ford();

	double ans=1e20;
	REP(v, 0, h+1)ans = min(ans, dist[m - 1][n - 1][v]);
	printf("Case #%d: %.10lf\n", tn, ans);
	
}
int main() {            
#ifdef air
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	char buf[1024];
	gets(buf);
	int tc;
	sscanf(buf, "%d", &tc);
	REP(t, 1, tc + 1) {
		solve(t);
	}

}