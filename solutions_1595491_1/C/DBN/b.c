#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int num, n, s, p, score, count;
	int i, j;
	scanf("%d", &num);
	for(i = 0; i < num; ++i)
	{
		scanf("%d %d %d", &n, &s, &p);
		count = 0;
		for(j = 0; j < n; ++j)
		{
			scanf("%d", &score);
			if(score >= p*3-2)
			{
				++count;
			}
			else if(s > 0 && score >= p*3-4 && p*3-4 >= 0)
			{
				++count;
				--s;
			}
		}
	
		printf("Case #%d: %d\n", i+1, count);	
	}

	return 0;
}