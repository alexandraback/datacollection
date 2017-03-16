#include <stdio.h>
#include <string.h>

int T;

int main(int argc, char *argv[])
{
	int i,j,k;
	int x,y;
	char c1,c2;
	scanf("%d\n", &T);
	for (i=0;i<T;i++)
	{
		printf("Case #%d: ", i+1);
		scanf("%d %d\n", &x, &y);
		if (x>0)
		{
			c1 = 'W';
			c2 = 'E';
		}
		else
		{
			c1 = 'E';
			c2 = 'W';
			x = -x;
		}
		for (j=0;j<x;j++)
			printf("%c%c",c1,c2);
		if (y>0)
		{
			c1 = 'S';
			c2 = 'N';
		}
		else
		{
			c1 = 'N';
			c2 = 'S';
			y = -y;
		}
		for (j=0;j<y;j++)
			printf("%c%c",c1,c2);
		printf("\n");
	}
	return 0;
}