#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

typedef long long ll;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define ld_ll(X)  (63-__builtin_clzll(ll(X)))

#define MAX_N (1024 * 10)

int TC;
int N;
ll E, R, V[MAX_N];

ll mg(int i, int r) {
	if (i > N) return 0;

	ll ret = 0;
	FOR(e,0,r+1) {
		ret = max(ret,
			V[i] * e + mg(i+1, min(E, r-e+R))
		);
	}
	return ret;
}

int main() {
	int TC; cin >> TC;
	FOR(tc,1,TC+1) {
		cin >> E >> R >> N;
		FOR(i,1,N+1) cin >> V[i];

		printf("Case #%d: %lld\n", tc, mg(1, E));
	}
}
