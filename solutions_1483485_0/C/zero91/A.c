#include <stdio.h>
#include <ctype.h>

const char mapping[] = "yhesocvxduiglbkrztnwjpfmaq";

int
main (void)
{
	int T, ch;
	int i;

	scanf ("%d", &T);
	getchar();
	for (i = 1; i <= T; ++i) {
		printf ("Case #%d: ", i);
		while ((ch = getchar()) != '\n') {
			if (isalpha (ch)) {
				putchar (mapping[ch - 'a']);
			} else {
				putchar (ch);
			}
		}
		printf ("\n");
	}

	return 0;
}
