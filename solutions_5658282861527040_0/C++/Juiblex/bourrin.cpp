#include <cstdio>

int main(void) {
	int nbTests;
	scanf("%d", &nbTests);
	for (int iTest = 1; iTest <= nbTests; iTest++) {
		int a, b, k, total = 0;
		scanf("%d%d%d", &a, &b, &k);
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				if ((i&j) < k)
					total++;
		printf("Case #%d: %d\n", iTest, total);
	}
	return 0;
}
