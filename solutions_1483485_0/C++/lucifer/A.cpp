#include <stdio.h>
#include <cstring>

char a[] = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
char b[] = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

int mark[300], len, n, t[300], vis[300];
char s[200];

int main() {
	len = strlen(a);
	memset(mark, -1, sizeof mark);
	memset(vis, -1, sizeof vis);
	for(int i=0; i<len; ++i) {
		mark[a[i]] = b[i];
		vis[b[i]] = 1;
	}

	int t;
	scanf("%d\n", &t);
	for(int x=1; x<=t; ++x) {
		gets(s);
		printf("Case #%d: ", x);
		for(int i=0; s[i]; ++i) {
			if(s[i] == ' ') printf(" ");
			else if(s[i] == 'q') printf("z");
			else if(s[i] == 'z') printf("q");
			else printf("%c", mark[s[i]]);
		}
		puts("");
	}

	return 0;
}

