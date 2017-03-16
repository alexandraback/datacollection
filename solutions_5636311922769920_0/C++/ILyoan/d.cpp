#include <cstdio>

int main() {
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc) {
		int K, C, S;
		scanf("%d%d%d", &K, &C, &S);
		printf("Case #%d:", tc);
		for (int i = 1; i <= S; ++i) {
			printf(" %d", i);
		}
		printf("\n");
	}
	return 0;
}