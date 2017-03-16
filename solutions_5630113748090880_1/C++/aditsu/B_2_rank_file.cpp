#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int n, x;
		cin >> n;
		int a[2600] = {0};
		for (int j = 0; j < 2 * n - 1; ++j) {
			for (int k = 0; k < n; ++k) {
				cin >> x;
				a[x] ^= 1;
			}
		}
		cout << "Case #" << i << ":";
		for (int j = 0; j < 2600; ++j) {
			if (a[j]) {
				cout << " " << j;
			}
		}
		cout << endl;
	}
}
