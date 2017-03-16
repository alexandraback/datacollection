#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int solve(vector<int> &cake) {

	int cake_max = 0;
	for (int i = 1000; i > 0; i--) {
		if (cake[i] != 0) {
			cake_max = i;
			break;
		}
	}

	int ans = cake_max;
	for (int i = 2; i < cake_max; i++) {
		int special = 0;
		for (int j = i + 1; j <= cake_max; j++) {
			special += (1 * ceil(1.0 * j / i) - 1 )* cake[j];
		}
		ans = min(ans, special + i);
	}

	return ans;
}

int main() {
	int t, d, p;

	cin >> t;
	vector<int> ans(t, 0);

	for (int i = 0; i < t; i++) {
		int d;
		cin >> d;

		vector<int> cake(1001, 0);

		for (int j = 0; j < d; j++) {
			cin >> p;
			cake[p]++;
		}

		ans[i] = solve(cake);
	}

	for (int i = 0; i < t; i++) {
		printf("Case #%d: %d\n", i + 1, ans[i]);
	}
	return 0;
}
