#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define DEBUG(x) cout << ">>> " << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

#define INF (1<<29)
typedef long long ll;

int T, H, N, M;
int F[120][120], C[120][120];

typedef pair<int,pair<int,int> > Ev;
typedef priority_queue<Ev, vector<Ev>, greater<Ev> > q_type;
q_type q;

Ev ev(int time, int x, int y) {
	return make_pair(time, make_pair(x, y));
}

int waterLevel(int t) {
	return H-t;
}

bool canGo(int t, int x1, int y1, int x2, int y2) {
	if (x2 < 0 || x2 >= M || y2 < 0 || y2 >= N) return false;
	if (waterLevel(t) > C[y2][x2]-50) return false;
	if (F[y1][x1] > C[y2][x2]-50) return false;
	if (F[y2][x2] > C[y2][x2]-50) return false;
	if (F[y2][x2] > C[y1][x1]-50) return false;
	return true;
}

int canGoWhen(int x1, int y1, int x2, int y2) {
	if (x2 < 0 || x2 >= M || y2 < 0 || y2 >= N) return -1;
	if (F[y1][x1] > C[y2][x2]-50) return -1;
	if (F[y2][x2] > C[y2][x2]-50) return -1;
	if (F[y2][x2] > C[y1][x1]-50) return -1;
	int neededChange = H - C[y2][x2]+50;
	return neededChange;
}

bool visited[1200][1200];
int dts[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int main() {
	scanf("%d", &T);
	REP(t,T) {
		scanf("%d%d%d", &H, &N, &M);
		REP(i,N) REP(j,M) scanf("%d", &C[i][j]);
		REP(i,N) REP(j,M) scanf("%d", &F[i][j]);
		REP(i,N) REP(j,M) visited[i][j] = false;
		q = q_type();
		q.push(ev(0, 0, 0));
		int res = -1;
		while (!q.empty()) {
			Ev e = q.top();
			q.pop();
			int now = e.first;
			int x = e.second.first, y = e.second.second;
			if (visited[y][x]) continue;
			visited[y][x] = true;
			if (y == N-1 && x == M-1) {
				res = now;
				break;
			}
			if (now == 0) {
				REP(di,4) {
					int dx = dts[di][0], dy = dts[di][1];
					int nx = x+dx, ny = y+dy;
					if (canGo(0, x, y, nx, ny)) {
						q.push(ev(0, nx, ny));
					}
				}
			}
			REP(di,4) {
				int dx = dts[di][0], dy = dts[di][1];
				int nx = x+dx, ny = y+dy;
				if (canGo(now, x, y, nx, ny)) {
					int dt = 10;
					if (waterLevel(now) < F[y][x]+20) dt = 100;
					q.push(ev(now+dt, nx, ny));
				} else {
					int when = canGoWhen(x, y, nx, ny);
					if (when != -1) {
						int dt = 10;
						if (waterLevel(when) < F[y][x]+20) dt = 100;
						q.push(ev(when+dt, nx, ny));
					}
				}
			}
		}
		printf("Case #%d: %d.%d\n", t+1, res/10, res%10);
	}
	return 0;
}
