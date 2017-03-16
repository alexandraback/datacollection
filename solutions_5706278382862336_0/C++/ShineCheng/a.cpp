#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d\n", &t);
	int cas = 1;
	while (t--) {
		printf("Case #%d: ", cas++);
		long long p, q;
		scanf("%lld/%lld\n", &p, &q);
		long long gcd = __gcd(p,q);
		p /= gcd;
		q /= gcd;
		if (p > q) {
			printf("impossible\n");
			continue;
		}
		int yuan, qnum;
		qnum = 0;
		int onenum = 0;
		while (q) {
			onenum += (q&1);
			q>>=1;
			qnum++;
		}
		if (onenum > 1) {
			printf("impossible\n");
			continue;
		}
		yuan = 0;
		while(p) {
			yuan++;
			p>>=1;
		}
		//printf("qnum = %d, yuan = %d\n", qnum, yuan);
		printf("%d\n", (qnum - yuan));
	}
	return 0;
}
