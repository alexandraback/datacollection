#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <bitset>

using namespace std;

const int N_MAX = 1001;

int solve(int t) {
// cout << "----------- case " << t << "----------" << endl;
	int n;
	cin >> n;

	vector<int> bff(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> bff[i];
	}

	vector<bitset<N_MAX>> circles(n + 1);
	vector<int> last1 (n + 1, -1);
	vector<int> last2 (n + 1, -1);
	vector<bool> is_circle(n + 1, false);

	for (int i = 1; i <= n; i++) {
		auto target = i;
		bitset<N_MAX> circle;
		int l1 = -1;
		int l2 = -1;
		do {
			circle.set(target);
// cout << target << " ";
			l2 = l1;
			l1 = target;
			target = bff[target];
		} while (circle[target] == 0);
// cout << endl;
		circles[i] = circle;
		last1[i] = l1;
		last2[i] = l2;
		if (target == i) {
			is_circle[i] = true;
		}
	}

	unsigned long ans = 0;
	for (int i = 1 ; i <= n; i++) {
		if (is_circle[i]) {
			ans = max(ans, circles[i].count());
		}
		for (int j = 1 ; j <= n; j++) {
			auto common = circles[i] & circles[j];
			if ((common.count() == 1 && common[last1[i]] == 1) ||
				(common.count() == 2 && common[last1[i]] == 1 && common[last2[i]] == 1 && last1[i] == last2[j] && last2[i] == last1[j])) {
				ans = max(ans, (circles[i] | circles[j]).count());
			}
		}
	}

// cout << "ans " << ans << endl;
	return ans;
}

int main() {
	int t;

	cin >> t;
	vector<int> ans(t, 0);

	for (int i = 0; i < t; i++) {
		ans[i] = solve(i + 1);
	}

	for (int i = 0; i < t; i++) {
		printf("Case #%d: %d\n", i + 1, ans[i]);
	}
	return 0;
}
