#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int solve(int a, int n, vector<int>& sizes)
{
	sort(sizes.begin(), sizes.end());
	int maxsize = sizes.back();
	vector<int> dp(maxsize + 2, -1);
	for (int add = 0, i = 0; true; ++add) {
		for (; i < n; ++i) {
			if (a > sizes[i]) a += sizes[i];
			else break;
		}
		dp[a > maxsize ? maxsize + 1 : a] = add;
		if (a > maxsize || a == 1) break;
		a += a - 1;
	}
	int result = numeric_limits<int>::max();
	for (int s = 1; s <= maxsize + 1; ++s) {
		if (dp[s] >= 0) {
			result = min(result, dp[s] + (sizes.end() - lower_bound(sizes.begin(), sizes.end(), s)));
		}
	}
	return result;
}

int main()
{
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int a, n;
		cin >> a >> n;
		vector<int> sizes(n);
		for (int i = 0; i < n; ++i) {
			cin >> sizes[i];
		}
		cout << "Case #" << test << ": " << solve(a, n, sizes) << endl;
	}
}
