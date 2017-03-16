#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int tests, n;
	string str;
	int a[10000][100];
	int b[10000];
	int sum;
	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> n;
		cout << "Case #" << t << ": ";
		for (int i = 1; i <= 2500; ++i) {
			b[i] = 0;
		}
		for (int i = 0; i < 2 * n - 1; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
				++b[a[i][j]];
			}
		}
		int count = 0;
		for (int i = 1; i <= 2500; ++i) {
			if (b[i] % 2 == 1) {
				if (count == n - 1) {
					cout << i << endl;
				} else {
					cout << i << " ";
				}
				++count;
			}
		}
	}
	// sort(a, a + d);
	return 0;
}