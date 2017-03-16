#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool loose(int n, int idx, vector<int>& a, double add, double lev)
{
	double res = 0.0;
	for (int i = 0; i < n; ++i) if (i != idx) {
		if (a[i] < lev) {
			res += lev - a[i];
		}
	}
	return res < add;
}

int main()
{
	cout.precision(20);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		cout << "Case #" << test << ": ";
		int x = accumulate(a.begin(), a.end(), 0);
		for (int i = 0; i < n; ++i) {
			double l = 0.0, r = 100.0;
			while (r - l > 1e-9) {
				double c = (l + r) / 2;
				if (loose(n, i, a, (100 - c) / 100 * x, a[i] + c / 100 * x)) {
					l = c;
				} else {
					r = c;
				}
			}
			cout << r << " ";
		}
		cout << endl;
	}
}
