#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
	int _n;
	cin >> _n;
	cout << fixed << setprecision(8);
	for (int n = 1; n <= _n; ++n) {
		cout << "Case #" << n << ": ";
		double c, f, x;
		cin >> c >> f >> x;
		double current_v = 2, ans = x / current_v, current_time = 0;
		for (int i = 1; i <= 1e5 + 100; ++i) {
			current_time += (c / current_v);
			current_v += f;
			ans = min(ans, x / current_v + current_time);
		}
		cout << ans << '\n';
	}
	return 0;
}
