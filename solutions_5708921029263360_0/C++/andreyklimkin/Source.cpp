#include <iostream>
#include <algorithm>
#include <assert.h>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <time.h>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
#define mp make_pair
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

struct abc {
	int a, b, c;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll it;
	cin >> it;
	for (int k1 = 0; k1 < it; ++k1) {
		cout << "Case #" << k1 + 1 << ": ";
		vector<abc> res;
		int maxa, maxb, maxc;
		int k;
		cin >> maxa >> maxb >> maxc >> k;
		map<pii, int> ab, bc, ac;
		for (int a = 1; a <= maxa; ++a) {
			for (int b = 1; b <= maxb; ++b) {
				for (int c = 1; c <= maxc; ++c) {
					if (ab[{a, b}] < k && ac[{a, c}] < k && bc[{b, c}] < k) {
						res.push_back({ a, b, c });
						++ab[{a, b}], ++ac[{a, c}], ++bc[{b, c}];
					}
				}
			}
		}
		cout << res.size() << endl;
		for (auto p : res) {
			cout << p.a << " " << p.b << " " << p.c << endl;
		}
	}
}