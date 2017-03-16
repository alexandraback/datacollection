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
double a[N], b[N];

int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-out.txt", "w", stdout);	
	int T, ca = 0;
	for (scanf("%d", &T); T--; ) {
		int n; scanf("%d", &n);
		rep(i, n) scanf("%lf", &a[i]);
		rep(i, n) scanf("%lf", &b[i]);
		sort(a, a + n), sort(b, b + n);
		int r0 = n, pos = 0;
		rep(i, n) {
			while (pos < n && b[pos] < a[i]) {
				++pos;
			}
			if (pos < n) {
				++pos;
				--r0;
			}
		}
		int r1 = 0;
		rep(i, n) {
			int s = n - i;
			bool f = 1;
			rep(j, s) {
				if (a[i + j] < b[j]) {
					f = 0;
					break;
				}
			}
			if (f) {
				r1 = s;
				break;
			}
		}
		printf("Case #%d: %d %d\n", ++ca, r1, r0);
	}
	return 0;
}

