#include <list>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <ext/hash_map>
#include <stdint.h>
#include <ctime>
#include <queue>
#include <sstream>
#include <sys/time.h>
#include <fstream>
#include <vector>

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef long long LL;
typedef unsigned char BYTE;

#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FORU(i, s, e) for (int i = (s); i <= (e); ++i)
#define FORD(i, s, e) for (int i = (s); i >= (e); --i)
#define ALL(x) x.begin(),x.end()
#define FOREACH(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define SIZE(x) ((int)x.size())
#define MP make_pair
#define PB push_back
#define BIT(x, b) (((x) >> (b)) & 1)
#define SWAP(a, b, t) do {t = a; a = b; b = t;} while (0);
#define INF 1000000000
#define EPS 1e-9
#define TIME_LEFT_UNTIL(end) ((curTime=getTime()-startTime) < (end))
#define TIME_LEFT() TIME_LEFT_UNTIL(MAX_TIME)
#define INIT_TIME() startTime = getTime()

static inline double getTime () {
   timeval tv;
   gettimeofday(&tv, 0);
   return tv.tv_sec + tv.tv_usec * 1e-6;
}

#define MAXH 10203
#define MAXR 103
#define MAXC 103
//#define PASSABLE(r1, c1, r2, c2, h) (ch[r2][c2] - max(fh[r2][c2], h) >= 50 && ch[r1][c1] - max(fh[r2][c2], h) >= 50 && ch[r2][c2] - max(fh[r1][c1], h) >= 50)
#define PASSABLE(r1, c1, r2, c2, h) (ch[r2][c2] - h >= 50 && ch[r2][c2] - fh[r1][c1] >= 50 && ch[r2][c2] - fh[r2][c2] >= 50 && ch[r1][c1] - fh[r2][c2] >= 50)

bool reachable[MAXH][MAXR][MAXC]; // [.1 * secs passed][r][c]
int nowater[MAXR][MAXC]; // time if there is no water left
int fh[MAXR][MAXC];
int ch[MAXR][MAXC];
int H, R, C;

const int dr[4] = {0, 0, 1, -1};
const int dc[4] = {1, -1, 0, 0};

void fillStartReach (int r, int c) {
	reachable[0][r][c] = 1;
	FOR(i, 4) {
		int nr = r + dr[i], nc = c + dc[i];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C || reachable[0][nr][nc])
			continue;
		if (PASSABLE(r, c, nr, nc, H))
			fillStartReach(nr, nc);
	}
}

int main () {
	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		cerr << itr << endl;
		scanf("%d%d%d", &H, &R, &C);

		FOR(i, R)
			FOR(j, C)
				scanf("%d", &ch[i][j]);
		FOR(i, R)
			FOR(j, C)
				scanf("%d", &fh[i][j]);

		FORU(h, 0, H+100)
			FOR(r, R)
				FOR(c, C)
					reachable[h][r][c] = 0;
		fillStartReach(0, 0);

		double out = -1;
		FORU(t, 0, H) {
			if (reachable[t][R-1][C-1]) {
				out = .1 * t;
				break;
			}
			int h = max(0, H - t);
			FOR(r, R)
				FOR(c, C)
					if (reachable[t][r][c]) {
						reachable[t+1][r][c] = 1;
						FOR(i, 4) {
							int nr = r + dr[i], nc = c + dc[i];
							if (nr < 0 || nr >= R || nc < 0 || nc >= C)
								continue;
							if (PASSABLE(r, c, nr, nc, h)) {
								if (h - fh[r][c] >= 20)
									reachable[t+10][nr][nc] = 1;
								else
									reachable[t+100][nr][nc] = 1;
							}
						}
					}
		}
		if (out > -.5)
			printf("Case #%d: %.1f\n", itr+1, out);
		else {
			double out = 1e100;
			FORU(t, H, H+100) {
				bool vis[R][C];
				int rq[R*C], cq[R*C], sq[R*C];
				int len = 0;
				FOR(r, R)
					FOR(c, C) {
						if (reachable[t][r][c]) {
							vis[r][c] = 1;
							rq[len] = r;
							cq[len] = c;
							sq[len] = 0;
							++len;
						}
						else
							vis[r][c] = 0;
					}

//				printf("%d ", len);
				FOR(q, len) {
					int r = rq[q], c = cq[q], s = sq[q];

					if (r == R-1 && c == C-1) {
						out = min(out, .1 * t + 10 * s);
						break;
					}

					FOR(i, 4) {
						int nr = r + dr[i], nc = c + dc[i];
						if (nr < 0 || nr >= R || nc < 0 || nc >= C || vis[nr][nc])
							continue;
						if (PASSABLE(r, c, nr, nc, 0)) {
							vis[nr][nc] = 1;
							rq[len] = nr;
							cq[len] = nc;
							sq[len] = s + 1;
							++len;
						}
					}
				}
//				printf("%d %d\n", len, R*C);
			}
			printf("Case #%d: %.1f\n", itr+1, out);
		}
	}
}
