#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define MP make_pair
const int MAXN = 102;
const int diri[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int H, N, M;
int t0[4][MAXN][MAXN], early[MAXN][MAXN], C[MAXN][MAXN], F[MAXN][MAXN];
inline bool inside(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;
}
int main() {
	int testnum, ct, cx, cy;
	scanf("%d", &testnum);
	for (int test = 1;test <= testnum;test++) {
		scanf("%d%d%d", &H, &N, &M);
		//H *= 10;
		for (int i = 0;i < N;i++)
			for (int j = 0;j < M;j++) {
				scanf("%d", &C[i][j]);
				//C[i][j] *= 10;
			}
		for (int i = 0;i < N;i++)
			for (int j = 0;j < M;j++) {
				scanf("%d", &F[i][j]);
				//F[i][j] *= 10;
			}
		printf("Case #%d: ", test);
		for (int dir = 0;dir < 4;dir++) {
			for (int i = 0;i < N;i++) {
				for (int j = 0;j < M;j++) {
					int x = i + diri[dir][0], y = j + diri[dir][1];
					if (!inside(x, y) || C[x][y] < F[x][y] + 50 || C[x][y] < F[i][j] + 50 || C[i][j] < F[x][y] + 50) {
						t0[dir][i][j] = -1;
					} else {
						t0[dir][i][j] = max(0, H - (C[x][y] - 50));
						//t1[dir][i][j] = max(t0[dir][i][j], H - (F[i][j] + 200));
					}
					//printf("%d ", t0[dir][i][j]);
				}
				//puts("");
			}
			//puts("");
		}
		priority_queue<pair<int, pair<int, int> > > q;
		memset(early, -1, sizeof(early));
		early[0][0] = 0;
		q.push(MP(0, MP(0, 0)));
		bool suc = false;
		while (!q.empty() && !suc) {
			pair<int, pair<int, int> > cur = q.top(); q.pop();
			ct = -cur.first; cx = cur.second.first; cy = cur.second.second;
			if (early[cx][cy] < ct) continue;
			/*if (cx == N - 1 && cy == M - 1) {
				suc = true;
				printf("%.1lf\n", ct * .1);
				break;
			}*/
			for (int dir = 0;dir < 4;dir++) {
				int x = cx + diri[dir][0], y = cy + diri[dir][1];
				if (t0[dir][cx][cy] >= 0) {
					int nt = max(0, t0[dir][cx][cy] - ct) + ct;
					if (nt) if (H - nt >= F[cx][cy] + 20) nt += 10; else nt += 100;
					if (early[x][y] < 0 || nt < early[x][y]) {
						early[x][y] = nt;
						q.push(MP(-nt, MP(x, y)));
					}
				}
			}
		}
		//if (!suc) puts("WRONG!");
		printf("%.1lf\n", early[N - 1][M - 1] * .1);
	}
	return 0;
}