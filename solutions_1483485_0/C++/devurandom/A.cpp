#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[] = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvy qee";
char t[] = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upa zoo";

char map[255];
int main() {
	int n = strlen(s);
	for(int i=0; i<n; i++) {
		map[(int)s[i]] = t[i];
	}
	map[(int)'z'] = 'q';
//	for(char c='a'; c<='z'; c++)
//		printf("%c %c\n", c, map[(int)c]);

	int T;
	scanf("%d\n", &T);
	char line[10000];
	for(int t=1; t<=T; t++) {
		gets(line);
		
		int n = strlen(s);
		for(int i=0; i<n; i++) {
			line[i] = map[(int)line[i]];
		}
		printf("Case #%d: %s\n", t, line);
	}
}
