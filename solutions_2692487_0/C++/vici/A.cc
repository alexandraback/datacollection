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
int a[maxn];
int cal(int n, int x) {
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		if (x > a[i]) {
			x += a[i];
		}
		else if (x == 1) {
			return inf;
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
    freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-ans.txt", "w", stdout);
  //  freopen("A-large.in", "r", stdin);  freopen("A-large-ans.txt", "w", stdout);
	int T, ca = 1;
	int now, n;
	for (scanf("%d", &T); T--; ) {
		scanf("%d%d", &now, &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		sort(a, a + n);
		int ret = inf;
		for (int i = 0; i <= n; ++i) {
			ret = min(ret, i + cal(n - i, now));
		}
		printf("Case #%d: %d\n", ca++, ret);
	}
	return 0;
}

