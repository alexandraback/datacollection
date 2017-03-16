#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << endl)

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define _FOR(it, b, e) for (decltype(b) it = (b); it != (e); ++it)
#define foreach(x...) _FOR(x)
#define fu(i, a) foreach(i, 0, a)
#define forall(i, v) foreach(i, all(v))

#define MSET(c, v) memset(c, v, sizeof(c))

#define pb push_back
#define sz(c) int((c).size())

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

ll E, R, N;

ll m[10010], M[10010];

int main() {
	int _;
	scanf("%d", &_);
	fu(__,_) {
		printf("Case #%d:", __+1);
		vector<pair<ll, ll> > V;
		scanf("%lld %lld %lld", &E, &R, &N);
		fu(i, N) {
			ll temp;
			scanf("%lld", &temp);
			V.pb(make_pair(temp, i));
		}
		auto V2 = V;
		sort(rall(V));
		set<int> already;
		for (auto& v: V) {
			ll p2 = v.second;
			auto temp = already.lower_bound(p2);
			if (temp == already.end()) {
				m[p2] = 0;
			} else {
				ll p3 = *temp;
				m[p2] = max(0ll, M[p3] - (p3-p2)*R);
			}
			if (temp == already.begin()) {
				M[p2] = E;
			} else {
				temp--;
				ll p1 = *temp;
				M[p2] = min(E, m[p1] + R*(p2-p1));
			}
			already.insert(p2);
		}
		ll ans = 0;
		fu(i, N) ans += V2[i].first*(M[i] - m[i]);
		printf(" %lld\n", ans);
	}
	return 0;
}
