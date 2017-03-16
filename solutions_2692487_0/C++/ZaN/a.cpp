#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int a, n;
		cin >> a >> n;
		vector<int> m(n);
		for (int i = 0; i < n; ++i) {
			cin >> m[i];
		}
		sort(m.begin(), m.end());

		int best = n, added = 0;
		int i = 0;
		if (a > 1) {
			while (i < n) {
				if (m[i] < a) {
					a += m[i];
					++i;
					continue;
				}

				if (best > added + (n - i)) {
					best = added + (n - i);
				}
				++added;
				a += (a - 1);
			}

			if (best > added) {
				best = added;
			}
		}

		cout << "Case #" << test << ": " << best << endl;
	}
}
