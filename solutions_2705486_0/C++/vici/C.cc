#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef long long ll;
char dat[555555][15];
int len[555555];
char str[55];
int dp[55][55];

int main() {
  //  freopen("C-small-attempt0.in", "r", stdin); freopen("C-small-ans.txt", "w", stdout);
  //  freopen("C-large.in", "r", stdin);  freopen("C-large-ans.txt", "w", stdout);
	freopen("dic.txt", "r", stdin);
	freopen("C-small-ans.txt", "w", stdout);
	int n = 521196;
	//int n = 2;
	for (int i = 0; i < n; ++i) scanf(" %s", dat[i]);
	for (int i = 0; i < n; ++i) len[i] = strlen(dat[i]);
	int T, ca = 1;
	for (scanf("%d", &T); T--; ) {
		scanf("%s", str + 1);
		int l = strlen(str + 1);
		memset(dp, 0x3f, sizeof dp);
		dp[0][51] = 0;
		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < n; ++j) {
				if ( i + len[j] > l) continue;
				int pre = -inf, cc = 0;
				int p0 = inf;
				for (int k = 1; k <= len[j]; ++k) {
					if (str[i + k] != dat[j][k - 1]) {
						p0 = min(p0, i + k);
						++cc;
						if (i + k - pre <= 4) {
							cc = -1;
							break;
						}
						pre = i + k;
					}
				}
				if (cc == -1) continue;
				if (cc == 0) {
					for (int k = 0; k <= 51; ++k) {
						dp[i + len[j]][k] = min(dp[i + len[j]][k], dp[i][k]);
					}
				}
				else {
					dp[i + len[j]][pre] = min(dp[i + len[j]][pre], dp[i][51] + cc);
					for (int k = p0 - 5; k >= 0; --k) {
						dp[i + len[j]][pre] = min(dp[i + len[j]][pre], dp[i][k] + cc);
					}
				}
			}
		}
		int ret = inf;
		for (int i = 0; i <= 51; ++i) ret = min(ret, dp[l][i]);
		printf("Case #%d: %d\n", ca++, ret);
	}
	return 0;
}



