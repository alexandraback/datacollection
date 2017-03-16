#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int tests = 0; scanf("%d", &tests);
    for (int test = 0; test < tests; test++) {
	printf("Case #%d: ", test + 1);
	long long p, q; scanf("%lld/%lld", &p, &q);
	long long g = gcd(p, q);
	p /= g; q /= g;
	int qp = -1; 
	for (int i = 0; i <= 40; i++) {
	    if ((1L << i) == q) 
		qp = i;
	}
	if (qp == -1) {
	    printf("impossible\n");
	    continue;
	}
	int pp = 0;
	for (; p != 0; p >>= 1)
	    pp++;
	printf("%d\n", qp + 1 - pp);
    }
}
