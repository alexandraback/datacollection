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
		int a, b, c, k;
		cin >> a >> b >> c >> k;
		if (k > c) {
			cout << a * b * c << endl;
			for (int i = 0; i < a; ++i)
				for (int j = 0; j < b; ++j)
					for (int l = 0; l < c; ++l)
						cout << i + 1 << " " << j + 1 << " " << l + 1 << endl;
			continue;
		}

		if (k > b) {
			cout << a * b * k << endl;
			for (int i = 0; i < a; ++i)
				for (int j = 0; j < b; ++j)
					for (int l = 0; l < k; ++l)
						cout << i + 1 << " " << j + 1 << " " << l + 1 << endl;
			continue;
		}

		if (k > a) {
			cout << a * b * k << endl;
			for (int i = 0; i < a; ++i)
				for (int j = 0; j < b; ++j)
					for (int l = 0; l < k; ++l) {
						int t = (j + l) % c;
						cout << i + 1 << " " << j + 1 << " " << t + 1 << endl;
					}
			continue;
		}

		cout << a * b * k << endl;
		for (int i = 0; i < a; ++i)
			for (int j = 0; j < b; ++j)
				for (int l = 0; l < k; ++l) {
					int t = (i + j + l) % c;
					cout << i + 1 << " " << j + 1 << " " << t + 1 << endl;
				}
		continue;
	}

	return 0;
}