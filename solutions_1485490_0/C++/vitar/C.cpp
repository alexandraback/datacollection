#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>
#include <set>
#include <map>
using namespace std;

#define N 105
typedef long long ll;

ll dp[N][N];

struct st {
	ll x;
	int k;
};

st a[N], b[N];

int i, j, k, n, m, T, tt, ii, jj;

ll x, y, z, t, r, res;



int main() {
	freopen("small.in", "r", stdin);	freopen("small.out", "w", stdout);

	scanf("%d", &T);
	for (tt = 1; tt <= T; tt ++) {
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++) {
			scanf("%lld%d", &a[i].x, &a[i].k);
		}
		for (i = 0; i < m; i++) {
			scanf("%lld%d", &b[i].x, &b[i].k);
		}

		memset(dp, 0, sizeof(dp));

		for (i = 0; i < n; i ++) {
			for (j = 0; j < m; j ++) {
				if (a[i].k != b[j].k) {
					if (i == 0 && j == 0) {
						continue;
					}
					if (i > 0) {
						dp[i][j] = max(dp[i][j], dp[i-1][j]);
					}
					if (j > 0) {
						dp[i][j] = max(dp[i][j], dp[i][j-1]);
					}
					continue;
				}
				x = y = 0;
				t = 0;
				for (ii = i; ii >= 0; ii --) {
					if (a[ii].k != a[i].k) {
						continue;
					}
					x += a[ii].x;
					y = 0;
					for (jj = j; jj >= 0; jj --) {
						if (b[jj].k != b[j].k) {
							continue;
						}
						y += b[jj].x;
						z = min(x, y);
						if (ii > 0 && jj > 0) {
							z += dp[ii-1][jj-1];
						}
						if (z > dp[i][j]) {
							dp[i][j] = z;
						}
					}
				}
			}
		}
		printf("Case #%d: %lld\n", tt, dp[n-1][m-1]);
	}
	return 0;
}







