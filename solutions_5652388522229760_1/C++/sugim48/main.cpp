#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

ll solve(ll N) {
	if (!N) return -1;
	vector<bool> a(10);
	for (int i = 1; ; i++) {
		ll x = i * N;
		for (; x; x /= 10)
			a[x % 10] = true;
		bool ok = true;
		for (bool x: a)
			if (!x)
				ok = false;
		if (ok) return i * N;
	}
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int N; cin >> N;
		ll ans = solve(N);
		printf("Case #%d: ", t);
		if (ans == -1) cout << "INSOMNIA";
		else cout << ans;
		cout << endl;
	}
}
