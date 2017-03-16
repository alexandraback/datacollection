#include <stdio.h>
#include <string.h>

long long p, q;
int t;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool judge(long long num) {
    while (num > 1) {
	if (num % 2) return false;
	num /= 2;
    }
    return true;
}

int main() {
    scanf("%d", &t);
    int cas = 0;
    while (t--) {
	scanf("%lld%*c%lld", &p, &q);
	long long t = gcd(p, q);
	p /= t; q /= t;
	printf("Case #%d: ", ++cas);
	if (judge(q)) {
	    int count = 0;
	    while (p < q) {
		p *= 2;
		count++;
	    }
	    printf("%d\n", count);
	}
	else {
	    printf("impossible\n");
	}
    }
    return 0;
}
