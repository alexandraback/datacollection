#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int num;
	double C, F, X;
	cin >> num;
	cout << fixed;

	for (int i = 0; i < num; i++) {
		double ans = 0, rate = 2;
		cin >> C >> F >> X;

		while (X / rate > X / (rate + F) + (C / rate)) {
			ans += C / rate;
			rate += F;
		}
		ans += X / rate;
		cout << "Case #" << std::setprecision(7) << i + 1 << ": " << ans << "\n";
	}

	return 0;
}