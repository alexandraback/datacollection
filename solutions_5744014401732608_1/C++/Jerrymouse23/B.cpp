#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; cases++) {
		printf("Case #%d: ", cases);
		int B;
		unsigned long long M;
		scanf("%d%llu", &B, &M);
		if (M < (1 << (B-2))) {
			printf("POSSIBLE\n");
			for (int i = 0; i < B; i++) {
				for (int j = 0; j < B-1; j++) {
					if (i < j) {
						printf("1");
					} else {
						printf("0");
					}
				}
				if ((M & (1 << (i-1))) > 0) {
					printf("1\n");
				} else {
					printf("0\n");
				}
			}
		} else if (M == (1 << (B-2))) {
			printf("POSSIBLE\n");
			for (int i = 0; i < B; i++) {
				for (int j = 0; j < B; j++) {
					if (i < j) {
						printf("1");
					} else {
						printf("0");
					}
				}
				printf("\n");
			}
		} else {
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
