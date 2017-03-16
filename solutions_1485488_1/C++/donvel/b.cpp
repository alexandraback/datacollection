#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
//#define DEBUG
#ifdef DEBUG
	#define DEB printf
#else
	#define DEB(...)
#endif
#define VAR(x, v) __typeof(v) x = (v)
#define REP(x, n) for(int x = 0; x < (n); x++)
#define FOR(x, b, e) for(int x = (b); x <= (e); x++)
#define FORD(x, u, d) for(int x = (u); x >= (d); x--)
#define FOREACH(x, v) for(VAR(x, (v).begin()); x != (v).end(); x++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define MIN(a, b) (a) < (b) ? (a) : (b)
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;

//typedef long double LD;

const int INF = 1000000001;

struct point {
	int x, y;
	point() {}
	point(int nx, int ny) {
		x = nx, y = ny;
	}
};


struct event {
	int time, id;
	point p;
	event(int t, int i, point pp) : time(t), id(i), p(pp) {}
	void write() {
		DEB("event(%d, %d, (%d, %d))\n", time, id, p.x, p.y);
	}
};

struct comp {
	bool operator() (event a, event b) {
		if(a.time == b.time) return a.id < b.id;
		return a.time < b.time;
	}
};

const int N = 100;
int flo[N][N], cei[N][N];
bool vis[N][N];

int t,
	n, m,
	h;

set<event, comp> qu;

int num;

bool valid(point p) {
	return p.x >= 0 && p.x < m && p.y >= 0 && p.y < n;
}

int timepass(point p, point q) {
	int c1 = cei[p.x][p.y], c2 = cei[q.x][q.y];
	int f1 = flo[p.x][p.y], f2 = flo[q.x][q.y];
	if(min(c1, c2) - max(f1, f2) < 50) return INF;
	return max(0, h + 50 - min(c1, c2));
}


int bfs() {
	REP(y, n) REP(x, m) vis[x][y] = 0;
	qu.clear();
	num = 0;
	qu.insert(event(0, num++, point(0,0)));

	while(!qu.empty()) {
		event ev = *qu.begin();
		ev.write();
		qu.erase(qu.begin());
		point p = ev.p;
		if(vis[p.x][p.y]) continue;
		vis[p.x][p.y] = 1;
		if(p.x == m - 1 && p.y == n - 1) return ev.time;
			
		point q[4];
		REP(i, 4) q[i] = p;
		q[0].x--, q[1].x++;
		q[2].y--, q[3].y++;
		REP(i, 4) if(valid(q[i]) && !vis[q[i].x][q[i].y]) {
			event tmp(0, num++, q[i]);
			int timemove = max(ev.time, timepass(p, q[i]));
			if(timemove != 0) {
				tmp.time = timemove + ((h - timemove >= flo[p.x][p.y] + 20) ? 10 : 100);
			}
			qu.insert(tmp);	
		}
	}
	return -1;
}

int main() {
	scanf("%d", &t);
	REP(xx, t) {
		scanf("%d%d%d", &h, &n, &m);
		REP(y, n) {
			REP(x, m) scanf("%d", &cei[x][y]);
		}
		REP(y, n) {
			REP(x, m) scanf("%d", &flo[x][y]);
		}

		REP(y, n) {
			REP(x, m) DEB("%d ", cei[x][y]);
			DEB("\n");
		}
		DEB("\n");
		REP(y, n) {
			REP(x, m) DEB("%d ", flo[x][y]);
			DEB("\n");
		}
		DEB("\n");
		printf("Case #%d: %.1Lf\n", xx + 1, (long double)bfs() / 10.0);
	}
}
