#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int di[] = {-1, 0, 0, 1};
int dj[] = {0, -1, 1, 0};

int main() {
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		int h, n, m;
		scanf("%d %d %d", &h, &n, &m);

		int floor[n][m], ceil[n][m];
		int dist[n][m];
		bool final[n][m];

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &ceil[i][j]);
				final[i][j] = false;
				dist[i][j] = -1;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &floor[i][j]);
			}
		}

		priority_queue<pair<int, pair<int, int> > > q;
		q.push(make_pair(0, make_pair(0, 0)));
		dist[0][0] = 0;

		while (!q.empty()) {
			pair<int, pair<int, int> > cur = q.top();
			q.pop();
			int curi = cur.second.first;
			int curj = cur.second.second;
			if (final[curi][curj]) continue;
			final[curi][curj] = true;
			int curdist = -cur.first;

			for (int d = 0; d < 4; ++d) {
				int i = cur.second.first + di[d];
				int j = cur.second.second + dj[d];
				if (i >= 0 && i < n && j >= 0 && j < m && !final[i][j]
						&& ceil[i][j] - floor[i][j] >= 50) {
					int lowest = min(ceil[i][j], ceil[curi][curj]);
					int highest = max(floor[i][j], floor[curi][curj]);
					//printf("hi: %d  lo: %d\n", highest, lowest);
					if (lowest - highest < 50) continue;

					int soonest = 50 - (ceil[i][j] - h);
					if (soonest < 0) soonest = 0;
					//printf("[%d, %d] soonest: %d\n", i, j, soonest);

					int thisway;
					if (soonest == 0 && curdist == 0) {
						thisway = 0;
					} else {
						if (curdist > soonest) soonest = curdist;

						//printf("water at %d (%d above floor)\n", h-soonest, h-soonest-floor[curi][curj]);
						if (h-soonest-floor[curi][curj] >= 20) {
							thisway = soonest + 10;
						} else {
							thisway = soonest + 100;
						}
					}

					if (dist[i][j] == -1 || dist[i][j] > thisway) {
						dist[i][j] = thisway;
						q.push(make_pair(-thisway, make_pair(i,j)));
						//printf("[%d, %d] in %d.%d\n", i, j, thisway/10, thisway%10);
					}
				}
			}
		}

		/*for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				printf("% 4d  ", dist[i][j]);
			}
			printf("\n");
		}*/

		printf("Case #%d: ", tt);
		printf("%d.%d\n", dist[n-1][m-1]/10, dist[n-1][m-1]%10);
	}
}
