#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <complex>
#include <ctime>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; ++t) {
		cout << "Case #" << t + 1 << ": ";
		long long n;
		cin >> n;
		long long m;
		cin >> m;
		if (m <= ((long long)1 << (n - 2))) 
			cout << "POSSIBLE" << endl;
		else {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		if (m == ((long long)1 << (n - 2))) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j)
					cout << (i < j);
				cout << endl;
			}
			continue;
		}
		vector<long long> a;
		for (; m > 0; m /= 2)
			a.push_back(m & 1);
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n - 1; ++j)
				cout << (i < j);
			if (i > 0 && i < n && a[i - 1])
				cout << 1;
			else
				cout << 0;
			cout << endl;
		}
	}

	return 0;
}