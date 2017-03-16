#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MID 350
#define MAX(a, b)    ((a) > (b) ? (a) : (b))
using namespace std;

int dest_x, dest_y;


int main()
{
	bool flag;
	int cas, t;
	int i, len, y, dist;
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++)
	{
		scanf("%d%d", &dest_x, &dest_y);
		printf("Case #%d: ", cas);
		if (dest_x > 0)
		{
			for (i = 0; i < dest_x - 1; i++)
				printf("EW");
			printf("E");
		}
		else if (dest_x < 0)
		{
			for (i = 0; i < abs(dest_x) - 1; i++)
				printf("WE");
			printf("W");
		}
		len = 2 * abs(dest_x);
		if (dest_y == 0)
			printf("\n");
		else
		{
			if (dest_y > 0)
			{
				y = -len;
				printf("S");
			}
			else
			{
				y = len;
				printf("N");
			}
			dist = abs(y - dest_y);
			//printf("%d %d %d\n", y, dest_y, dist);
			dist -= len;
			if (dest_y > y)
			{
				for (i = 0; i < dist - 1; i++)
					printf("NS");
				printf("N");
			}
			else
			{
				for (i = 0; i < dist - 1; i++)
					printf("SN");
				printf("S");
			}
			printf("\n");
		}
		
	}
	return 0;
}
