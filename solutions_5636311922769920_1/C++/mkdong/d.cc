#include <stdio.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

typedef unsigned long long u64;

int k, c, s;

/* *p postion to identify from */
u64 find(int *p)
{
	u64 r = *p;
	int tocheck = *p;
	int l = 1;
	(*p)++;
	while (l < c) {
		tocheck++;
		tocheck = MIN(tocheck, k);
		r = (r-1) * k + tocheck;
		(*p)++;
		l++;
	}
	return r;
}

void solve(int no)
{
	scanf(" %d %d %d", &k, &c, &s);
	printf("Case #%d:", no);
	int one_check = MIN(k, c);
	if (one_check * s < k) {
		printf(" IMPOSSIBLE\n");
		return;
	}
	int p = 1;
	while (p <= k) {
		printf(" %llu", find(&p));
	}
	putchar('\n');
}

int main()
{
	int T;
	scanf(" %d", &T);
	for (int i=0; i<T; ++i)
		solve(i+1);
	return 0;
}
