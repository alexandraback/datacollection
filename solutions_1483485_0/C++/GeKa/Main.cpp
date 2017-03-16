#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

char * inpp =  "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
char * outpp = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
char mapping[256];

int main()
{
	for (int i = 0; i < 256; i++)
		mapping[i] = 0;
	for (int i = 0; inpp[i] != 0; i++)
		if (inpp[i] != ' ')
			mapping[inpp[i]] = outpp[i];
	mapping['q'] = 'z';
	mapping['z'] = 'q';

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	char s[10000], p[10000];
	gets(s);
	for (int t = 0; t < T; t++)
	{		
		memset(p, 0, sizeof(char) * 10000);
		gets(s);
		for (int i = 0; s[i]; i++)
			if (s[i] != ' ')
				p[i] = mapping[s[i]];
			else
				p[i] = ' ';
		printf("Case #%d: %s\n", t+1, p);
	}

	return 0;
}