#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int a, b;
		cin >> a >> b;
		double c = 1;
		double best = b + 2;
		for (int j = 0; j <= a; ++j) {
			if (j > 0) {
				double p;
				cin >> p;
				c *= p;
			}
			double x = b - a + 2 * (a - j) + 1;
			x = x * c + (x + b + 1) * (1 - c);
			best = min(best, x);
		}
		cout << "Case #" << i << ": " << best << setprecision(15) << endl;
	}
}
