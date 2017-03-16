#include <stdio.h>
#include <string.h>

char s[] = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
char t[] = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
char map[256];
char a[1000];

int main()
{
	int cs, i, j;
	memset(map, 0, sizeof(map));
	for (i = 0; s[i]; i++)
		map[s[i]] = t[i];
	map['q'] = 'z';
	map['z'] = 'q';
	map[' '] = ' ';

	scanf("%d\n", &cs);
	for (i = 0; i < cs; i++) {
		gets(a);
		printf("Case #%d: ", i + 1);
		for (j = 0; a[j]; j++)
			printf("%c", map[a[j]]);
		printf("\n");
	}
	return 0;
}
