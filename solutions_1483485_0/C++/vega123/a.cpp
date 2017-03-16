#include<iostream>
#include<stdio.h>
using namespace std;
char str[27]="yhesocvxduiglbkrztnwjpfmaq";
int main()
{
	char str1[105];
	int i,j,t;
	scanf("%d\n",&t);
	for(i=1;i<=t;i++)
	{
		gets(str1);
		printf("Case #%d: ",i);
		int len=strlen(str1);
		for(j=0;j<len;j++)
			if(str1[j]>='a'&&str1[j]<='z')
				printf("%c",str[str1[j]-'a']);
			else printf("%c",str1[j]);
		printf("\n");

	}
	return 0;
}