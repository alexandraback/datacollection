#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXX = 10000000;



int dp[MAXX];

ll rev(ll x) {
	ll ans = 0;
	while (x) {
		ans = ans * 10 + x % 10;
		x /= 10;
	}
	return ans;
}


ll solve(ll n) {
	return dp[n];
}

queue<ll> qu;

void init() {
	for (int i = 0; i < MAXX; ++i)
		dp[i] = MAXX;
	dp[1] = 1;
	qu.push(1);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		if (x + 1 < MAXX) {
			if (dp[x + 1] > dp[x] + 1) {
				dp[x + 1] = dp[x] + 1;
				qu.push(x + 1);
			}
		}
		ll xx = rev(x);
		if (xx < MAXX) {
			if (dp[xx] > dp[x] + 1) {
				dp[xx] = dp[x] + 1;
				qu.push(xx);
			}
		}
	}
}


int main() {
	init();
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		ll n;
		cin >> n;
		cout << "Case #" << i + 1 << ":" << " " << solve(n) << "\n";
	}
	return 0;
}


