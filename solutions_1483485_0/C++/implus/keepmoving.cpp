#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

char s[28]={'y','h','e','s','o','c','v','x','d','u','i','g','l'	,'b','k','r','z','t','n','w','j','p','f','m','a','q'};
char str[300];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	getchar();
	for (int i=0;i<n;i++)
	{
		gets(str);
		for(int j=0;j<strlen(str);j++)if(str[j]!=' ')
			str[j]=s[str[j]-'a'];

		printf("Case #%d: %s\n",i+1,str);
	}
	return 0;
}
