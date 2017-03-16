#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
	return !b?a:gcd(b, a%b);
}

int calc(LL a, LL b) {
	LL d = gcd(a,b);
	a/=d;
	b/=d;
	if (a >= b || (b & (b-1))) {
		return -1;
	}

	if (a+a >= b) return 1;
	else {
		return calc(a, b / 2) + 1;
	}
}


int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int Tn;
	scanf("%d", &Tn);
	for (int Tc = 1; Tc <= Tn; ++Tc) {
		LL a, b;
		scanf("%lld/%lld", &a, &b);
//		cout <<"a=" <<a<<endl;
//		cout <<"b=" <<b<<endl;

		int r = calc(a, b);

		printf("Case #%d: ", Tc);
		if (r == -1) {
			puts("impossible");
		} else {
			printf("%d\n", r);
		}
	}
	return 0;
}
