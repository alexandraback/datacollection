#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

#define mp make_pair
#define pb push_back

int main() {
	int T; scanf("%d", &T);
	for (int t = 0; t++<T;) {
		int B, y = 0;
		unsigned long long M, z = 1;
		scanf("%d%llu", &B, &M);
		printf("Case #%d: ", t);
		for (int j = 2; j < B; ++j) z *= 2;
		if (z < M) { printf("IMPOSSIBLE\n"); continue; }
		printf("POSSIBLE\n");
		y = z == M;
		if (z == M) {
			printf("0");
			for (int i = 1; i < B; ++i) printf("1");
		} else {
			while (M) {
				if (M >= z) {
					printf("1");
					M -= z;
				} else {
					printf("0");
				}
				z /= 2;
			}
			printf("0");
			while (z) { printf("0"); z /= 2; }
		}
		printf("\n");
		for (int i = 1, j; i < B-1; ++i) {
			for (j = 0; j <= i; ++j) {
				printf("0");
			}
			for (; j < B; ++j) {
				printf("1");
			}
			printf("\n");
		}
		for (int i = 0; i < B; ++i) printf("0");
		printf("\n");
	}
}
