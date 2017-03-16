#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
typedef long long ll;

int N, J, MAX_P, D;
ll t, p[10100][11][40];
vector<ll> primes;

struct res {
	ll m;
	vector<ll> div;
} c;

vector<res> v;

int main () {
	printf("Case #1:\n");
	tie(N, J, MAX_P) = make_tuple(16, 50, 1000);
	ifstream pfile("primes.txt");
	while (pfile >> t && (int) primes.size() < MAX_P) primes.PB(t);
	for (ll P : primes) {
		for (ll i = 2; i <= 10; i++) {
			fo(j, N) p[P][i][j] = j ? (p[P][i][j-1] * i) % P : 1;
		}
	}
	for (ll x = 0; x < (1<<(N-2)); x++) {
		t = (1<<(N-1)) | (x<<1) | 1;
		bool ok = 1;
		for (ll b = 2; b <= 10; b++) {
			bool o = 0;
			for (ll P : primes) {
				ll val = 0;
				fo(i, N) if ((1<<i)&t) {
					val = (val + p[P][b][i]) % P;
				}
				o |= (val == 0);
			}
			if (!o) ok = 0;
		}
		if (ok) {
			c.m = t, c.div.clear();
			for (ll b = 2; b <= 10; b++) {
				for (ll P : primes) {
					ll val = 0;
					fo(i, N) if ((1<<i)&t) {
						val = (val + p[P][b][i]) % P;
					}
					if (val == 0) { c.div.PB(P); break; }
				}
			}
			for (int i = N; i--; ) printf("%d", !!((1<<i)&c.m));
			for (ll i : c.div) printf(" %lld", i); puts("");
			//v.PB(c);
			//if ((int) v.size() == J) break;
			D++; if (D == J) break;
		}
	}
	/*
	   for (res r : v) {
	   fo(i, N) printf("%d", !!((1<<i)&r.m));
	   for (ll i : r.div) printf(" %lld", i); puts("");
	   }
	 */
	return 0;
}
