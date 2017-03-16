#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
using namespace std;
typedef long long i64;


i64 ipow(i64 base, i64 exp)
{
	i64 result = 1;
	while (exp) {
		if (exp & 1) result *= base;
		exp >>= 1;
		base *= base;
	}
	return result;
}

int main() {
	int T; scanf("%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti) {
		fprintf(stderr, "Case #%d of %d...\n", Ti, T);

		int K, C, S;
		scanf("%d %d %d", &K, &C, &S);

		if (C == 1) {
			if (K > S) {
				printf("Case #%d: IMPOSSIBLE\n", Ti);
			} else {
				printf("Case #%d:", Ti);
				for (int i = 0; i < K; ++i) {
					printf(" %d", i + 1);
				}
				printf("\n");
			}
		} else {
			if (K / 2 > S) {
				printf("Case #%d: IMPOSSIBLE\n", Ti);
			} else {
				printf("Case #%d:", Ti);
				i64 step = ipow(K, C-1);
			
				for (i64 i = 0; i < K; i += 2) {
					i64 j = (1 + i) + i * step;
					printf(" %lld", min(j + 1, K * step));
				}
				printf("\n");
			}
		}
	}
	return 0;
}
