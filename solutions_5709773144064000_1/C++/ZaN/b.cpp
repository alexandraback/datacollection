#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		double c, f, x;
		cin >> c >> f >> x;
		double y = x / c - 2 / f - 1;
		int n = (y < 0 ? 0 : static_cast<int>(y) + 1);
		double time = 0;
		for (int i = 0; i < n; ++i) {
			time += c / (2 + i*f);
		}
		time += x / (2 + n*f);
		cout << "Case #" << test << ": "
		     << fixed << setprecision(7) << time << endl;
	}
}
