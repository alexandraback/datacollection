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

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int max_N = 18;

int dp[1 << max_N];
pair <string, string> inp[max_N];

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;

		for(int i = 0; i < N; ++i)
			cin >> inp[i].first >> inp[i].second;

		memset(dp, 0, sizeof(dp));
		map<string, int> first, second;
		for (int i = 1; i < (1 << N); ++i) {
			first.clear(); second.clear();
			for (int j = 0; j < N; ++j)
				if (i & (1 << j))
					first[inp[j].first]++, second[inp[j].second]++;
			for (int j = 0; j < N; ++j)
				if (i & (1 << j))
					dp[i] = max(dp[i], dp[i ^ (1 << j)] + (first[inp[j].first] > 1 && second[inp[j].second] > 1));
		}

		cout << "Case #" << tc << ": ";
		cout << dp[(1 << N) - 1] << endl;
	}
}
