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


ll solve1(ll n) {
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

ll pw[100];


ll solve(ll n) {
	if (n < 20)
		return n;
	ll ans = 10;
	int now = 2;
	pw[0] = 1;
	for (int i = 1; i < 15; ++i)
		pw[i] = pw[i - 1] * 10;
	ll xx = 10;
	while (xx * 10 <= n) {
		if (now % 2 == 0)
			ans += pw[now / 2] - 1 + pw[now / 2];
		else
			ans += pw[now / 2] - 1 + pw[now / 2 + 1];
		++now;
		xx *= 10;
	}

	if (xx == n)
		return ans;

	int n0 = 0;
	ll n2 = n;
	while (n2 % 10 == 0)
		n2 /= 10, ++n0;


	int nn = 0;
	ll ans2 = ans;
	ans = ans + n - xx;

	if (n2 * 2 >= now)
		--n, ++ans2; 

	while (n) {
		if ((nn + 1) * 2 <= now)
			ans2 += (n % 10) * pw[nn];
		else
			ans2 += (n % 10) * pw[now - 1 - nn];
		n /= 10;
		++nn;
	}
	return min(ans, ans2);
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


