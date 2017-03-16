#include <iostream>
#include <cassert>
#include <string>
#include <cstdio>
#include <sstream>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : abs(x);
}

int sqr(int x) {
	return x * x;
}

int a[220];

void solve(int test) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	double sum = 0;
	for (int i = 0; i < n; ++i)
		sum += a[i];
	cout << "Case #" << test << ":";
	cout << fixed;
	cout << setprecision(8);
	for (int i = 0; i < n; ++i) {
		double left = 0.0;
		double right = 1.0;
		while (right - left > 1e-8) {
			double mid = (left + right) / 2;
			double pointsLeft = 1 - mid;
			for (int j = 0; j < n; ++j)
				if (i != j)
					pointsLeft -= max(0.0, (a[i] - a[j]) / sum + mid);
			if (pointsLeft > 0)
				left = mid;
			else
				right = mid;
		}
		cout<<" " << left * 100;
	}
	cout << endl;
}

void pre() {
}

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	ios::sync_with_stdio(false);
	pre();
	int n;
	cin >> n;
	string tmp;
	getline(cin, tmp);
	for (int i = 1; i <= n; ++i) {
		solve(i);
	}
	return 0;
}
