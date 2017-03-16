#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;

int main() {
	int nt, it;

	cin >> nt;
	for (it = 1; it <= nt; it++) {
		int n, i, x = 0, s[200] = {}, s1 = 101, s2 = 101;

		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> s[i];
			x += s[i];
			if (s[i] <= s2) {
				if (s[i] <= s1) {
					s2 = s1;
					s1 = s[i];
				} else {
					s2 = s[i];
				}
			}
		}

		cout << "Case #" << it << ':';
		for (i = 0; i < n; i++) {
			// s[i] + x * y[i] >= otrs mazākais + x * (1. - y[i])
			int t = (s[i] == s1 ? s2 : s1);
			
			// y[i] = (t + x * 1. - s[i]) / (x + x)
// 			cout << ' ' << ld(t + x - s[i]) / (x + x) * 100;

			ld lo = s[i], hi = s[i] + x, mi;
			int j, k;

			for (j = 0; j < 100; j++) {
				mi = (lo + hi) / 2;

				ld t = 0;

				for (k = 0; k < n; k++) {
					t += max(ld(0), ld(mi - s[k]) / x);
				}
				(t > 1 ? hi : lo) = mi;
			}
			cout << ' ' << setprecision(9) << fixed << ld(mi - s[i]) / x * 100;
		}
		cout << '\n';
	}
	
	return 0;
}
