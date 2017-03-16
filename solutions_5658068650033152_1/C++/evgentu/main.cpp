#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

typedef long long ll;

const int MAXN = 1010;
int dp[40][MAXN][MAXN];

void solve() {
	int n, m, r;
	cin >> n >> m >> r;
	if (n > m) {
		swap(n, m);
	}
	forn(i, n + 5) {
		forn(j, m + 5) {
			forn(k, MAXN) {
				dp[i][j][k] = MAXN;
			}
		}
	}
	int ans = r;
	int size = n * m;
	for (int i = 1; i < n; ++i) {
		for(int k = 1; k <= m; ++k) {
			if (i == 1) {
				dp[i][k][k] = k;
			} else {
				for (int j = 1; j <= size; ++j) {
					for (int t = -2; t <= 2; ++t) if (k + t >= 1 && k + t <= m && j - k >= 0) {
						dp[i][k][j] = min(dp[i][k][j], dp[i - 1][k + t][j - k] + 2);
					}
					int total = j + k - 2;
					int res = dp[i][k][j] + k - 2;
					if (total >= r) {
						ans = min(ans, res);
					} else {
						ans = min(ans, res + r - total);
					}
				}
			}
		}
	}
	cout << ans << endl;
}

int main(int argc, char **argv) {
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int tt;
	cin >> tt;
	forn(t, tt) {
		cout << "Case #" << (t + 1) << ": ";
		solve();
	}
	return 0;
}
