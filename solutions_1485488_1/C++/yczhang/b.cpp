#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 1000000000;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int A[100][100];
int B[100][100];
int N, M;
int H;

bool visd[100][100];
int dist[100][100];

int judge(int r1, int c1, int r2, int c2) {
	if (B[r2][c2] > A[r2][c2] - 50) return inf;
	if (B[r1][c1] > A[r2][c2] - 50) return inf;
	if (B[r2][c2] > A[r1][c1] - 50) return inf;
	return H - (A[r2][c2] - 50);
}

void dfs(int r, int c) {
	if (visd[r][c]) return;
	visd[r][c] = true;
	dist[r][c] = 0;

	for (int i = 0; i < 4; i++) {
		int r1 = r + dir[i][0];
		int c1 = c + dir[i][1];

		if (r1 < 0 || r1 >= N || c1 < 0 || c1 >= M) continue;

		int ret = judge(r, c, r1, c1);
		if (ret == inf) continue;

		if (ret <= 0) dfs(r1, c1);
	}
}

int solve() {
	memset(visd, 0, sizeof visd);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			dist[i][j] = inf;

	dfs(0, 0);
	memset(visd, 0, sizeof visd);

	while (1) {
		int minr, minc, m = 1000000000;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (!visd[i][j] && dist[i][j] < m) {
					m = dist[i][j];
					minr = i;
					minc = j;
				}

		if (minr == N-1 && minc == M-1) return m;
		visd[minr][minc] = true;

		for (int i = 0; i < 4; i++) {
			int r1 = minr + dir[i][0];
			int c1 = minc + dir[i][1];

			if (r1 < 0 || r1 >= N || c1 < 0 || c1 >= M) continue;

			int ret = judge(minr, minc, r1, c1);
			if (ret == inf) continue;

			ret = max(ret, m);

			int c;
			if (max(H - ret, B[minr][minc]) - B[minr][minc] >= 20) c = 10;
			else c = 100;

			dist[r1][c1] = min(dist[r1][c1], ret + c);
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d", &H, &N, &M);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &A[i][j]);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &B[i][j]);

		printf("Case #%d: %.1lf\n", t, double(solve()) / 10);
	}

	return 0;
}
