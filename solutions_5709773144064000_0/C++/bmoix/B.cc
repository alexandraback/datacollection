#include <iostream>
using namespace std;

int main() {
	cout.precision(7);
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		double C,F,X;
		cin >> C >> F >> X;
		double prod = 2.0;
		double t = 0.0;
		double ans = X;
		bool found = false;
		while (not found) {
			if (t+(X/prod) < ans) ans = t+(X/prod);
			else found = true;
			t += C/prod;
			prod += F;
		}

		cout << "Case #" << cas << ": " << fixed << ans << endl;
	}
	
}