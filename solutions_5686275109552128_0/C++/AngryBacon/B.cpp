#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

void solve()
{
	int n;
	cin >> n;
	vector<int> vec;
	int maxv = 0;
	for(int i = 0; i < n; ++ i) {
		int x;
		cin >> x;
		maxv = max(maxv, x);
		vec.push_back(x);
	}

	int ret = maxv;
	for(int value = 1; value <= maxv; ++ value) {
		int cur = value;
		for(int i = 0; i < n; ++ i) {
			if (vec[i] > value) {
				cur += (vec[i] - 1) / value;
			}
		}
		ret = min(ret, cur);
	}
	cout << ret << endl;
}

int main()
{
	//freopen("B-small-attempt0.in", "r", stdin); freopen("B-small-attempt0.out", "w", stdout);
	freopen("B-small-attempt1.in", "r", stdin); freopen("B-small-attempt1.out", "w", stdout);
	//froepen("B-large.in", "r", stdin); freopen("B-large.out", stdout);
	int test_case;
	cin >> test_case;
	for(int i = 0; i < test_case; ++ i) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
