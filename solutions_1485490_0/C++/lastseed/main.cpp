#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

#define MAXN 110
int A[MAXN], B[MAXN];
LL a[MAXN], b[MAXN];

map<LL, LL> dp[MAXN][MAXN];
map<LL, LL>::iterator it, it1;

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			scanf("%lld%d", a + i, A + i);
		}
		for(int i = 1; i <= m; ++i) {
			scanf("%lld%d", b + i, B + i);
		}
		for(int i = 0; i <= n; ++i)
			for(int j = 0; j <= m + 1; ++j) dp[i][j].clear();
		dp[0][0][0] = 0;
		for(int i = 0; i <= n; ++i)
			for(int j = 0; j <= m; ++j) {
				for(it = dp[i][j].begin(); it != dp[i][j].end(); ++it) {
					LL k = it->first, val = it->second;
					dp[i + 1][j][k] = max(dp[i + 1][j][k], val);
					LL sum = 0;
					if(A[i + 1] == B[j]) sum += b[j] - k;
//					if(i + 1 == 2 && A[i + 1] == B[j] && B[j] == 2) puts("ASDADS");
					if(sum > a[i + 1]) {
						dp[i + 1][j][k + sum - a[i + 1]] = max(dp[i + 1][j][k + sum - a[i + 1]], val + a[i + 1]);
					} else if(sum == a[i + 1]){
						dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], val + a[i + 1]);
					} else {
						dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], val + sum);
						for(int next = j + 1; next <= m; ++next) {
							if(B[next] == A[i + 1]) sum += b[next];
							else continue;
							if(sum > a[i + 1]) {
								LL pos = b[next] - (sum - a[i + 1]);
								dp[i + 1][next][pos] = max(dp[i + 1][next][pos], val + a[i + 1]);
								break;
							} else if(sum == a[i + 1]) {
								dp[i + 1][next + 1][0] = max(dp[i + 1][next + 1][0], val + a[i + 1]);
								break;
							} else {
								dp[i + 1][next + 1][0] = max(dp[i + 1][next + 1][0], val + sum);
							}
						}
					}
				}
			}
		LL res = 0;
		for(int i = 0; i <= n; ++i)
			for(int j = 0; j <= m + 1; ++j) {
				for(it = dp[i][j].begin(); it != dp[i][j].end(); ++it) {
//					printf("dp[%d][%d][%lld] = %lld\n", i, j, it->first, it->second);
					res = max(res, it->second);
				}
			}
		printf("Case #%d: %lld\n", cas, res);
	}
	return 0;
}
