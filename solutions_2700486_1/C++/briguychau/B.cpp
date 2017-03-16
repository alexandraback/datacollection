#include <stdio.h>
#include <math.h>

int rows(int N) {
	int i = 1;
	while ((2 * i - 1) * (2 * i) < 2 * N) {
		i++;
	}
	return i;
}

int nCr(int n, int r) {
	int result = 1;
	for (int i = 0; i < r; i++) {
		result *= (n - i);
	}
	for (int i = 1; i <= r; i++) {
		result /= i;
	}
	return result;
}

void solve(int count) {
	int N, X, Y;
	scanf("%d %d %d", &N, &X, &Y);
	if (X < 0) X *= -1;
	double result = 0;
	
	if (X + Y > 2 * (rows(N) - 1)) {
		result = 0;
	} else {
		if (X + Y < 2 * (rows(N) - 1)) {
			result = 1;
		} else {
			int remaining = N - ((2 * rows(N) - 2) * (2 * rows(N) - 3) / 2);
			int rowtotal = 4 * rows(N) - 3;
			if (X == 0) {
				if (remaining == rowtotal)
					result = 1;
				else
					result = 0;
			} else if (rowtotal - remaining <= X) {
				result = 1;
			} else {
				for (int i = Y; i < remaining; i++) {
					result += nCr(i, Y) * pow(0.5, i);
				}
				result /= 2;
			}
		}
	}
	printf("Case #%d: %f\n", count, result);
	return;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		solve(i);
	}
	return 0;
}

