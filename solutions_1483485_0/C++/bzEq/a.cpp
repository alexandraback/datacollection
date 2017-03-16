#include <stdio.h>
char m[26]={'y','h','e','s','o',
	    'c','v','x','d','u',
	    'i','g','l','b','k',
	    'r','z','t','n','w',
	    'j','p','f','m','a',
	    'q'},buf[110];
int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);
	int T;
	scanf("%d\n",&T);
	for (int tt=1; tt<=T; tt++) {
		printf("Case #%d: ",tt);
		gets(buf);
		for (int i=0; buf[i]; i++)
			if (buf[i]!=' ')
				putchar(m[buf[i]-'a']);
			else
				putchar(' ');
		putchar('\n');
	}
}
