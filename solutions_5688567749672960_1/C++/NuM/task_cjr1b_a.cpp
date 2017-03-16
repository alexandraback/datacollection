#pragma comment(linker, "/stack:32000000")
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <cassert>
#include <string.h>
#include <ctime>

#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define sqr(x) (x)*(x)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

const int maxn = 1000010;

ll calc(ll n) {
	if (n == 1) return 1;
	ll x = n;
	ll r = 0;
	int len = 0;
	while (x) {
		++len;
		r = r * 10 + x % 10;
		x /= 10;
	}
	ll ten = 1;
	forn(iter, (len+1) / 2) ten *= 10;
	ll to = n / ten * ten + 1;
	if (to < n) return n-to + calc(to);
	if (to == n && r < n) return 1 + calc(r);
	return 1 + calc(n - 1);
}


int rev(int x) {
	int res = 0;
	while (x) res = res * 10 + x % 10, x /= 10;
	return res;
}

int dp[maxn];

void solve(int n) {
	printf("%d\n", dp[n]);
}



//int calc(int x) {
//	int ans = 1;
//	while (x > 1) {
//		++ans;
//		int r = rev(x);
//		if (x % 10 == 1 && r < x) x = r;
//		else x = x-1;
//	}
//	return ans;
//}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//int cc = 0;
	//forn(i, maxn) dp[i] = i;
	//for(int i = 1; i < maxn; ++i) {
	//	int r = rev(i);
	//	if (r > i && r < maxn) dp[r] = min(dp[r], dp[i] + 1);
	//	if (i + 1 < maxn) dp[i + 1] = min(dp[i + 1], dp[i] + 1);
	//}
	//for (int i = 1; i < maxn; ++i) if (calc(i) != dp[i])
	//	printf("FAIL!!! %d %d %d\n", i, calc(i), dp[i]);//, exit(0);
	////for (int i = 1; i < maxn; ++i) if (dp[i] != dp[i-1] + 1) printf("%d\n", i);
	//return 0;

	int T; scanf("%d", &T);
	for (int tn = 1; tn <= T; ++tn) {
		ll x; cin >> x;
		printf("Case #%d: ", tn);
		ll res = calc(x);
		//solve(x);
		cout << res << endl;
	}
	return 0;
}