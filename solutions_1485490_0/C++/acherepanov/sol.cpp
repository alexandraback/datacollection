#include <iostream>
#include <cstdio>

using namespace std;
typedef pair<long long, int> pli;

const int N = 100 + 10;
pli a[N], b[N];
int n, m;
long long dp[N][N];

void sol (int test_number) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i].first >> b[i].second;
	}

	for (int i = 0; i <= n; ++i) {
		dp[i][m] = 0;		
	}	
	for (int i = 0; i <= m; ++i) {
		dp[n][i] = 0;
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);

			long long e1 = a[i].first, e2 = 0;
			for (int k = i + 1, k1 = j; k <= n; ++k) {
				while (k1 < m && e2 < e1) {
					if (b[k1].second == a[i].second) {
						e2 += b[k1].first;
					}
					++k1;
				}
				if (e2 >= e1) {
					dp[i][j] = max(dp[i][j], dp[k][k1] + e1);
				}						
				if (k < n && a[k].second == a[i].second) {
					e1 += a[k].first;
				}
			}

			e1 = b[j].first, e2 = 0;
			for (int k = j + 1, k1 = i; k <= m; ++k) {
				while (k1 < n && e2 < e1) {
					if (a[k1].second == b[j].second) {
						e2 += a[k1].first;
					}
					++k1;
				}
				if (e2 >= e1) {
					dp[i][j] = max(dp[i][j], dp[k1][k] + e1);
				}						
				if (k < m && b[k].second == b[j].second) {
					e1 += b[k].first;
				}
			}
		}
	}
	cout << "Case #" << test_number + 1 << ": " << dp[0][0] << endl;	
}

int main () {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int tests_count;
	cin >> tests_count;
	for (int i = 0; i < tests_count; ++i) {
		sol(i);
	}
	return 0;
}
