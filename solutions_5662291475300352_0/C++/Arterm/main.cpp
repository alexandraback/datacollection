#include <bits/stdc++.h>

using namespace std;

#define long long long

int n;

struct Hiker {
	int a, b;
	Hiker():a(0), b(0) {}
	Hiker(int a, int b) : a(a), b(b) {}

	long prod() {
		return 1ll * a * b;
	}
};

vector<Hiker> a;

void read() {
	cin >> n;
	a.clear();
	for (int i = 0; i < n; ++i) {
		int d, h, m;
		cin >> d >> h >> m;
		for (int j = m; j < m + h; ++j)
			a.emplace_back(d, j);
	}
}

int kill() {
	if (a.size() <= 1)
		return 0;
	long g = __gcd(a[0].b, a[1].b);
	a[0].b /= g;
	a[1].b /= g;
	long x = a[0].prod();
	long y = a[1].prod();
	if (x % 360 == y % 360)
		return 1;
	return 0;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		read();
		cout << "Case #" << i << ": ";
		cout << kill() << endl;
	}
	return 0;
}