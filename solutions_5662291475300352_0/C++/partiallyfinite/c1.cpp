#include <iostream>

using namespace std;

int t, n, d, h, m, c;
double s[10], r[10];

int main ()
{
	cin >> t;
	for (int i = 0; i ++< t;) {
		cin >> n;
		c = 0;
		for (int j = n; j --> 0;) {
			cin >> d >> h >> m;
			for (int k = h; k --> 0;) s[c] = d, r[c++] = 1.0 / (m + k);
		}
		if (r[0] > r[1]) swap(r[0], r[1]), swap(s[0], s[1]);
		cout << "Case #" << i << ": ";
		double a = *s + *r * (s[0] - s[1] + 360) / (r[1] - r[0]);
		if (a <= 360 && a > *s) cout << 1;
		else cout << 0;
		cout << '\n';
		// s1 + tr1 + 360o = s2 + tr2
		// s1 - s2 + 360o = t(r2 - r1)
		// t = (s1 - s2 + 360o) / (r2 - r1)
	}
}

