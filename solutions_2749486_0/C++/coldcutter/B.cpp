#include <cstdio>

int test, x, y;
char c1, c2;

int main()
{
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase)
	{
		scanf("%d %d", &x, &y);
		printf("Case #%d: ", kase);
		if (x >= 0)
			c1 = 'W', c2 = 'E';
		else
			c1 = 'E', c2 = 'W', x = -x;
		for (int i = 1; i <= x; ++i)
			printf("%c%c", c1, c2);
		if (y >= 0)
			c1 = 'S', c2 = 'N';
		else
			c1 = 'N', c2 = 'S', y = -y;
		for (int i = 1; i <= y; ++i)
			printf("%c%c", c1, c2);
		puts("");
	}
	
	return 0;
}
