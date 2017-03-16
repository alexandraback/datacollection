#include <iostream>
using namespace std;
typedef long double ld;

int A[300];

int main() {
	int T, C = 1, n;
	cin >> T;
	while (T-- && cin >> n) {
		int s = 0;
		for (int i = 0; i < n && cin >> A[i]; ++i)
			s += A[i];

		cout << "Case #" << C++ << ":";

		for (int i = 0; i < n; ++i) {
			ld mn = 0, mx = 1;
			while (mx - mn > 1e-9) {
				ld md = (mn + mx)/2.0;
				ld y = A[i] + s * md, r = 0;
				for (int j = 0; j < n; ++j)
					r += max((ld)0, (y - A[j])/s);

				if (r < 1) {
					mn = md;
				} else {
					mx = md;
				}
			}

			cout.setf(ios::fixed);
			cout.precision(7);
			cout << " " << mx * 100.0;
		}
		cout << endl;
	}
}
