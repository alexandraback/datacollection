#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long int gcd(long long int a, long long int b) 
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void run() {
	long long int a, b;
	scanf("%lld/%lld", &a, &b);
	long long int g = gcd(a, b);
	long long int exp = 1;
	int g1 = 0, g2 = 0;
	a /= g;
	b /= g;
	exp = 1;
//	printf("gcd %lld\n", g);
	for (int i = 1; i <= 40; ++i) {
		exp *= 2;
		if (g1 == 0 && a * exp >= b)
			g1 = i;
		if (b == exp) {
//			printf("%lld %lld\n", b, exp);
			g2 = i;
		}
	}
	
	if (g1 == 0 || g2 == 0) {
		puts("impossible");
		return;
	}
	printf("%d\n", g1);
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);
    for (int t = 1; t <= num_cases; ++t) {
        printf("Case #%d: ", t);
        run();
    }
    return 0;
}

