#include <cstdio>

int num[1000001] = {};

int main() {

	int testcase, t;
	int q;
	int i, j;
	int temp, temp2;

	// Precalculate

	num[1] = 1;
	for (i = 1; i < 1000000; i++) {
		if (num[i + 1] > num[i] + 1 || num[i + 1] == 0) {
			num[i + 1] = num[i] + 1;
		}
		temp = i;
		temp2 = 0;
		while (temp > 0) {
			temp2 = temp2 * 10 + temp % 10;
			temp /= 10;
		}
		if (temp2 <= 1000000) {
			if (num[temp2] > num[i] + 1 || num[temp2] == 0) {
				num[temp2] = num[i] + 1;
				if (temp2 < i) {
					printf("CAUTION!\n");
				}
			}
		}
	}
	
	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		printf("Case #%d: ", t);

		scanf("%d", &q);
		printf("%d\n", num[q]);
	}

	return 0;
}
