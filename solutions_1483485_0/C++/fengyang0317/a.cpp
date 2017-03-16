#include <stdio.h>
#include <string.h>
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	char s[26];
	char x[999];
	strcpy(s,"yhesocvxduiglbkrztnwjpfmaq");
	int i,t,k;
	scanf("%d",&t);
	getchar();
	for(k=1;k<=t;k++)
	{
		gets(x);
		i=0;
		while(x[i])
		{
			if(x[i]<='z'&&x[i]>='a')x[i]=s[x[i]-'a'];
			i++;
		}
		printf("Case #%d: ",k);
		puts(x);
	}
	return 0;
}