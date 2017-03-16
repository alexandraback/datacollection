#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

double solve() {
	double c, f, x;
	cin >> c >> f >> x;
	double ans = x / 2, sum = 0, m = 0;
	while (1) {
		sum += c / (2 + m * f);
		m++;
		double tmp = sum + x/(2+m*f);
		if (tmp > ans) break;
		ans = tmp;
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": " << fixed << setprecision(7) << solve() << endl;
	}
}