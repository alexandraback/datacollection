#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int T;

long long P, Q;

long long GCD(long long P, long long Q) {
	if(Q == 0) return P;
	return GCD(Q, P%Q);
}

int solve(long long P, long long Q) {
	if(P == 0 && Q == 1) return 0;
	for(int i = 1; i <= 40; i++) {
		if(Q % 2 == 1) break;
		Q /= 2;
		long long gcd = GCD(P, Q);
		P /= gcd;
		Q /= gcd;
		if(Q <= P) {
			if(solve(P - Q, Q) != -1) return i;
		}
	}

	return -1;
}

int main() {

	scanf("%d", &T);

	for(int c = 1; c <= T; c++) {
		scanf("%lld/%lld", &P, &Q);

		int result = solve(P, Q);

		printf("Case #%d: ", c);
		if(result != -1) {
			printf("%d\n", result);
		} else {
			puts("impossible");
		}
	}

	return 0;
}
