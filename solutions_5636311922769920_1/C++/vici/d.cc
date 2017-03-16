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
vector<ll> ans;
ll b[111];

int main() {
	freopen("D-large.in", "r", stdin);
	freopen("d-ans-large", "w", stdout);
	
	int T, ca = 1;
	ll k, c, s;
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d %I64d %I64d", &k, &c, &s);
		printf("Case #%d:", ca++);
		if (s * c < k) puts(" IMPOSSIBLE");
		else {
			b[0] = 1; Rep(i, c) b[i] = b[i - 1] * k;
			ans.clear();
			ll pos = 0;
			rep(step, k) {
				int t = step % c;
				if (t == 0) {
					pos = 0;
				}
				pos += b[c - t - 1] * step;
				
				if ((step + 1) % c == 0) {
					ans.push_back(pos);
				}
			}
			if (k % c != 0) ans.push_back(pos);
			rep(i, ans.size()) printf(" %I64d", ans[i] + 1);
			puts("");
		}
	}
	return 0;
}

