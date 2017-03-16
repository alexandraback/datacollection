#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[20], t[20];
long long f[20][10][10];
long long b[20] = {1};
int digit(long long x, int i) {
	return x / b[i] % 10;
}
void solve() {
	scanf("%s%s", s, t);
	int n = strlen(s);
	long long ans = b[10], ans1, ans2;
	for (int i = 0; i < b[n]; ++i) {
		for (int j = 0; j < b[n]; ++j) {
			bool fs = true, ft = true;
			for (int a = 0; a < n; ++a) {
				if (s[a] == '?') continue;
				if (s[a] != digit(i, n - a - 1) + '0') {
					fs = false;
					break;
				}
			}
			for (int a = 0; a < n; ++a) {
				if (t[a] == '?') continue;
				if (t[a] != digit(j, n - a - 1) + '0') {
					ft = false;
					break;
				}
			}
			if (fs && ft) {
				if (ans > abs(i - j)) {
					ans = abs(i - j);
					ans1 = i, ans2 = j;
					// printf("%lld %lld %lld\n", ans, ans1, ans2);
				}
			}
		}
	}
	for (int a = 0; a < n; ++a) s[a] = digit(ans1, n - a - 1) + '0';
	for (int a = 0; a < n; ++a) t[a] = digit(ans2, n - a - 1) + '0';	
	printf("%s %s\n", s, t);
}
int main() {
	for (int i = 1; i < 19; ++i) b[i] = b[i - 1] * 10;
	// freopen("in", "r", stdin);
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}
