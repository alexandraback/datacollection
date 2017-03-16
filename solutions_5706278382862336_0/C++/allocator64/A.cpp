#include <cstdio>
#include <string>

using namespace std;

uint64_t gcd (uint64_t a, uint64_t b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

uint32_t bitcnt(uint64_t x) {
	uint32_t res = 0;
	while (x) {
		res += x & 1;
		x >>= 1;
	}
	return res;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; ++test) {
		uint64_t P, Q;
		scanf("%llu/%llu", &P, &Q);
		uint64_t g = gcd(P, Q);
		P /= g;
		Q /= g;
		printf("Case #%d: ", test + 1);
		if (bitcnt(Q) != 1) {
			printf("impossible\n");
			continue;
		}
		uint32_t res = 0;
		for (uint32_t i = 1; i <= 40; ++i) {
			if ((P * (1ull << i)) >= Q) {
				res = i;
				break;
			}

			// uint64_t A = P;
			// uint64_t B = Q;
			// uint32_t k = i;

			// while (B % 2 == 0) {
			// 	B /= 2;
			// 	--k;
			// }

			// if (B < A * (1ull << k)) {
			// 	res = i;
			// 	break;
			// }
		}
		printf("%d\n", res);
	}

	return 0;
}