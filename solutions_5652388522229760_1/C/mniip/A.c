#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	int test;
	for(test = 1; test <= T; test++)
	{
		int N;
		scanf("%d", &N);
		int i;
		int digits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		for(i = 1; i <= 1000000; i++)
		{
			int pr = N * i;
			while(pr)
			{
				digits[pr % 10] = 1;
				pr /= 10;
			}
			int found = 0, d;
			for(d = 0; d < 10; d++)
				if(!digits[d])
				{
					found = 1;
					break;
				}
			if(!found)
			{
				printf("Case #%d: %d\n", test, N * i);
				break;
			}
		}
		if(i > 1000000)
			printf("Case #%d: INSOMNIA\n", test);
	}
}
