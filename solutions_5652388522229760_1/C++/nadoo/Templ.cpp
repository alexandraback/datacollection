#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out","w", stdout);
	int m, n, i, j;
	int t, ti;
	scanf("%d", &t);
	for (ti = 0; ti < t; ti++) {
		int check = 0;
		printf("Case #%d: ", ti + 1);
		scanf("%d", &n);
		if (n == 0) {
			printf("INSOMNIA\n");
			continue;
		}
		i = 0;
		do {
			i += n;
			int temp = i;
			while (temp) {
				check |= 1 << (temp % 10);
				temp /= 10;
			}
		} while (check < 0x000003ff);
		printf("%d\n", i);
	}
	return 0;
}