#include<string.h>
#include<stdio.h>
int main()
{
	char test[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	char str[101];
	int t,j,i;
	scanf("%d\n",&t);
	fflush(stdin);
	for(i=0;i<t;i++)
	{
		gets(str);
		printf("Case #%d: ",i+1	);
		for(j=0;j<strlen(str);j++)
		{
			if(str[j]>='a' && str[j]<='z')
			{
				printf("%c",test[str[j]-'a']);
			}
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
