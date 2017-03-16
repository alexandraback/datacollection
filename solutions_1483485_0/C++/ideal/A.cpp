#include <stdio.h>
char text[80] = "yhesocvxduiglbkrztnwjpfmaq";

void verse(char *s) {
	int i;
	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] != ' ')
			s[i] = text[s[i] - 'a'];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("E:\\test\\codejam\\A-small-attempt0.in", "r", stdin);
	freopen("E:\\test\\codejam\\test.out", "w", stdout);
#endif

	char str[800];
	int i, T;
	scanf("%d", &T);
	getchar();
	for (i = 1; i <= T; ++i) {
		gets(str);
		verse(str);
		printf("Case #%d: %s\n", i, str);
	}
	return 0;
}