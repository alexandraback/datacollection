#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	int tests, n;
	int a[10];
	int sum;
	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> n;
		cout << "Case #" << t << ": ";
		if (n == 0) {
			cout << "INSOMNIA" << endl;
			continue;
		}
		for (int j = 0; j < 10; ++j) {
			a[j] = 0;
		}
		sum = 0;
		int x = n;
		while (true) {
			int xx = x;
			while (xx > 0) {
				int yy = xx % 10;
				xx /= 10;
				if (a[yy] == 0) {
					a[yy] = 1;
					sum += 1;
				}
			}
			if (sum == 10) {
				cout << x << endl;
				break;
			}
			x += n;
		}
	}
	return 0;
}