#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int T;

long long P, Q;

int solve(int P, int Q) {
	if(P == 0 && Q == 1) return 0;
	for(int i = 1; i <= 40; i++) {
		if(Q % 2 == 1) break;
		if(Q/2 > P) {
			Q /= 2;
		} else {
			if(solve(P - Q/2, Q/2) != -1) return i;
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
