#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-11
#define oo 1LL<<53
#define LL long long

using namespace std;

LL T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an;
LL a, b, k;

int main(){
	scanf("%lld", &T);
	for (LL rr = 1; rr <= T; rr++){
		printf("Case #%lld: ", rr);
		scanf("%lld%lld%lld", &a, &b, &k);
		cnt = 0;
		for (LL i=0; i<a; i++)
			for (LL j=0; j<b; j++)
				if ((i&j) < k)
					cnt++;
		printf("%lld\n", cnt);
	}
	return 0;
}
