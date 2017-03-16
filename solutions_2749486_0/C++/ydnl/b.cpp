#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-8
#define oo 1<<29
#define LL long long

using namespace std;

LL T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an, ans, y;

int main(){
	scanf("%lld", &T);
	for (LL rr = 1; rr <= T; rr++){
		printf("Case #%lld: ", rr);
		scanf("%lld%lld", &x, &y);
		if (x > 0){
			for (LL i=0; i<x; i++)
				printf("WE");
		} else {
			for (LL i=0; i<-x; i++)
				printf("EW");
		}
		if (y > 0){
			for (LL i=0; i<y; i++)
				printf("SN");
		} else {
			for (LL i=0; i<-y; i++)
				printf("NS");
		}
		puts("");
	}
	return 0;
}
