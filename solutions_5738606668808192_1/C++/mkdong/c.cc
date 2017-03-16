#include <stdio.h>
#include <stdlib.h>

int n, j;
char buf[33];
int terms[11];

typedef unsigned long long u64;


int check(u64 num)
{
	for (int i=2; i*i<=num; ++i) {
		if (num % i == 0) return i;
	}
	return 0;
}

/* location to generate */
void dfs(int l)
{
	if (l == n-1) {
		/* time to check */
		for (int base=2; base<11; ++base) {
			u64 num = strtoull(buf, NULL, base);
			terms[base] = check(num);
			if (terms[base] == 0) return;
		}
		printf("%s", buf);
		for (int base=2; base<11; ++base) {
			//printf(" %d[%llu]", terms[base], strtoull(buf, NULL, base));
			printf(" %d", terms[base]);
		}
		putchar('\n');
		j--;
		return;
	}
	if (!j) return;
	buf[l] = '0';
	dfs(l+1);
	if (!j) return;
	buf[l] = '1';
	dfs(l+1);
}

void solve(int no)
{
	scanf(" %d %d", &n, &j);
	printf("Case #%d:\n", no);
	for (int i=0; i<33; ++i) {
		buf[i] = 0;
	}
	buf[0] = '1';
	buf[n-1] = '1';
	dfs(1);
}

int main()
{
	int T;
	scanf(" %d", &T);
	for (int i=0; i<T; ++i)
		solve(i+1);
	return 0;
}
