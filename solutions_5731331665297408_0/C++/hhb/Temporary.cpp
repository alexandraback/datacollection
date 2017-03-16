#include <stdio.h>
#include <vector>
#include <algorithm>

const int MAXN = 50;
bool map[MAXN][MAXN];
int stack[MAXN];
bool visited[MAXN];

int bc[MAXN];
int find(int a) {
	int r = a, t;
	while (bc[r] != -1) r = bc[r];
	while (a != r) t = bc[a], bc[a] = r, a = t;
	return r;
}

bool unite(int a, int b) {
	int ra = find(a), rb = find(b);
	if (ra == rb) return false;
	bc[ra] = rb;
	return true;
}

void solve() {
	int N, M;
	int zips[MAXN];
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &zips[i]);
	}
	memset(map, 0, sizeof(map));
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		map[a][b] = map[b][a] = true;
	}
	int cur = 0;
	for (int i = 0; i < N; i++) {
		if (zips[i] < zips[cur]) cur = i;
	}
	int sp = 0;
	memset(visited, 0, sizeof(visited));
	int cnt_visited = 0;
	for (int i = 0; i < N; i++) {
		// visit the city
		printf("%d", zips[cur]);
		stack[sp++] = cur;
		visited[cur] = true;
		cnt_visited++;

		// how far can we return?
		memset(bc, -1, sizeof(bc));
		int cnt = 0;
		for (int j = 0; j < N; j++) if (!visited[j]) {
			for (int k = 0; k < N; k++) if (!visited[k] && map[j][k]) {
				cnt += unite(j, k);
			}
		}
		for (int j = 1; j<sp; j++) unite(stack[j], stack[j - 1]);
		int msp = -1;
		while (N - cnt_visited > cnt) {
			int j = stack[++msp];
			for (int k = 0; k < N; k++) if (!visited[k] && map[j][k]) {
				cnt += unite(j, k);
			}
		}

		// find minimum
		int minzip = 100000000;
		int tsp = -1, tar = -1;
		for (int j = msp; j < sp; j++) {
			int p = stack[j];
			for (int k = 0; k < N; k++) if (!visited[k] && map[p][k]) {
				if (zips[k] <= minzip) {
					minzip = zips[k];
					tsp = j;
					tar = k;
				}
			}
		}

		// travel!
		sp = tsp + 1;
		cur = tar;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int c = 1; c <= T; c++) {
		printf("Case #%d: ", c);
		solve();
		putchar('\n');
	}
}