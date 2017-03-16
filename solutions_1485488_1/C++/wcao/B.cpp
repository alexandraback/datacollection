#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
#define FOR(i,a,b) for(__typeof(b) i=(a);i!=(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(),a.end()
#define EACH(i,a) FOR(i,a.begin(),a.end())
#define PB push_back
#define iss istringstream
#define SZ(a) (int)a.size()
#define CLEAR(a) memset(a,0,sizeof(a))
#define ll long long

const int MAXN = 105, INF = 1000000000;
int H, N, M;
int T;

int F[MAXN][MAXN], C[MAXN][MAXN];
int dist[MAXN][MAXN];

struct state {
	int d, x, y;
	inline bool operator < (const state &o) const {
		return (d > o.d);
	}
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
inline bool valid(int x, int y) {return (x >= 0 && x < N && y >= 0 && y < M);}

inline int calc(int lo1, int hi1, int lo2, int hi2, int level) {
	//printf("%d %d %d %d %d\n",lo1,hi1,lo2,hi2,level);
	if (lo2 + 50 > hi2) {return INF;}
	int ret = 0;
	if (level > hi2 - 50) {
		int diff = (level - (hi2 - 50));
		ret += diff;
		level = hi2 - 50;
	}
	
	if (level + 50 <= hi2 && max(lo1, lo2) + 50 <= hi2 && lo2 + 50 <= hi1) {
		ret += (level >= lo1 + 20 ? 10 : 100);
		return ret;
	}	else {
		return INF;
	}
}

priority_queue<state> pq;
inline void dfs(int x, int y) {
	if (dist[x][y] != 0) {
		dist[x][y] = 0;
		pq.push((state){0, x, y});
		for(int k = 0 ; k < 4 ; k++) {
			int x2 = x + dx[k], y2 = y + dy[k];
			if (valid(x2, y2) && H + 50 <= C[x2][y2] && max(F[x][y], F[x2][y2]) + 50 <= C[x2][y2] && F[x2][y2] + 50 <= C[x][y]) {
				dfs(x2, y2);
			}
		}
	}
}

int main() {
	scanf("%d",&T);
	for(int t = 1 ; t <= T ; t++) {
		scanf("%d %d %d",&H,&N,&M);
		REP(i,N) REP(j, M) {
			scanf("%d",&C[i][j]);
		}
		REP(i,N) REP(j, M) {
			scanf("%d",&F[i][j]);
		}
		REP(i,N) REP(j, M) {
			dist[i][j] = INF;
		}
		while (!pq.empty()) {pq.pop();}
		dfs(0, 0);
		while (!pq.empty()) {
			state st = pq.top();
			pq.pop();
			if (st.d != dist[st.x][st.y]) {continue;}
			
			int water_level = max(H - st.d, 0);
			
			for(int k = 0 ; k < 4 ; k++) {
				int x = st.x + dx[k], y = st.y + dy[k];
				if (valid(x, y)) {
					int add = calc(F[st.x][st.y], C[st.x][st.y], F[x][y], C[x][y], water_level);
					if (st.d + add < dist[x][y]) {
						dist[x][y] = st.d + add;
						pq.push((state){dist[x][y], x, y});
					}
				}
			}
			
		}
		printf("Case #%d: %.1lf\n",t, ((double)dist[N - 1][M - 1] / 10.0));
	}
	return 0;
}
