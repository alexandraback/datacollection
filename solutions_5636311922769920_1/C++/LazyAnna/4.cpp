#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	int tests, k, c, s;
	int a[10];
	int sum;
	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> k >> c >> s;
		cout << "Case #" << t << ": ";
		if (k == 1) {
			cout << 1 << endl;
			continue;
		}
		if (c == 1) {
			if (s == k) {
				for (int i = 1; i <= k; ++i) {
					cout << i;
					if (i < k) {
						cout << " ";
					} else {
						cout << endl;
					}
				}
			} else {
				cout << "IMPOSSIBLE" << endl;
			}
		} else {
			if (s < k - 1) {
				cout << "IMPOSSIBLE" << endl;
			} else {
				for (int i = 2; i <= k; ++i) {
					cout << i;
					if (i < k) {
						cout << " ";
					} else {
						cout << endl;
					}
				}				
			}
		}
	}
	return 0;
}