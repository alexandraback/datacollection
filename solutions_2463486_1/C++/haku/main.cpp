#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <list>
#include <iterator>
#include <functional>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cassert>
#include <climits>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

const ll M = 1000ll * 1000ll * 1000ll * 1000ll * 100ll;
int t;
vector<ll> a;

bool isPalindrome(ll x) {
	ll revX = 0;
	ll bufX = x;
	while (bufX > 0)
		revX = revX * 10 + bufX % 10, bufX /= 10;
	return x == revX;
}

ll solve() {
	ll le, ri;
	cin >> le >> ri;
	return distance(lower_bound(a.begin(), a.end(), le), upper_bound(a.begin(), a.end(), ri));
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (ll i = 1; i * i <= M; ++i)
		if (isPalindrome(i) && isPalindrome(i * i))
			a.pb(i * i);
	cin >> t;
	for (int k = 0; k < t; ++k)
		cout << "Case #" << (k + 1) << ": " << solve() << "\n";
	return 0;
}