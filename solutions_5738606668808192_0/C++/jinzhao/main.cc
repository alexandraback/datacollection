#include <cstdio>

const int K = 10;
const int p[K] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27};

int n, k;

long long convert(int a, int k) {
	long long x = 1, ans = 0;
	while (a) {
		if (a & 1) ans += x;
		a >>= 1;
		x *= k;
	}
	return ans;
}
void print(int a) {
	for (int i = 15; i >= 0; i--) {
		printf("%d", (int)(bool)(1 << i & a));
	}
}
bool cal(int i) {
	int a[11];
	for (int k = 2; k <= 10; k++) {
		long long ii = convert(i, k);
		a[k] = -1;
		for (int j = 0; j < K; j++) {
			if (ii % p[j] == 0) a[k] = p[j];
		}
		if (a[k] == -1) return false;
	}
	print(i);
	if (n == 32) print(i);
	for (int k = 2; k <= 10; k++) {
		printf(" %d", a[k]);
	}
	printf("\n");
	return true;
}
int main() {
	int t;
	scanf("%d", &t);
	printf("Case #1:\n");
	scanf("%d%d", &n, &k);
	int nn = 1 << 14, l = 1 << 15;
	int m = 0;
	for (int i = 0; i < nn; i++) {
		int ii = l | i << 1 | 1;
		if (cal(ii)) m++;
		if (m == k) break;
	}
	return 0;
}
