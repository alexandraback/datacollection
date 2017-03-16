#include <bits/stdc++.h>

#define sz(z) (int)z.size()
#define fo(i,a,b) for (auto (i) = (a); (i) < (b); (i)++)
#define mp make_pair
#define pb push_back

using namespace std;

#define DEBUG

#ifdef DEBUG
#define D(x...) printf(x)
#else
#define D(x...) 
#endif

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	freopen("fra.in","r",stdin);
	int t;
	scanf("%d\n", &t);
	for (int _ = 1; _ <= t; _++) {
		printf("Case #%d: ", _);
		ll k, c, s;
		scanf("%lld %lld %lld\n", &k, &c, &s);
		if (s < k) {
			puts("IMPOSSIBLE");
			continue;}
		for (int i = 1; i < s; ++i) {
			printf("%d ", i);
		}
		printf("%lld\n",s);
	}
	
	return 0;
}
