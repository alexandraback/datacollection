#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
int const maxn = 22;
typedef long long ll;
int E, R, n;
int v[maxn];
int dp[maxn][maxn];

int main() {
	freopen("B-small-attempt0.in", "r", stdin); freopen("B-small-ans.txt", "w", stdout);
	//freopen("B-large.in", "r", stdin);  freopen("B-large-ans.txt", "w", stdout);
	int T, ca = 1;
	for (scanf("%d", &T); T--; ) {
		scanf("%d%d%d", &E, &R, &n);
		for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
		memset(dp, 0xe0, sizeof dp);
		dp[0][E] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= E; ++j) {
				if (dp[i][j] >= 0) {
					for (int k = 0; k <= j; ++k) {
						int te = min(E, j - k + R);
						dp[i + 1][te] = max(dp[i + 1][te], dp[i][j] + k * v[i]);
					}
				}
			}
		}
		int ret = 0;
		for (int i = 0; i <= E; ++i) ret = max(ret, dp[n][i]);
		printf("Case #%d: %d\n", ca++, ret);
	}
	return 0;
}


