#include<stdio.h>
#include<string.h>

char map[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

char inp[101];

char mapthis(char c)
{
	if (c < 'a' || c > 'z')
		return c;
	return map[c-'a'];
}

void mapall()
{
	int l = 0;
	int len = strlen (inp);
	for (l=0;l < len;l++)
	{
		inp[l] = mapthis(inp[l]);
	}
}


int main()
{
	int t,l;
	scanf("%d\n",&t);
	fflush (stdin);
	for(l=0;l<t;l++)
	{
//		scanf("%[^\n]\n",inp);
		gets(inp);
		mapall();
		printf("Case #%d: %s\n",l+1,inp);
	}
	return 0;
}
