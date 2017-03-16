#include <stdio.h>

typedef unsigned long long u64;

void solve(int no)
{
	int n;
	scanf(" %d", &n);
	if (n == 0) {
		printf("Case #%d: INSOMNIA\n", no);
		return;
	}
	int a = 0;
	for (int i=0; i<10; ++i) {
		a |= 1 << i;
	}
	for (int i=1; i<1000; ++i) {
		u64 t = ((u64)n) * i;
		while (t) {
			a &= ~(1<<(t % 10));
			t /= 10;
		}
		if (a == 0) {
			//printf("Case #%d: %d %d, %llu\n", no, i, n, i * ((u64)n));
			printf("Case #%d: %llu\n", no, i * ((u64)n));
			return;
		}
	}
	printf("Case #%d: INSOMNIA\n", no);
}

int main()
{
	int T;
	scanf(" %d", &T);
	for (int i=0; i<T; ++i) {
		solve(i+1);
	}
	return 0;
}
