#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const long double eps = 1e-12;

int n;
long double d;
long double t[2001], x[2001];

inline long double sqr(long double x) {
	return x * x;
}

long double calc(long double a) {
	long double st = 0, v = 0, t0 = 0;
	if (n == 0) {
		return sqrt(2 * d / a);
	} else {
		for (int i = 1; i < n; i++) {
			long double s = st + v * (t[i] - t0) + 0.5 * a * sqr(t[i] - t0);
			//printf("%lf\n", s);
			if (s > x[i]) {
				if (i < n - 1) {
					//printf("%lf\n", v);
					//cout << sqrt(2.0 * a * (x[i] - st) + sqr(v)) << endl;
					v = min((x[i + 1] -  x[i]) / (t[i + 1] - t[i]), sqrt(2.0 * a * (x[i] - st) + sqr(v)));
				}
				st = x[i];
				t0 = t[i];
			}
		}
		if (abs(st - d) < eps) {
			return t0;
		} else {
			//cout << v << endl;
			return t0 + (-v + sqrt(sqr(v) + 2.0 * a * (d - st))) / a;
		}
	}
}

int main() {
	int test;
	cin >> test;
	int a;
	cout.precision(10);
	cout << fixed;
	for (int tt = 1; tt <= test; tt++) {
		cout << "Case #" << tt << ":" << endl;
		cin >> d;
		cin >> n >> a;
		for (int i = 0; i < n; i++) {
			cin >> t[i] >> x[i];
		}
		if (x[0] > d) {
			n = 0;
		} else {
			for (int i = 1; i < n; i++) {
				if (x[i] > d) {
					n = i + 1;
					t[i] = t[i - 1] + (t[i] - t[i - 1]) / (x[i] - x[i - 1]) * (d - x[i - 1]);
					x[i] = d;
				}
			}
		}
		//printf("%lf %lf\n", t[n - 2], x[n - 2]);
		for (int i = 0; i < a; i++) {
			long double ai;
			cin >> ai;
			long double ans = calc(ai);
			cout << ans << endl;
		}
	}
}