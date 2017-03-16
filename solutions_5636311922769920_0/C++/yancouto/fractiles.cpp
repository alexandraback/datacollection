#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int main() {
	int i, k, c, s;
	for_tests(t, tt) {
		scanf("%d %d %d", &k, &c, &s);
		assert(s == k);
		printf("Case #%d:", tt);
		for(i = 1; i <= s; i++)
			printf(" %d", i);
		putchar('\n');
	}
}
