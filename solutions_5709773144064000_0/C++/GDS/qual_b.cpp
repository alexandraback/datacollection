#include <iostream>
using namespace std;

int main() {
	cout.precision(7);
	cout << fixed;
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		double cookie_rate = 2, time = 0;
		double C, F, X;
		cin >> C >> F >> X;
		double dt1 = X/cookie_rate, dt2 = C/cookie_rate + X/(cookie_rate + F);
		while (dt2 < dt1) {
			time += C/cookie_rate;
			cookie_rate += F;
			dt1 = X/cookie_rate;
			dt2 = C/cookie_rate + X/(cookie_rate + F);
		}
		time += X/cookie_rate;
		cout << "Case #" << i << ": " << time << endl;
	}
}