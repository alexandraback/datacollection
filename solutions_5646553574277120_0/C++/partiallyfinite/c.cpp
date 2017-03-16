#include <iostream>
#include <algorithm>

using namespace std;

int t, c, d, v, a[30];
bool p[101];

int main ()
{
	cin >> t;
	for (int i = 0; i ++< t;) {
		cin >> c >> d >> v;
		for (int j = 0; j < d; ++j) cin >> a[j];
		sort(a, a + d);
		fill(p, p + 101, 0);
		p[0] = 1;
		int t = 0;
		for (int i = d; i --> 0;) {
			for (int j = v; j >= a[i]; --j) if (!p[j] && p[j-a[i]]) p[j] = 1;
		}
		for (int i = 1; i <= v; ++i) {
			bool y = 0;
			for (int j = v; j >= i; --j) if (!p[j] && p[j-i]) {
				p[j] = 1;
				y = 1;
			}
			if (y) ++t;
		}
		cout << "Case #" << i << ": " << t << '\n';
	}
}

