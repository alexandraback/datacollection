#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

typedef tuple<int, int, ll> tuple_t;

struct dhm: tuple_t {
	int D() { return get<0>(*this); }
	int H() { return get<1>(*this); }
	ll M() { return get<2>(*this); }
	dhm(int d, int h, ll m) { *static_cast<tuple_t *>(this) = make_tuple(d, h, m); }
};

int solve(int N, int *D, int *H, int *M) {
	vector<dhm> m;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < H[i]; j++) {
			m.push_back(dhm(D[i], H[i], (ll)M[i]+j*360LL));
		}
	}
	int n = m.size();
	ll ans = (1LL << 61);
	for (int i = 0; i < n; i++) {
		ll t = m[i].M() * (360 - m[i].D());
		ll r = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			ll t2 = m[j].M() * (360 - m[j].D());
			if (t2 > t) {
				r++;
			} else {
				r += (t-t2)/(m[j].M() * 360);
			}
		}
		ans = min(ans, r);
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		int D[1010];
		int H[1010];
		int M[1010];
		for (int j = 0; j < N; j++) {
			cin >> D[j] >> H[j] >> M[j];
		}
		int ans = solve(N, D, H, M);
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}
