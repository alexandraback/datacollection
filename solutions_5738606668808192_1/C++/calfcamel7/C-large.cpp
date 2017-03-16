#include <stdio.h>

char str[100];
int main()
{
	puts("Case #1:");
	freopen("C-small-all.out","r",stdin);
	for(int i = 0; i < 500; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			scanf("%s", str);
			if(j) printf(" ");
			printf("%s", str);
			if(j == 0)
				printf("%s", str);
		}
		puts("");
	}
}