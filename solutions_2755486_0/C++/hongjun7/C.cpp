#include <stdio.h>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;
#define MN 1001
struct data {
	long long di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
} d[MN];
struct data2 {
	long long di, wi, ei, si;
} c[MN];
long long h[3000], N, m;
inline bool cmp(data2 d1, data2 d2) {
	if (d1.di == d2.di)
		return d1.si < d2.si;
	return d1.di < d2.di;
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long long i, j, k, T, K, sol;
	scanf("%lld",&T);
	for (K = 1; K <= T; K++) {
		scanf("%lld",&N);
		memset(h, 0, sizeof(h));
		m = 0;
		for (i = 1; i <= N; i++) {
			scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&d[i].di,&d[i].ni,&d[i].wi,&d[i].ei,&d[i].si,&d[i].delta_di,&d[i].delta_pi,&d[i].delta_si);
			d[i].ei--;
			d[i].ei += 1000;
			d[i].wi += 1000;
			for (j = 1; j <= d[i].ni; j++) {
				m++;
				c[m].di = d[i].di+(d[i].delta_di)*(j-1);
				c[m].ei = d[i].ei+(d[i].delta_pi)*(j-1);
				c[m].wi = d[i].wi+(d[i].delta_pi)*(j-1);
				c[m].si = d[i].si+(d[i].delta_si)*(j-1);
			}
		}
		sort(c+1, c+m+1, cmp);
		sol = 0;
		bool sw;
		int l, bf = 1;
		for (k = 1; k <= m; k++) {
			if (k > 1 && c[k].di != c[k-1].di) {
				for (l = bf; l <= k-1; l++) {
					for (i = c[l].wi; i <= c[l].ei; i++) {
						if (h[i] < c[l].si)
							h[i] = c[l].si;
					}
				}
				bf = k;
			}
			sw = 0;
			for (i = c[k].wi; i <= c[k].ei; i++) {
				if (h[i] < c[k].si)
					sw = 1;
			}
			if (sw) {
				++sol;
				
			}
		}
		printf("Case #%lld: %lld\n",K,sol);
	}
	fcloseall();
	return 0;
}