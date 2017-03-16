#include <stdio.h>
#include <string.h>

const int N = 1000;
const int M = 20;

int n, m, nq;
int queue[N];
int mark[N];
int d[N][M], e[N][M], du[N], eu[N];
char mk[N][N];

void init() {
	memset(du, 0, sizeof(du));
	memset(eu, 0, sizeof(eu));
	memset(mk, 0, sizeof(mk));
	memset(mark, 0, sizeof(mark));
	nq = 0;
}

bool inj(int x, int y) {
	for (int i = 0; i < n; i++) {
		if (mk[x][i] && mk[y][i]) {
			return true;
		}
		mk[x][i] += mk[y][i];
	}
	return false;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		init();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &m);
			for (int j = 0; j < m; j++) {
				int v;
				scanf("%d", &v);
				v --;
				d[i][du[i]++] = v;
				e[v][eu[v]++] = i;
			}
		}

		for (int i = 0; i < n; i++) {
			if (du[i] == 0) {
				int l = nq, r = nq;
				queue[r++] = i;
				for (; l < r; l++) {
					int u = queue[l];
					for (int j = 0; j < eu[u]; j++) {
						int v = e[u][j];
						mark[v] ++;
						if (mark[v] == du[v]) {
							queue[r++] = v;
						}
					}
				}
				nq = r;
			}
		}
		for (int i = 0; i < nq; i++) {
			fprintf(stderr, "%d ", queue[i]);
		}
		fprintf(stderr, "\n");

		bool result = false;
		for (int i = 0; i < n; i++) {
			int v = queue[i];
			mk[v][v] = 1;
			for (int j = 0; j < du[v]; j++) {
				int u = d[v][j];
				if (inj(v, u) == true) {
					result = true;
					break;
				}
			}
			if (result) {
				break;
			}
		}

		printf("Case #%d: %s\n", t, result ? "Yes" : "No");
	}
	return 0;
}

