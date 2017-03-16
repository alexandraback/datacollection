#include <stdio.h>
#include <stdlib.h>

int test, tt, d1, d2, d3, d4, x, y, i;

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &test);
	while (test > 0)
	{
		test--;
		tt++;
		scanf("%d %d", &x, &y);
		if (x < 0)
			d1 = 'W', d2 = 'E', x = 0 - x;
		else
			d1 = 'E', d2 = 'W';
		if (y < 0)
			d3 = 'S', d4 = 'N', y = 0 - y;
		else
			d3 = 'N', d4 = 'S';
		printf("Case #%d: ", tt);
		for (i = 1; i <= x; i++)
			printf("%c%c", d2, d1);
		for (i = 1; i <= y; i++)
			printf("%c%c", d4, d3);
		printf("\n");
	}
	
	return 0;
}
