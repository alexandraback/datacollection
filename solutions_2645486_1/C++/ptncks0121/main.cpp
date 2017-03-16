#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>

using namespace std;
typedef long long ll;
const int INF = 987654321;
const ll LINF = 1e15;

void precalc();

const int N_ = 10500;

int TC, TCC;
ll E, R, N;
ll V[N_];

bool Used[N_];

int main() {
    freopen("input.txt", "r", stdin);

    int i, j, k;

    precalc();
    freopen("output.txt", "w", stdout);

    scanf("%d", &TC);
    while(++TCC <= TC) {
        printf("Case #%d: ", TCC);

		scanf("%lld%lld%lld", &E, &R, &N);
		for(i = 0; i < N; i++) scanf("%lld", &V[i]);
		R = min(E, R);

		ll ret = 0;

		memset(Used, 0, sizeof Used); V[N] = -1;
		for(i = 0; i < N; i++) {
			for(j = 0, k = N; j < N; j++) if(!Used[j] && V[j] > V[k]) k = j;
			if(k == N) break;

			Used[k] = 1;
			int l; for(l = k - 1; l >= 0; l--) if(Used[l]) break;
			int r; for(r = k + 1; r <  N; r++) if(Used[r]) break;

			ll now = E;
			if(l >= 0 && E - (k - l) * R > 0) now -= E - (ll)(k - l) * R;
			if(r <  N && E - (r - k) * R > 0) now -= E - (ll)(r - k) * R;

			ret += max(now, 0ll) * V[k];
		}

		printf("%lld\n", ret);
    }
    return 0;
}

void precalc() {
}
