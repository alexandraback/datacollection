#include <iostream>

using namespace std;

double tim(int k, double c, double f, double x) {
	double res = 0;
	for (int i = k - 1; i >= 0; i--) {
		res += 1 / (2 + i * f);
	}
	res *= c;
	res += x / (2 + k * f);
	return res;
}

double ans(double c, double f, double x) {
	int ll = 0;
	int rr = 10000000;
	while (rr - ll > 2) {
		int m1 = ll + (rr - ll) / 3;
		int m2 = ll + 2 * (rr - ll) / 3;
		if (tim(m1, c, f, x) < tim(m2, c, f, x)) {
			rr = m2;
		} else {
			ll = m1;
		}
	}
	return min(tim(ll, c, f, x), min(tim(ll + 1, c, f, x), tim(ll + 2, c, f, x)));
}

int t;
double c, f, x;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cout.precision(20);
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> c >> f >> x;
		cout << "Case #" << k + 1 << ": " << ans(c, f, x) << endl;
	}
}