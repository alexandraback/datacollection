#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int solve(int r, int c, int w) {
	int ans = 0;

	ans += c / w * r;
	if (w > 1) {
		int left = w - 1;
		int right = c % w;
		if (right == 0) {
			ans += left;
			return ans;
		}

		ans += w;
	}
	return ans;
}

int main() {
	int t, r, c, w;
	int input;

	cin >> t;
	vector<int> ans(t);

	for (int i = 0; i < t; i++) {
		cin >> r >> c >> w;
		ans[i] = solve(r, c, w);
	}

	for (int i = 0; i < t; i++) {
		printf("Case #%d: %d\n", i + 1, ans[i]);
	}
	return 0;
}
