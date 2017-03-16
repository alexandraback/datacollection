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

int num[100];
ll na[100], nb[100];
ll ra, rb, rd;
void upd(ll a, ll b) {
	ll td = max(a - b, b - a);
	if (td < rd) {
		rd = td, ra = a, rb = b;
	} else if (td == rd) {
		if (a < ra) {
			ra = a, rb = b;
		} else if (a == ra && b < rb) {
			rb = b;
		}
	}
}

ll cal(string s, bool d) {
	ll ret = 0;
	rep(i, s.length()) {
		int x = 0;
		if (s[i] == '?') {
			if (d) x = 9;
			else x = 0;
		} else {
			x = s[i] - '0';
		}
		ret = ret * 10 + x;
	}
	return ret;
}

int main() {
	freopen("B-large.in", "r", stdin);
	//freopen("B-small-attempt0.in", "r", stdin);
	freopen("b-ans-large", "w", stdout);
	int T, ca = 1;
	string a, b;
	for (scanf("%d", &T); T--; ) {
		cin >> a >> b;
		int n = a.length();
		ra = Inf, rb = Inf, rd = Inf;
		ll ta, tb;
		rep(i, n) {
			if (a[i] == '?' && b[i] == '?') {
				a[i] = '0'; b[i] = '1';
				ta = cal(a, 1), tb = cal(b, 0);
				upd(ta, tb);
				a[i] = '1'; b[i] = '0';
				ta = cal(a, 0), tb =cal(b, 1);
				upd(ta, tb);

				a[i] = '0'; b[i] = '0'; 
			} else if (a[i] == '?' && b[i] != '?') {
				int kb = b[i] - '0';
				if (kb < 9) {
					a[i] = b[i] + 1;
					ta = cal(a, 0), tb = cal(b, 1);
					upd(ta, tb);
				}
				if (kb > 0) {
					a[i] = b[i] - 1;
					ta = cal(a, 1), tb = cal(b, 0);
					upd(ta, tb);
				}
				a[i] = b[i];
			} else if (a[i] != '?' && b[i] == '?') {
				int ka = a[i] - '0';
				if (ka < 9) {
					b[i] = a[i] + 1;
					ta = cal(a, 1), tb = cal(b, 0);
					upd(ta, tb);
				}
				if (ka > 0) {
					b[i] = a[i] - 1;
					ta = cal(a, 0), tb = cal(b, 1);
					upd(ta, tb);
				}
				b[i] = a[i];
			} else {
				if (a[i] == b[i]) continue;
				else if (a[i] < b[i]) {
					ta = cal(a, 1), tb = cal(b, 0);
					upd(ta, tb);
					break;
				} else {
					ta = cal(a, 0), tb = cal(b, 1);
					upd(ta, tb);
					break;
				}
			}
		}
		bool mark = 0;
		ta = tb = 0;
		rep(i, n) {
			if (a[i] == '?' || b[i] == '?') {
				mark = 1;
				break;
			}
			ta = ta * 10 + (a[i] - '0');
			tb = tb * 10 + (b[i] - '0');
		}
		if (!mark) upd(ta, tb);
		printf("Case #%d: ", ca++);
		rep(i, n) {
			num[n - i - 1] = ra % 10; ra /= 10;
		}
		rep(i, n) printf("%d", num[i]); printf(" ");
		rep(i, n) {
			num[n - i - 1] = rb % 10; rb /= 10;
		}
		rep(i, n) printf("%d", num[i]); puts("");
	}

	return 0;
}




