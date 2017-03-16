#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef long long ll;

ll E,R,N,V[10001];

ll solve() {
	scanf("%lld %lld %lld", &E, &R, &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lld", V+i);
	}
	ll ans = 0;
	int e = E;
	for (int i = 0; i < N; ++i) {
		ll use = max(0LL, E - R);
		for (int j = i+1; j < N && use > 0; ++j) {
			if (V[j] >= V[i]) break;
			use = max(0LL, use - R);
			if (j == N-1) use = 0;
		}
		if (i == N-1) use = 0;
		if (use < e) {
			ans += (e - use) * V[i];
			e = use;
		}
		e = min(E, e + R);
//		cout << use << " " << ans << endl;
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc){
		printf("Case #%d: %lld\n", tc, solve());
	}
}
