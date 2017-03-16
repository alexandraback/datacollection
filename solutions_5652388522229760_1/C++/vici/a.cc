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

int main() {
	freopen("A-large.in", "r", stdin);
	//freopen("A-small-attempt0.in", "r", stdin);
	freopen("a-ans-large", "w", stdout);
	int T, ca = 1; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		if (n == 0) {
			printf("Case #%d: INSOMNIA\n", ca++);
			continue;
		}
		
		int msk = 0;
		for (ll i = 1; ; ++i) {
			ll t = i * n;
			while (t) {
				msk |= 1 << (t % 10); t /= 10;
			}
			if (__builtin_popcount(msk) == 10) {
				printf("Case #%d: %I64d\n", ca++, i * n);
				break;
			}
		}
	}

	return 0;
}

