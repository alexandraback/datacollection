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
int const maxn = 111;
typedef long long ll;
ll a[maxn];
ll cal(int n, ll x) {
	ll ret = 0;
	for (int i = 0; i < n; ++i) {
		if (x > a[i]) {
			x += a[i];
		}
		else if (x == 1) {
			return Inf;
		}
		else {
			x += x - 1;
			--i;
			++ret;
		}
	}
	return ret;
}
int main() {
    //freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-ans.txt", "w", stdout);
    freopen("A-large.in", "r", stdin);  freopen("A-large-ans.txt", "w", stdout);
	int T, ca = 1;
	int n; ll now;
	for (scanf("%d", &T); T--; ) {
		scanf("%lld%d", &now, &n);
		for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
		sort(a, a + n);
		ll ret = Inf;
		for (int i = 0; i <= n; ++i) {
			ret = min(ret, (ll)(i + cal(n - i, now)));
		}
		printf("Case #%d: %lld\n", ca++, ret);
	}
	return 0;
}

