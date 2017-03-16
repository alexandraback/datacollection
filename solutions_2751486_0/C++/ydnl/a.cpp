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

LL T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, r, z, x, an, ans, l;
char a[1000010];
int b[1000010];
int c[1000010];
LL e[1000010];

int main(){
	scanf("%lld", &T);
	for (LL rr = 1; rr <= T; rr++){
		printf("Case #%lld: ", rr);
		ans = 0;
		scanf("%s", a);
		scanf("%lld", &m);
		for (LL i=0; a[i]; i++)
			if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
				b[i] = 0;
			else b[i] = 1;
		c[0] = b[0];
		for (LL i=1; a[i]; i++)
			c[i] = c[i-1] + b[i];
		l = strlen(a);
		memset(a, 0, sizeof(a));
		if (c[m-1] == m)
			a[m-1] = 1;
		for (LL i=0; i<l; i++)
			if (i+m < l && c[i+m] - c[i] == m)
				a[i+m] = 1;
			else a[i+m] = 0;
//		for (LL i=0; i<l; i++)
//			printf("%d", a[i] == 1?1:0);
//		puts("");
		LL cnt = 0;
		for (LL i=0; i<l; i++)
			if (a[i] == 1)
				e[cnt++] = i;
		e[cnt] = oo;
		cnt++;
		for (LL i=0; i<l; i++){
			LL pos = *lower_bound(e, e+cnt, i+m-1);
			if (pos >= l) continue;
			ans += l - pos;
		}
		printf("%lld\n", ans);
	}

	return 0;
}
