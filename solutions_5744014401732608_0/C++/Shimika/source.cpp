#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int t, b, m, a[8][8], v[8], c[8], w[8][8], e[8], mx;

void recall(int from, int to, int lev) {
	if (lev > mx) { return; }
	bool flag;
	if (from == b + 1) {
		for (int i = 1; i <= b; i++) {
			v[i] = 0;
			c[i] = 0;
		}
		v[1] = 1;
		for (int i = 1; i <= b; i++) {
			for (int j = i + 1; j <= b; j++) {
				c[j] += a[i][j];
			}
		}

		queue<int> q;
		q.push(1);
		do {
			int xi = q.front(); q.pop();
			for (int i = 2; i <= b; i++) {
				if (a[xi][i] == 1 && c[i] > 0) {
					v[i] += v[xi];
					c[i]--;
					if (c[i] == 0) {
						q.push(i);
					}
				}
			}
		} while (q.size());

		if (v[b] == m) {
			mx = lev;
			for (int i = 1; i <= b; i++) {
				for (int j = 1; j <= b; j++) {
					w[i][j] = a[i][j];
				}
			}
		}
	}
	else if (to > b) {
		recall(from + 1, from + 2, lev);
	}
	else {
		if (from == 1 || e[from] > 0) {
			a[from][to] = 1;
			e[to]++;
			recall(from, to + 1, lev + 1);
			e[to]--;
			a[from][to] = 0;
		}
		recall(from, to + 1, lev);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d %d", &b, &m);
		mx = 999999999;
		for (int i = 1; i <= b; i++) {
			e[i] = 0;
			for (int j = 1; j <= b; j++) {
				a[i][j] = 0;
			}
		}
		recall(1, 2, 0);
		if (mx < 999999999) {
			printf("Case #%d: POSSIBLE\n", tt);
			for (int i = 1; i <= b; i++) {
				for (int j = 1; j <= b; j++) {
					printf("%d", w[i][j]);
				}
				printf("\n");
			}
		}
		else {
			printf("Case #%d: IMPOSSIBLE\n", tt);
		}
	}

	return 0;
}