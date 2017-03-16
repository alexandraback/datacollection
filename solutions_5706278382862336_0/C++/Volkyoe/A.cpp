#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#define INF 1000000000
typedef long long 		ll;
ll p, q;
int t, T, i;
bool ans;
ll gcd(ll& t1, ll& t2) {
	ll tmp, l1 = t1, l2 = t2;
	while (l1 % l2) {
		tmp = l1;
		l1 = l2;
		l2 = tmp % l2;
	}
	t1 /= l2;
	t2 /= l2;
}
int main() {
	freopen("4.in", "r", stdin);
	freopen("4_1.txt", "w", stdout);
	scanf("%d", &T);
	while (T > t++) {
		scanf("%lld/%lld", &p, &q);
		printf("Case #%d: ", t);
		gcd(p, q);
		//printf("%lld %lld\n", p, q);
		if ((q & (-q)) != q) {
			printf("impossible\n");
			continue;
		}
		i = 0;
		while (q > p) {
			q /= 2;
			i++;
		}
		printf("%d\n", i);
	}
}
