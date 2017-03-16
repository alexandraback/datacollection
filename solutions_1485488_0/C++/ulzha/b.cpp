#include <iostream>
#include <cstring>
using namespace std;

const int nmax = 100;
int h, n, m, f[nmax][nmax], c[nmax][nmax];
int e[nmax][nmax]; // agrākais laiks, kad varam tur būt
int z[nmax][nmax]; // ātrākais, kā izrāpot uz izeju, pieņemot, ka nožuvis
const int dr[] = {0, -1, 0, 1}, dc[] = {1, 0, -1, 0};
bool v[nmax][nmax];
const int inf = 1E9;

int can(int r0, int c0, int d) {
	int r1 = r0 + dr[d], c1 = c0 + dc[d];

	if (r1 < 0 || r1 >= n || c1 < 0 || c1 >= m) return 0;
	if (h > c[r1][c1] - 50 || f[r0][c0] > c[r1][c1] - 50 || f[r1][c1] > c[r1][c1] - 50) return 0;
	if (f[r1][c1] > c[r0][c0] - 50) return 0;

	if (h - f[r0][c0] >= 20) return 10;

	return 100;
}

int qr[nmax * nmax], qc[nmax * nmax];

void bfs(int r0, int c0) {
	int i, nq = 0, d;

	memset(v, 0, sizeof v);
	qr[0] = r0, qc[0] = c0, nq++;
	v[r0][c0] = 0;
	for (i = 0; i < nq; i++) {
		int r = qr[i], c = qc[i];

		e[r][c] = 0;
		for (d = 0; d < 4; d++) if (can(r, c, d)) {
			int r1 = r + dr[d], c1 = c + dc[d];

			if (!v[r1][c1]++) {
				qr[nq] = r1, qc[nq] = c1, nq++;
			}
		}
	}
}

void bfs2(int r0, int c0) {
	int i, nq = 0, d;

	memset(v, 0, sizeof v);
	qr[0] = r0, qc[0] = c0, nq++;
	v[r0][c0] = 0;
	for (i = 0; i < nq; i++) {
		int r = qr[i], c = qc[i];

		for (d = 0; d < 4; d++) {
			// atpakaļgaitā
			int r1 = r - dr[d], c1 = c - dc[d];

			if (r1 >= 0 && r1 < n && c1 >= 0 && c1 < m && can(r1, c1, d)) {
				if (!v[r1][c1]++) {
					qr[nq] = r1, qc[nq] = c1, nq++;
					z[r1][c1] = z[r][c] + 100;
				}
			}
		}
	}
}

int main() {
	int nt, it;

	cin >> nt;
	for (it = 1; it <= nt; it++) {
		int i, j, t, d, i1, j1, t1;

		cin >> h >> n >> m;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) cin >> c[i][j];
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) cin >> f[i][j];
		}

		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) e[i][j] = inf;
		}
		bfs(0, 0);

		for (t = 0; ; h--, t++) {
// 			memcpy(e, e2, sizeof e);
			for (i = 0; i < n; i++) for (j = 0; j < m; j++) if (e[i][j] <= t) {
				for (d = 0; d < 4; d++) if (t1 = can(i, j, d)) {
					i1 = i + dr[d], j1 = j + dc[d];
					if (e[i1][j1] > t + t1) {
						e[i1][j1] = t + t1;
						if (h < 0) {
							e[n - 1][m - 1] = min(e[n - 1][m - 1], t + t1 + z[i1][j1]);
						}
					}
				}
			}

// 			cout << "t = " << t << ", h = " << h << ":\n";
// 			for (i = 0; i < n; i++) {
// 				for (j = 0; j < m; j++) {
// 					cout << ' ' << e[i][j];
// 				}
// 				cout << endl;
// 			}

			if (!h) {
				z[n - 1][m - 1] = 0;
				bfs2(n - 1, m - 1);
			}

//  			if (e[n - 1][m - 1] != inf) break;
			if (h < -666) break;
		}

		cout << "Case #" << it << ": " << double(e[n - 1][m - 1]) / 10 << '\n';
	}

	return 0;
}
