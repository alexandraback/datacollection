#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long solve(int e, int r, int n, const vector<int>& v)
{
	vector<long long> dp(e + 1), ndp = dp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= e; ++j) {
			for (int spent = 0; spent <= j; ++spent) {
				long long &result = ndp[min(e, j - spent + r)];
				long long res = dp[j] + (long long) spent * v[i];
				if (res > result) {
					//cout << "after #" << i << " will be " << min(e, j - spent + r) << " with " << res << endl;
					result = res;
				}
			}
		}
		dp.swap(ndp);
	}
	return *max_element(dp.begin(), dp.end());
}

int main()
{
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; ++test) {
		int e, r, n;
		cin >> e >> r >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		cout << "Case #" << test + 1 << ": " << solve(e, r, n, v) << endl;
	}
}
