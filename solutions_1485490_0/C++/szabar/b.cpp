#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <deque>
#include <cstdio>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<double> vd;

ll a[1000];
ll at[1000];
ll b[1000];
ll bt[1000];

ll count(ll * my_a, ll * my_at, ll * my_b, ll * my_bt, int x, int y, int type_no) {
	ll taken = 0;
	ll avail = my_a[type_no];
	for (int i = x; i <= y; ++i) {
		if (my_at[type_no] == my_bt[i]) {
			ll t = 0;
			if (avail < my_b[i]) {
				t += avail;
				my_b[i] -= avail;
				avail = 0;
			} else {
				avail -= my_b[i];
				t += my_b[i];
				my_b[i] = 0;
			}
			taken += t;
		}
	}
	return taken;
}

ll get_max(int n, int m) {
	if (n == 1) {
		return count(a, at, b, bt, 0, m, 0);
	} else if (n == 2) {
		ll mx = 0;
		for (int i = 0; i <= m; ++i) {
			ll z = count(a, at, b, bt, 0, i, 0) + count(a, at, b, bt, i, m, 1);
			mx = max(z, mx);
		}
		return mx;
	} else if (n == 3) {
		ll mx = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = i; j < m; ++j) {
				ll a_copy[1000];
				ll at_copy[1000];
				ll b_copy[1000];
				ll bt_copy[1000];
				for(int k = 0; k < n; ++k){
					a_copy[k] = a[k];
					at_copy[k] = at[k];
				}
				for(int k = 0; k < m; ++k){
					b_copy[k] = b[k];
					bt_copy[k] = bt[k];
				}
				ll z = count(a_copy, at_copy, b_copy, bt_copy, 0, i, 0) + count(a_copy, at_copy, b_copy, bt_copy, i, j, 1)
						+ count(a_copy, at_copy, b_copy, bt_copy, j, m, 2);
				mx = max(z, mx);
//				printf("i: %d, j: %d, z: %lld\n", i, j, z);
			}
		}
		return mx;
	}
	return 0;
}

void run() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		a[i] = x;
		at[i] = y;
	}
	for (int i = 0; i < m; ++i) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		b[i] = x;
		bt[i] = y;
	}
	printf("%lld\n", get_max(n, m));
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i + 1);
		run();
	}
}
