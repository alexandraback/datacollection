#include <iostream>
#include <algorithm>
#include <cstdio>

int main(void) {
	int T, B;
	long M;
	std::cin >> T;

	int G[100][100];
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) G[i][j] = 0;
	}

	for (int t = 0; t < T; t++) {
		printf("Case #%i: ", t + 1);

		std::cin >> B >> M;

		if (B == 2) {
			if (M == 1) printf("POSSIBLE\n01\n00\n");
			else printf("IMPOSSIBLE\n");
			continue;
		}

		for (int i = 0; i < B; i++) {
			for (int j = i + 1; j < B; j++) G[i][j] = 1;
		}

		int requiredNodes = 2;
		long possibleMethods = 1;
		while (possibleMethods < M) {
			possibleMethods *= 2;
			requiredNodes++;
		}
		if (requiredNodes > B) printf("IMPOSSIBLE\n");
		else {
			printf("POSSIBLE\n");
			for (int i = 0; i < B - requiredNodes; i++) {
				for (int j = i + 2; j < B; j++) G[i][j] = 0;
			}
			if (possibleMethods != M) {
				G[B - requiredNodes][B - 1] = 0;
				long aux = M;
				for (int j = B - 2; j > B - requiredNodes; j--) {
					G[B - requiredNodes][j] = (M & 1);
					M /= 2;
				}
			}
			for (int i = 0; i < B; i++) {
				for (int j = 0; j < B; j++) {
					printf("%i", G[i][j]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}
