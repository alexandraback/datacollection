#include<stdio.h>
#include<string.h>
int main()
{
	char map[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	char str[120];
	int t,i,j,cases;
	scanf("%d\n",&t);
	for(cases=1;cases<=t;cases++)
	{
		gets(str);
		printf("Case #%d: ",cases);
		for(i=0;i<strlen(str);i++)
		{
			if(str[i]>='a' && str[i]<='z')
				printf("%c",map[str[i]-'a']);
			else
				printf("%c",str[i]);
		}
		printf("\n");
	}
	return 0;
}
