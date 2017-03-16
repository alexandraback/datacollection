#include <stdio.h>
char m[27] = "yhesocvxduiglbkrztnwjpfmaq";
char s[101];
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int t;
	scanf("%d",&t);
	gets(s);
	for(int tt = 1; tt <=t; ++tt)
	{
		gets(s);
//		puts(s);
//		continue;
		for(int i = 0; s[i];++i)
		{
			if(s[i]!=' ')s[i]=m[s[i]-'a'];
		}
		printf("Case #%d: %s\n",tt,s);
	}
	return 0;
}
