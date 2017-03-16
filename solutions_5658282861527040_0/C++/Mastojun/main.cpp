#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int T;
int A, B, K;

long long solve() {
	long long result = 0;

	for(int a = 0; a < A; a++) {
		for(int b = 0; b < B; b++) {
			if( (a & b) < K ) result ++;
		}
	}
	return result;
}

int main() {
	scanf("%d", &T);

	for(int c = 1; c <= T; c++) {
		scanf("%d %d %d", &A, &B, &K);

		printf("Case #%d: %lld\n", c, solve());

	}
	return 0;
}
