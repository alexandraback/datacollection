#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int tests;
	int c, d, v;
	int a[200], b[200], cc[200];
	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> c >> d >> v;
		for (int i = 0; i <= v * 2; ++i) {
			cc[i] = 0;
		}
		for (int i = 0; i < d; ++i) {
			cin >> a[i];
			cc[a[i]] = 1;
		}
		for (int i = 0; i <= v; ++i) {
			b[0] = 1;
			for (int j = 1; j <= v; ++j) {
				b[j] = 0;
			}
			for (int k = 1; k <= v; ++k) {
				for (int j = v; j >= 1; --j) {
					if ((cc[k] != 0) && (k <= j)) {
						if (b[j - k] != 0) b[j] = 1;
					}
				}
			}
			bool flag = true;
			for (int j = 1; j <= v; ++j) {
				if (b[j] == 0) {
					//cout << j << ' ' << i << endl;
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << "Case #" << t << ": " << i << endl;
				break;
			}
			for (int j = 1; j <= v; ++j)
				if (b[j] == 0) {
					cc[j] = 1;
					break;
				}
		}
		// sort(a, a + d);
	}
	return 0;
}