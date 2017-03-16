#include <stdio.h>

int main() {
	char A[1024];
	int i, S, t, x = 1;
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d %[^\n]\n", &S, A);
		int a = 0, c = A[0] - '0';
		for (i = 1; i <= S; ++i) {
			int k = A[i] - '0';
			if (c < i) {
				a += i - c;
				c += i - c;
			}
			c += k;
		}
		printf("Case #%d: %d\n", x++, a);
	}
	return 0;
}
