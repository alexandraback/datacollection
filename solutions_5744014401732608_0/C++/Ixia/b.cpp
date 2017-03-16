#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
int ans[64][64];
ll qpow(ll a, ll k) {
	ll ans = 1;
	while (k > 0) {
		if (k & 1ll) ans *= a;
		a *= a;
		k >>= 1ll;
	}
	return ans;
}
int main() {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int _, cas = 1;
	scanf("%d", &_);
	while (_--) {
		printf("Case #%d: ", cas);
		++cas;

		int B;
		ll M;
		scanf("%d%I64d", &B, &M);
		ll maxm = qpow(2, B - 2);
		if (M > maxm) {
			puts("IMPOSSIBLE");
		} else {
			puts("POSSIBLE");
			memset(ans, 0, sizeof(ans));
			if (M == 1) {
				ans[1][B] = 1;
			} else {
				for (int i = 2; i <= B; ++i) {
					for (int j = i + 1; j <= B; ++j) {
						ans[i][j] = 1;
					}
				}
				ans[1][B] = 1;
				--M;
				for (int i = 1; i <= B - 2; ++i) {
					if (M & (1ll << (i - 1))) {
						ans[1][B - i] = 1;
					}
				}
			}
			for (int i = 1; i <= B; ++i) {
				for (int j = 1; j <= B; ++j) {
					printf("%d", ans[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}