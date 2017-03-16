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

LL T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an, ans;
LL a[1000010];

void dfs(LL size, LL index, LL cost){
	LL tt = index;
	for (LL i=index; i<m; i++){
		if (size > a[i]){
			size += a[i];
			tt = i+1;
		}
	}
//	printf("%lld %lld %lld\n", size, index, cost);
	if (tt >= m) {
		if (cost < mi) mi = cost;
		return;
	}
	dfs(size + size - 1, tt, cost+1);
	dfs(size, tt+1, cost+1);
}

int main(){
	scanf("%lld", &T);
	for (LL rr = 1; rr <= T; rr++){
		mi = oo;
		printf("Case #%lld: ", rr);
		scanf("%lld %lld", &q, &m);
		for (LL i=0; i<m; i++)
			scanf("%lld", &a[i]);
		sort(a, a+m);
		if (q == 1){
			printf("%lld\n", m);
			continue;
		}
		dfs(q, 0, 0);
		printf("%lld\n", mi);
	}
	return 0;
}
