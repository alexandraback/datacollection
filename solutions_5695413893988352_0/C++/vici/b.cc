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

bool ck(string s, int n, int a) {
	rep(i, n) {
		int t = a % 10;
		char c = s[n - i - 1];
		if (c == '?' || c - '0' == t) { 
		} else return 0;
		a /= 10;
	}
	return 1;
}
int num[10];
int main() {
	//freopen("B-large.in", "r", stdin);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b-ans-small", "w", stdout);
	int T, ca = 1;
	string a, b;
	for (scanf("%d", &T); T--; ) {
		cin >> a >> b;
		int n = a.length();
		int w = 1; rep(i, n) w *= 10;
		int ra = inf, rb = inf, rd = inf;
		rep(i, w) rep(j, w) {
			if (ck(a, n, i) && ck(b, n, j)) {
				int td = max(i - j, j - i);
				if (td < rd) {
					rd = td, ra = i, rb = j;
				} else if (td == rd) {
					if (i < ra) {
						ra = i, rb = j;
					} else if (i == ra && j < rb) {
						rb = j;
					}
				}
			}
		}
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



