#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

int main() {
	int ncases;

	cin >> ncases;

	for (int t = 1; t <= ncases; t++) {
		int result = 0;

		int c, d, v;

		cin >> c >> d >> v;

		vector<int> denoms;

		for (int i = 0; i < d; i++) {
			int x;
			cin >> x;
			denoms.push_back(x);
		}

		assert(c == 1);

		vector<bool> can_make(v + 1);

		can_make[0] = true;

		for (int coin : denoms) {
			for (int i = v; i >= 0; i--) {
				if (can_make[i] && (i + coin) <= v) {
					can_make[i + coin] = true;
				}
			}
		}

		for (int i = 1; i <= v; i++) {
			if (!can_make[i]) {
				cerr << "Adding: " << i << endl;
				result++;

				for (int j = v; j >= 0; j--) {
					if (can_make[j] && (j + i) <= v) {
						can_make[j + i] = true;
					}
				}
			}
		}

		cout << "Case #" << t << ": " << result << endl;
	}

	return 0;
}
