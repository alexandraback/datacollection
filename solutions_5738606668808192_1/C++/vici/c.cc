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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
ll ans[15];
int main() {
	//freopen("C-small-attempt0.in", "r", stdin);
	freopen("c-ans-large", "w", stdout);

	int T, ca = 1; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		n = 16, m = 500;
		printf("Case #%d:\n", ca++);
		for (ll i = 0; i < (1LL << n); ++i) {
			if ((i & 1) && (i >> (n - 1) & 1)) {
				bool ok = 1;
				for (int k = 2; k <= 10; ++k) {
					ll t = 0;
					for (int l = 0; l < n; ++l) {
						t *= k;
						if (i >> l & 1) ++t;
					}
					bool f = 0;
					for (ll l = 2; l * l <= t; ++l) {
						if (t % l == 0) {
							f = 1;
							ans[k] = l;
							break;
						}
					}
					if (!f) {
						ok = 0; break;
					}
				}

				if (ok) {
					rep(e, 2) rep(j, n) printf("%d", (i >> j & 1));
					for (int j = 2; j <= 10; ++j) printf(" %I64d", ans[j]);
					puts("");
					--m;
					if (m == 0) break;
				}
			}
		}
	}
	return 0;
}

