#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int K, C, S, T;

int main() {
	scanf("%d", &T);
	for (int TT = 1; TT <= T; TT++) {
		scanf("%d %d %d", &K, &C, &S);
		printf("Case #%d:", TT);
		if (C == 1 || K == 1) {
			if (S < K) printf(" IMPOSSIBLE\n");
			else {
				for (int i = 1; i <= K; i++) {
					printf(" %d", i);
				}
				printf("\n");
			}
		} else {
			if (S * 2 < K) printf(" IMPOSSIBLE\n");
			else {
				long long xx = 1;
				long long num = 0;
				for (int i = 1; i < C; i++) {
					xx *= K;
					num += xx;
				}
				if (K % 2 == 1) {
					printf(" 2");
					for (int i = 2; i <= K; i+=2) {
						printf(" %lld", num * (i - 1) + i + 1);
					}
					printf("\n");
				} else {
					for (int i = 1; i <= K; i+=2) {
						printf(" %lld", num * (i - 1) + i + 1);
					}
					printf("\n");
				}
			}
		}
	}

	return 0;
}