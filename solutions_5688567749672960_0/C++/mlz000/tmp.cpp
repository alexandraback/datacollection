#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[20];
LL p[15], b[15];
int main() {
	int T;
	p[1] = 1;
	for (int i = 2; i <= 15; ++i)	p[i] = p[i - 1] * 10;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		printf("Case #%d: ", tt);
		LL ans = 0;
		LL n;
		cin >> n;
		while (n != 0) {
			if (n % 10 == 0)	--n, ++ans;
			LL t = n;
			int cnt = 0;
			while (t)	a[++cnt] = t % 10, t /= 10;
			for (int i = 1; i <= cnt - i + 1; ++i) {
				if (i == 1) {
					ans += a[i] - 1, a[i] = 1;
				}
				else {
					ans += p[i] * a[i];
					a[i] = 0;
				}
			}
			bool ok = 0;
			for (int i = 1; i <= cnt - i + 1; ++i)
				if (a[cnt - i + 1] > a[i] && i != cnt - i + 1) {
					ok = 1;
					break;
				}
			if (ok) {
				for (int i = 1; i <= cnt - i + 1; ++i)	swap(a[i], a[cnt - i + 1]);
				++ans;
			}
			LL now = 0;	
			for (int i = cnt; i >= 1; --i)	now = now * 10 + a[i];
			if (cnt == 1)	ans += now, now = 0;
			else {
				if (!ok) {
					ans += 2;
					now -= 2;
				}
			}
			n = now;
		}
		printf("%d\n", ans);
	}
	return 0;
}
