#include <stdio.h>

int main(void)
{
	int t[256], i, j, v[256];
	char s1[1024], s2[1024];
	for (i = 0; i < 256; i++) t[i] = i, v[i] = 0;
	for (i = 'a'; i <= 'z'; i++) t[i] = '*';
	t['y'] = 'a';
	t['e'] = 'o';
	t['q'] = 'z';
	for (i = 0; i < 3; i++) {
		gets(s1);
		gets(s2);
		for (j = 0; s1[j]; j++) {
			t[s1[j]] = s2[j];
		}
	}
	for (i = 'a'; i <= 'z'; i++) v[t[i]] = 1;
	for (i = 'a'; i <= 'z'; i++) if (!v[i]) t['z'] = i;
	for (i = 'a'; i <= 'z'; i++) printf("%c", t[i]);
	printf("\n");
	return 0;
}
