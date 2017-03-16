#include <cstdio>

int k, c, s;

void solve(int test)
{
	scanf("%d %d %d", &k, &c, &s);
	long long p = 1, z = 0;
	for (int i = 1; i < c; i++) p *= (long long) k;
	printf("Case #%d: ", test);
	for (int i = 1; i <= s; i++) printf("%lld ", z + 1), z += p;
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) solve(i);
	return 0;
}