#include<iostream>
#include<cstdio>
using namespace std;

long long int gcd(long long int a, long long int b) {
    while (b != 0) {
       long long int t = b;
       b = a % b;
       a = t;
    }
    return a;
}

int get_level(long long int a, long long int b) {
	if (2*a >= b) return 1;
	return 1 + get_level(2*a, b);
}

bool is_power_of_two(long long int a) {
	while (a > 1) {
		if (a%2!=0) return false;
		a/=2;
	}
	return true;
}

int main() {
	int T;
	scanf("%d\n", &T);
	for (int tc=1; tc<=T; tc++) {
		long long int up, down;
		scanf("%lld/%lld\n", &up, &down);
		long long int the_gcd = gcd(up, down);
		up = up/the_gcd;
		down = down/the_gcd;
		printf("Case #%d: ", tc);
		if (!is_power_of_two(down)) {
			printf("impossible\n");
		} else {
			int level = get_level(up, down);
			printf("%d\n", level);
		}
	}
}
