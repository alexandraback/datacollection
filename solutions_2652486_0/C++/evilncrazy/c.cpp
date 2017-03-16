#include <cstdio>
#include <algorithm>

int prods[100];

bool good(int i, int j, int k, int prod) {
	// consider subset
	for (int m = 0; m <= 1; m++) {
		for (int n = 0; n <= 1; n++) {
			for (int o = 0; o <= 1; o++) {
				if (i * m + j * n + k * o != prod) {
					return false;
				}
			}
		}
	}

	return true;
}

bool all(int i, int j, int k) {
	for (int l = 0; l < 7; l++) {
		if (!good(i, j, k, prods[l])) {
			return false;
		}
	}
	return true;
}

void solve(int cs) {
	for (int j = 0; j < 7; j++) {
		scanf("%d", &prods[j]);
	}

	for (int i = 2; i <= 5; i++) {
		for (int j = 2; j <= 5; j++) {
			for (int k = 2; k <= 5; k++) {
				if (all(i, j, k)) {
					printf("%d%d%d\n", i, j, k);
					return;
				}
			}
		}
	}

	printf("222\n");
}

int main() {
	int t;
	scanf("%d", &t);

	printf("Case #1:\n");
	for (int i = 0; i < 100; i++) {
		solve(i);
	}
}