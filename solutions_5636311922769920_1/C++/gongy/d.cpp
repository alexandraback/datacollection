#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
typedef long long ll;

int T, K, C, S, a;
ll p[110];
vector<ll> v;

int main () {
	scanf("%d", &T);
	for (int _ = 1; _ <= T; _++) {
		scanf("%d %d %d", &K, &C, &S);
		v.clear(), a = 0;
		for (int c = C; c--; ) p[c] = (c!=C-1 ? p[c+1] * K : 1);
		while (a < K) {
			ll q = 0;
			for (ll i = a; i < min(a+C, K); i++) {
				q += i * p[i-a];
			}
			v.PB(q+1), a += C;
		}
		printf("Case #%d:", _);
		if ((int) v.size() > S) puts(" IMPOSSIBLE");
		else {
			for (ll i : v) printf(" %lld", i); puts("");
		}
	}
	return 0;
}
