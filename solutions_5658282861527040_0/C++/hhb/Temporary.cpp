#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
long long solve() {
	long long A, B, K;
	scanf("%lld%lld%lld", &A, &B, &K);
	long long r = 0;
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) {
			if ((i&j) < K) r++;
		}
	}
	return r;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int c = 1; c <= T; c++) {
		printf("Case #%d: %lld\n", c, solve());
	}
}