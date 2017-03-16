#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(7) << fixed;
	
	int t;
	cin >> t;
	for (int casenum=1; casenum<=t; casenum++) {
		double c, f, x, s, r(2.0), t(0.0);
		cin >> c >> f >> x;
		s = x / r;
		while (t <= s) {
			t += c / r;
			r += f;
			s = min(s, t + x / r);
		}
		cout << "Case #" << casenum << ": " << s << "\n";
	}
	return 0;
}
