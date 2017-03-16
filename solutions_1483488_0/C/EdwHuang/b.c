#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char buf[64], *tmp;
	int i, j, len, a, b, cse = 1, space, count, t;
	int tab[10];
	while (fgetc(stdin) != '\n');
	while (fgets(buf, 64, stdin)) {
		tmp = strchr(buf, ' ');
		*tmp = '\0';
		len = strlen(buf);
		a = atoi(buf);
		b = atoi(++tmp);
		for (count = 0; a < b; a++) {
			for (i = 0; i < 10; i++) tab[i] = 0;
			sprintf(buf, "%d%d", a, a);
			for (i = len - 1; i >= 1; i--) {
				buf[i + len] = '\0';
				t = atoi(buf + i);
				tab[i] = t;
				if (t > a && t <= b) {
					count++;
					for (j = i + 1; j <= len; j++)
						if (t == tab[j]) {
							count--;
							break;
						}
				}
			}
		}
		printf("Case #%d: %d\n", cse++, count);
	}
	return 0;
}
