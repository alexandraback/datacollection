#include <stdio.h>

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("s.out", "w", stdout);

	int t, cas;
	int x, y;
	
	scanf("%d", &t);
	for (cas=1; cas<=t; cas++)
	{
		scanf("%d%d", &x, &y);
		printf("Case #%d: ", cas);

		if (x<0)
		{
			for(int i=0; i<0-x; i++)
				printf("EW");
		}
		else
		{
			for(int i=0; i<x; i++)
				printf("WE");
		}

		if (y<0)
		{
			for(int i=0; i<0-y; i++)
				printf("NS");
		}
		else
		{
			for(int i=0; i<y; i++)
				printf("SN");
		}
		printf("\n");
	}
	return 0;
}