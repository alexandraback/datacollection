#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k'
,'r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	char ch[105];
	int t,len,i,co=1;
	scanf("%d",&t);
	getchar();
	while (t--)
	{
		gets(ch);
		len=strlen(ch);
		for (i=0;i<len;i++)
			if (ch[i]!=' ')
				ch[i]=str[ch[i]-'a'];
		printf("Case #%d: %s\n",co++,ch);
	}
	return 0;
}