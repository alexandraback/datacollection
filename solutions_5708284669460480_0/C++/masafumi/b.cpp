#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>

using namespace std;

double solve(int k, int l, int s, string key, string target) {
	// l = target.size();
	if (l > s) {
		return 0;
	}

	vector<int> keyboard(26, 0);
	for (int i = 0; i < key.size(); i++) {
		keyboard[key[i] - 'A']++;
	}
	for (int i = 0; i < l; i++) {
		if (keyboard[target[i] - 'A'] == 0) {
			return 0;
		}
	}


	int limit = pow(k, s);
	int all_target = 0;
	int need = 0;
	for (int i = 0; i < limit; i++) {
		int tmp = i;
		string str;
		while (tmp > 0) {
			str.push_back(key[tmp % k]);
			tmp /= k;
		}

		for (int j = str.size(); j < s; j++) {
			str.push_back(key[0]);
		}

		int n_target = 0;
		for (int x = 0; x < s; x++) {
			bool has = true;
			for (int y = 0; y < l; y++) {
				if (str[x + y] != target[y]) {
					has = false;
					break;
				}
			}
			if (has) {
				n_target++;
			}
		}
		all_target += n_target;
		need = max(need, n_target);
	}

	return 1.0 * need - 1.0 * all_target / limit;
}

int main() {
	int t, k, l, s;
	string key, target;

	cin >> t;
	vector<double> ans(t, 0.0);

	for (int i = 0; i < t; i++) {
		cin >> k >> l >> s;
		cin >> key >> target;
		ans[i] = solve(k, l, s, key, target);
	}

	for (int i = 0; i < t; i++) {
		printf("Case #%d: %.7f\n", i + 1, ans[i]);
	}
	return 0;
}
