#include <stdio.h>

int main(void) {
	char t[256] = {0}, q[] = "yhesocvxduiglbkrztnwjpfmaq";
	char s[1024];
	int i, j, tn, ti;
	scanf("%d\n", &tn);
	for (i = 0; i < 26; i++) t[i+'a'] = q[i];
	t[' '] = ' ';
	for (ti = 1; ti <= tn; ti++) {
		printf("Case #%d: ", ti);
		gets(s);
		for (j = 0; t[s[j]]; j++) {
			printf("%c", t[s[j]]);
		}
		printf("\n");
	}
	return 0;
}
