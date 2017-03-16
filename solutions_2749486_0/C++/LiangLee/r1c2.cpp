#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int T;

	scanf("%d\n", &T);
	for (int cnt = 1 ; cnt <= T ; cnt++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		char f,s;
		printf("Case #%d: ", cnt);
		if (x > 0)
		{
			f = 'W';
			s = 'E';
		}else {
			f = 'E';
			s = 'W';
			x = -x;
		}
		for (int i = 0 ; i < x ; i++)
		{
			printf("%c%c",f,s);
		}
		if (y > 0)
		{
			f = 'S';
			s = 'N';
		}else {
			f = 'N';
			s = 'S';
			y = -y;
		}
		for (int i = 0 ; i < y ; i++)
		{
			printf("%c%c",f,s);
		}
		printf("\n");
	}

	return 0;
}