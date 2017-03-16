#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FOR(i, x, y) for(int i = x; i < y; ++ i)
#define pb push_back
#define mk make_pair

void solve() {
	int K, C, S;
	scanf("%d%d%d", &K, &C, &S);
	int ans = (K - 1) / C + 1;
	if (ans > S) {
		puts(" IMPOSSIBLE");
		return;
	}
	int t = 0;
	FOR(i, 0, ans)
	{
		ll x = 0;
		FOR(j, 0, C)
		{
			x = x * K + t;
			if (++t == K)
				t = 0;
		}
		printf(" %lld", x + 1);
	}
	puts("");
}

int main() {
#ifdef LOCAL
	freopen("in","r",stdin);
#endif
	int T, Case = 0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d:", ++Case);
		solve();
	}
	return 0;
}
