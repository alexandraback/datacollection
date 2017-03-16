#include <stdio.h>

char a[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jvzq";
char b[] = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give upqz";

char m[255];
int n, i, kejs;
char s[200];

int main() {
	for (i = 0; a[i]; i++) {
		m[(int)a[i]] = b[i];
	}
	/*
	for (i = 'a'; i <= 'z'; i++) {
		printf("%c: %d\n", i, (int)m[i]);
	}
	*/
	scanf("%d%*c", &n);
	for (kejs = 1; kejs <= n; kejs++) {
		fgets(s, 200, stdin);
		for (i = 0; s[i]; i++) {
			if (m[(int)s[i]]) s[i] = m[(int)s[i]];
		}
		printf("Case #%d: %s", kejs, s);
	}
	return 0;
}
