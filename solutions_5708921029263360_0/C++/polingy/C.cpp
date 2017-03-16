#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>

#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>
#include <tuple>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

map <pii, int> num1, num2, num3;
vector < vector<int> > ans;

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int J, P, S, K;
		cin >> J >> P >> S >> K;

		num1.clear();
		num2.clear();
		num3.clear();
		ans.clear();

		printf("Case #%d: ", tc);

		for (int i = 1; i <= J; ++i)
			for (int j = 1; j <= P; ++j)
				for (int k = 1; k <= S; ++k) {
					if (num1[{i, j}] < K && num2[{i, k}] < K && num3[{j, k}] < K) {
						num1[{i, j}]++;
						num2[{i, k}]++;
						num3[{j, k}]++;

						ans.push_back({i, j, k});
					}
				}

		cout << ans.size() << endl;
		for (auto &a : ans) {
			for (auto &b : a)
				cout << b << ' ';
			cout << endl;
		}
	}
}
