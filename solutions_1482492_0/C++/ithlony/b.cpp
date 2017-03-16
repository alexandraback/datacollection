#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const int maxn = 2200;
const double eps = 1e-8;

double h, t[maxn], x[maxn], a;
int n, ac;

double s(double v, double a, double t) {
	return v * t + 0.5 * a * t * t;
}

double f(double v, double a, double S, double t) {
	double l = 0, r = v;
	while (r - l > eps) {
		double m0 = l + (r - l) / 3;
		double m1 = l + (r - l) / 3 * 2;
		double f0 = v + (t - sqrt((S - m0 * t) * 2 / a)) * a;
		double f1 = v + (t - sqrt((S - m1 * t) * 2 / a)) * a;
		if (f0 > f1) {
			r = m1;
		} else {
			l = m0;
		}
	}
	return sqrt((S - l * t) * 2 / a);
}

int main() {
	int ncase;
	cin >> ncase;
	for (int c = 1; c <= ncase; ++c) {
		cin >> h >> n >> ac;
		t[0] = x[0] = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> t[i] >> x[i];
		}
		cout << "Case #" << c << ":" << endl;
		for (int i = 1; i <= ac; ++i) {
			cin >> a;
			double v = 0, xx = 0;
			int last = 0;
			for (int j = 1; j <= n && x[j] < h + eps; ++j) {
				last = j;
				double dx = x[j] - xx, dt = t[j] - t[j - 1];
				if (xx + s(v, a, dt) > x[j]) {
					double t0 = f(min(v, dx / dt), a, dx, dt);
					xx = x[j];
					v = v + a * t0;
				} else {
					xx = xx + s(v, a, dt);
					v = v + a * dt;
				}
			}
			double at = t[last];
			if (last == n) {
				at += (sqrt(v * v + 2 * a * (h - xx)) - v) / a;
			} else {
				at = max(at + (sqrt(v * v + 2 * a * (h - xx)) - v) / a, t[last] + (t[last + 1] - t[last]) / (x[last + 1] - x[last]) * (h - x[last]));
			}
			printf("%.8lf\n", at);
		}
	}
	return 0;
}
