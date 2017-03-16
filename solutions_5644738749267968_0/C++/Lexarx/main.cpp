#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define N 1000

int main() {
	int nt;
	cin >> nt;
	for (int t = 1; t <= nt; t++) {
		int n;
		cin >> n;
		double a[N], b[N];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		int dw = 0;
		sort(b, b + n);
		bool c[N];
		for (int i = 0; i < n; i++) {
			c[i] = false;
		}
		for (int i = 0; i < n; i++) {
			double m = 1;
			int mj = -1;
			for (int j = 0; j < n; j++) {
				if (!c[j] && a[j] > b[i] && a[j] < m) {
					m = a[j];
					mj = j;
				}
			}
			if (mj == -1) {
				for (int j = 0; j < n; j++) {
					if (!c[j] && a[j] < m) {
						m = a[j];
						mj = j;
					}
				}
			} else {
				dw++;
			}
			c[mj] = true;
		}
		int w = 0;
		sort(a, a + n);
		for (int i = 0; i < n; i++) {
			c[i] = false;
		}
		for (int i = 0; i < n; i++) {
			double m = 1;
			int mj = -1;
			for (int j = 0; j < n; j++) {
				if (!c[j] && b[j] > a[i] && b[j] < m) {
					m = b[j];
					mj = j;
				}
			}
			if (mj == -1) {
				for (int j = 0; j < n; j++) {
					if (!c[j] && b[j] < m) {
						m = b[j];
						mj = j;
					}
				}
				w++;
			}
			c[mj] = true;
		}
		cout << "Case #" << t << ": " << dw << " " << w << endl;
	}
	return 0;
}