#include <stdio.h>
#include <string.h>

int main()
{
	int t, i, j, len;
	char input[1001], aux[1000], max;
	scanf("%d\n", &t);
	for(i=1;i<=t;i++)
	{
		scanf("%s\n", input);
		len=strlen(input);
		max=input[0];
		aux[0]='l';
		for(j=1;j<len;j++)
		{
			if(input[j]>=max)
			{
				max=input[j];
				aux[j]='l';
			}
			else
				aux[j]='r';
		}
		
		printf("Case #%d: ", i);

		for(j=len-1;j>=0;j--)
			if(aux[j]=='l')
				printf("%c", input[j]);

		for(j=0;j<len;j++)
			if(aux[j]=='r')
				printf("%c", input[j]);

		printf("\n");
	}

	return 0;
}
