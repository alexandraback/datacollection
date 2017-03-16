#include <stdio.h>

int main(void)
{
	char *decode = "yhesocvxduiglbkrztnwjpfmaq";
	int c, i = 2;
	while ((c = fgetc(stdin)) && c >= '0' && c <= '9');
	printf("Case #1: ");
	while ((c = fgetc(stdin)) != EOF) {
		if (c == '\n') {
			if ((c = fgetc(stdin)) == EOF) break;
			printf("\nCase #%d: ", i++);
		}
		printf("%c", (c >= 'a' && c <= 'z') ? decode[c - 'a'] : c);
	}
	printf("\n");
	return 0;
}
