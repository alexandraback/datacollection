#include <stdio.h>

void go(int x, char front, char back)
{
	while (x--)
	{
		printf("%c", back);
		printf("%c", front);
	}
}

int main()
{
	int T, cas=0;
	int x, y;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &x, &y);
		printf("Case #%d: ", ++cas);
		if (x>=0) go(x, 'E', 'W');
		else go(-x, 'W', 'E');
		if (y>=0) go(y, 'N', 'S');
		else go(-y, 'S', 'N');
		printf("\n");
	}
	return 0;
}
