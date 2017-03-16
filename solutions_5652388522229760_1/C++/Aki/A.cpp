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


int main() {
	int T; scanf("%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti) {
		fprintf(stderr, "Case #%d of %d...\n", Ti, T);

		int N;
		scanf("%d", &N);

		if (N == 0) {
			printf("Case #%d: INSOMNIA\n", Ti);
		} else {
			int digits = 0;
			i64 i = 1;
			for (;;) {
				i64 a = i * N;
				fprintf(stderr, "%lld\n", a);
				while (a != 0) {
					digits |= 1 << (a % 10);
					a /= 10;
				}
				if (digits == 1023) break;
				++i;
			}
			
			printf("Case #%d: %lld\n", Ti, N * i);
		}
	}
	return 0;
}
