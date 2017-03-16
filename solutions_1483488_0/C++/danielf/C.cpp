#include <stdio.h>

int c(int x, int B, int n, int p) {
	int count = 0;
	int y = x;
	int ja[10];
	for (int i = 0; i < n; i++) {
		int last = y/p;
		y = (y-last*p)*10 + last;
		if (x < y && y <= B) {
			ja[count++] = y;
			for (int j = 0; j < count-1; j++) if (ja[j] == y) {
				count--;
				break;
			}
		}
	}
	return count;
}

long long ans(int A, int B) {
	long long count = 0;
	int temp = A;
	int n = 0;
	int p = 1;
	while (temp >= 10) {
		n++;
		p *= 10;
		temp /= 10;
	}
	for (int i = A; i <= B; i++)
		count += c(i, B, n, p);
	return count;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int A, B;
		scanf("%d %d", &A, &B);
		printf("Case #%d: %lld\n", t+1,ans(A,B));
	}
	return 0;
}
