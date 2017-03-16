#include<stdio.h>

char *input = "zqeyejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
char *output = "qzoaour language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

int u[256];
char s[10000];

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	for(int i=0; input[i]; i++) {
		u[input[i]] = output[i];
	}

	int ntest;
	scanf("%d", &ntest); gets(s);
	for(int test = 1; test <= ntest; test++) {
		gets(s);
		printf("Case #%d: ", test);
		for(int i=0; s[i]; i++) printf("%c", u[s[i]]);
		printf("\n");
	}

	return 0;
}