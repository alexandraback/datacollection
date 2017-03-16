#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char map[]="yhesocvxduiglbkrztnwjpfmaq";
char st[500],str[500];
int main()
{
	int t,i,j;
//	freopen("d:\\gcj\\a.in","r",stdin);
//	freopen("d:\\gcj\\a.out","w",stdout);
	scanf("%d",&t);
	getchar();
	for(i=1;i<=t;i++)
	{
		gets(st);
		printf("Case #%d: ",i);
		for(j=0;j<strlen(st);j++)
			if(st[j]!=' ')
				str[j]=map[st[j]-'a'];
			else
				str[j]=st[j];
		str[j]='\0';
		puts(str);
	}
	return 0;
}