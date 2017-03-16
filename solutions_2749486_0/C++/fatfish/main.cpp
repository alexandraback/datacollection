#include <stdio.h>
#include <math.h>

int toX, toY;

void inputData()
{
	scanf("%d%d", &toX, &toY);
}

void process(int cases)
{
	printf("Case #%d: ", cases);
	if (toX < 0)
	{
		for (int i = 0; i < abs(toX); ++ i)
		{
			printf("EW");
		}
	}

	if (toX > 0)
	{
		for (int i = 0; i < toX; ++ i)
		{
			printf("WE");
		}
	}

	if (toY < 0)
	{
		for (int i = 0; i < abs(toY); ++ i)
		{
			printf("NS");
		}
	}
	if (toY > 0)
	{
		for (int i = 0; i < toY; ++ i)
		{
			printf("SN");
		}
	}
	printf("\n");
}

int main()
{
	freopen("E:\\codejam\\B\\B-small-attempt1.in", "r", stdin);
	freopen("E:\\codejam\\B\\B.out", "w", stdout);

	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; ++ i)
	{
		inputData();
		process(i);
	}
	return 0;
}