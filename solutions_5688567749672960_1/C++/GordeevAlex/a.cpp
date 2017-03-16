#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ldb;

#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

const int MAXN = 2e6 + 10;

ll rev(ll x) {
	vector<int> dig;
	while (x > 0) {
		dig.push_back(x % 10);
		x /= 10;
	}

	ll res = 0;

	forn(i, dig.size())
		res = res * 10ll + dig[i];

	return res;
}

int dp[MAXN];
int fr[MAXN];

int q[MAXN];
int b = 0, e = 0;

ll solve(ll n) {
	if (n <= 20)
		return n;

	if (n % 10 == 0)
		return solve(n - 1) + 1;

	ll tmp = n;
	int k = 0;
	while (tmp) {
		k++;
		tmp /= 10;
	}
	ll p = 1;
	forn(i, k / 2)
		p *= 10;

	ll nn = n / p * p + 1;

	ll p2 = 1;
	forn(i, k - 1)
		p2 *= 10;

	ll ans = min(n - p2 + 1, rev(nn) - p2 + 1 + 1 + (n - nn));

	return ans + solve(p2 - 1);
}

void print_path(int n) {
	if (n > 1)
		print_path(fr[n]);
	if (fr[n] != n - 1)
		cout << fr[n] << "->" << n << ' ';
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	/*memset(dp, -1, sizeof(dp));
	dp[1] = 1;
	fr[1] = 0;
	q[e++] = 1;

	while (b < e) {
		int v = q[b++];

		if (v + 1 < MAXN && dp[v + 1] == -1) {
			q[e++] = v + 1;
			dp[v + 1] = dp[v] + 1;
			fr[v + 1] = v;
		}

		int u = rev(v);

		if (u < MAXN && dp[u] == -1) {
			q[e++] = u;
			dp[u] = dp[v] + 1;
			fr[u] = v;
		}
	}
	
	//print_path(99900);*/


	int T;
	scanf("%d ", &T);
	forn(testNum, T) {
		printf("Case #%d: ", testNum + 1);

		ll n;
		cin >> n;

		ll ans = solve(n);

		//if (n < MAXN)
		//	assert(ans == dp[n]);

		cout << ans << '\n';

	}
	return 0;
}
