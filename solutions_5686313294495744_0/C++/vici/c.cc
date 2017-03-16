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
int const N = 1010;
int a[N][2];
map<string, int> mp;
int idx;
int getIdx(string s) {
	if (mp.find(s) == mp.end()) {
		mp[s] = ++idx;
	}
	return mp[s];
}
bool h1[N+N], h2[N+N];

int main() {
	//freopen("C-large.in", "r", stdin);
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("c-ans-small", "w", stdout);
	int T, ca = 1;
	string s1, s2;
	for (scanf("%d", &T); T--; ) {
		int n; cin >> n;
		idx = 0; mp.clear();
		int ans = 0;
		rep(i, n) {
			cin >> s1 >> s2;
			a[i][0] = getIdx(s1);
			a[i][1] = getIdx(s2);
		}
		int mx = 1 << n;
		rep(i, mx) if (i > 0) {
			rep(j, idx + 1) h1[j] = h2[j] = 0;
			rep(j, n) if (!(i >> j & 1)) {
				int x = a[j][0], y = a[j][1];
				h1[x] = 1, h2[y] = 1;
			}
			bool ok = 1;
			rep(j, n) if (i >> j & 1) {
				int x = a[j][0], y = a[j][1];
				if (!(h1[x] && h2[y])) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				ans = max(ans, __builtin_popcount(i));
			}
		}
		printf("Case #%d: %d\n", ca++, ans);
	}

	return 0;
}

