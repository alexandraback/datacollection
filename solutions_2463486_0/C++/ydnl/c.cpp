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

LL T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, ans;
LL a[1000000];

bool check(LL x){
	char temp[20];
	LL n = sprintf(temp, "%lld", x);
	for (LL i=0; i<n/2; i++)
		if (temp[i] != temp[n-1-i])
			return false;
	return true;
}

int main(){
	cnt = 0;
	for (LL i=1; i<=10000000; i++){
		if (check(i) && check(i*i))
			a[cnt++] = i*i;
	}
	scanf("%lld", &T);
	for (LL rr = 1; rr <= T; rr++){
		ans = 0;
		printf("Case #%lld: ", rr);
		scanf("%lld %lld", &q, &w);
		for (LL i=0; i<cnt; i++)
			if (a[i] >= q && a[i] <= w)
				ans++;
		printf("%lld\n", ans);
	}
	return 0;
}
