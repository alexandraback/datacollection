#pragma comment(linker,"/stack:256000000")

#include <cmath> 
#include <ctime> 
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <set> 
#include <map> 
#include <cstring> 
#include <cstdlib> 
#include <queue> 
#include <cstdio> 
#include <cfloat>
#include <cassert>
#include <ctime>

using namespace std; 

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++) 
#define sz(v) (int)(v).size() 
#define all(v) (v).begin(), (v).end()

//const int INF = (int)1e9;
//bool a[22][22];
//bool u[22][22];
//int res[22][22][22];
//int n, m;
//int dx[] = {0, 0, 1, -1};
//int dy[] = {1, -1, 0, 0};
//
//void dfs(int x, int y) {
//	if (u[x][y] || a[x][y]) return;
//	u[x][y] = 1;
//	REP(i, 4) {
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
//			dfs(nx, ny);
//		}
//	}
//}
//
//void brute() {
//	REP(i, 22) REP(j, 22) REP(k, 22) res[i][j][k] = INF;
//	for (n = 1; n <= 20; n++) {
//		for (m = 1; m <= 20; m++) {
//			if (n * m <= 20) {
//				cerr << n << " " << m << endl;
//				int t = n * m;
//				REP(mask, 1 << t) {
//					memset(a, 0, sizeof(a));
//					int occup = 0;
//					REP(i, t) {
//						if (mask & (1 << i)) {
//							occup++;
//							a[i / m][i % m] = 1;
//						}
//					}
//					memset(u, 0, sizeof(u));
//					REP(i, n) dfs(i, 0);
//					REP(i, n) dfs(i, m - 1);
//					REP(i, m) dfs(0, i);
//					REP(i, m) dfs(n - 1, i);
//					int free = 0;
//					REP(i, n) REP(j, m) if (!u[i][j] || a[i][j]) ++free;
//					for (int i = 0; i <= free; i++) {
//						res[n][m][i] = min(res[n][m][i], occup);
//					}
//				}
//			}
//		}
//	}
//}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	//cout << res[n][m][k] << endl;
	if (n < 3 || m < 3) {
		cout << k << endl;
	} else {
		vector <int> res(n * m + 1, 1000000000);
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= m; b++) {
				int can = a * b - 4;
				int need = 2 * (a - 2) + 2 * (b - 2);
				for (int i = 0; i <= can; i++) {
					res[i] = min(res[i], need);
				}
			}
		}
		cout << res[k] << endl;
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long start = clock();
#endif
	//brute();
	//for (n = 1; n <= 20; n++) {
	//	for (m = 1; m <= 20; m++) {
	//		if (n * m <= 20) {
	//			for (int k = 1; k <= n * m; k++) {
	//				if (res[n][m][k] != k) {
	//					cout << n << " " << m << " " << k << " " << res[n][m][k] << endl;
	//				}
	//			}
	//		}
	//	}
	//}
	//cout << res[4][5][8] << endl;
	//cout << res[3][5][11] << endl;
	int T;
	cin >> T;
	for (int tst = 1; tst <= T; tst++) {
		cerr << tst << endl;
		cout << "Case #" << tst << ": ";
		solve();
	}
	return 0;
}