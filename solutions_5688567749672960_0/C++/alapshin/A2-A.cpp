#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <set>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <climits>
#include <cmath>
#include <iomanip>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define endl '\n'
#define dbgv(arr) cout << #arr << ": "; for (int i = 0; i < (int)arr.size(); i++) cout << arr[i] << " "; cout << endl;
#define dbge(el) cout << #el << ": " << el << endl;

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< pair<int, int> > vii;

template<class T> T abs(T x) { return x > 0 ? x : -x; }

ll flip(ll a) {
	if (a % 10 == 0) {
		return a;
	}

	ll b = 0;
	while (a != 0) {
		b = 10 * b + (a % 10);
		a /= 10;
	}

	return b;
}

ll solve(ll a) {
	ll ans = 0;
	while (a != 1) {
		//dbge(a);
		//dbge(ans);
		if (a % 10 == 0) {
			a--;
			ans++;
		} else {
			ll b = flip(a / 10 * 10 + 1);
			if (b < (a / 10 * 10 + 1)) {
				ans += a - (a / 10 * 10 + 1) + 1;
				a = b;
			} else {
				a--;
				ans++;
			}
		}
	}
	return ans + 1;
}

const int maxn = 1000000 + 100;
ll cache[maxn];
ll solve2(ll a) {
	if (a == 1) return 1;
	if (a % 10 == 0) return solve2(a - 1) + 1;
	if (cache[a]) return cache[a];

	ll b = flip(a);
	if (b < a) {
		cache[a] = solve2(b) + 1;
		cache[a] = min(cache[a], solve2(a - 1) + 1);
	} else {
		cache[a] = solve2(a - 1) + 1;
	}
	return cache[a];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output", "w", stdout);
	
	ll n;
	cin >> n;
	for (int t = 1; t <= n; t++) {
		ll a;
		cin >> a;
		cout << "Case #" << t << ": " << solve2(a) << endl;
	}
	
	return 0;
}

