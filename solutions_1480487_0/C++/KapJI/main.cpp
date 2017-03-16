#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

const int ITERS = 100;
const double EPS = 1e-12;

int n, sum;
vector<int> a;

bool check(int k, double x) {
	double need = a[k] + sum * x;
	double votes = 0;
	for (int i = 0; i < n; ++i) {
		if (i != k) {
			votes += max(0.0, (need - a[i]) / sum);
		}
	}
	return votes + x >= 1.0;
}

void solve() {
	scanf("%d", &n);
	a.resize(n);
	sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 0; i < n; ++i) {
		double l = 0, r = 1, x;
		for (int j = 0; j < ITERS; ++j) {
			x = (l + r) / 2;
			if (check(i, x)) {
				r = x;
			} else {
				l = x;
			}
		}
		cout << fixed << setprecision(7) << l * 100 << ' ';
		//printf("%0.7lf ", l * 100);
	}
	printf("\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
