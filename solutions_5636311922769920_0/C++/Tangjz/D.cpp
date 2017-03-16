#include <cstdio>
const int maxt = 100, maxk = 100, maxc = 100;
int t, k, c, s;
int main()
{
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case)
	{
		scanf("%d%d%d", &k, &c, &s);
		printf("Case #%d:", Case);
		for(int i = 1; i <= s; ++i)
			printf(" %d", i);
		putchar('\n');
	}
	return 0;
}
