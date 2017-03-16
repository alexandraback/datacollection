#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int c, d, v;
vector<int> coins(5);

int solve() {
	vector<bool> price(v + 1, false);
	int limit = 1 << d;

	for (int i = 0; i < limit; i++) {
		int value = 0;
		for (int j = 0; j < d; j++) {
			if ((i >> j) & 1) {
				value += coins[j];
			}
		}
		if (value <= v) {
			price[value] = true;
		}

	}

	int add = 0;
	for (int i = 1; i <= v; i++) {
		if (price[i]) {
			continue;
		}
		add++;

		for (int j = 0; j <= v; j++) {
			if (price[j] && j + i >= v) {
				price[j + i] = true;
			}
		}
	}

	return add;
}

int main() {
	int t;
	cin >> t;
	vector<int> ans(t);

	for (int i = 0; i < t; i++) {
		cin >> c >> d >> v;
		for (int j = 0; j < d; j++) {
			cin >> coins[j];
		}

		ans[i] = solve();
	}

	for (int i = 0; i < t; i++) {
		printf("Case #%d: %d\n", i + 1, ans[i]);
	}
	return 0;
}
