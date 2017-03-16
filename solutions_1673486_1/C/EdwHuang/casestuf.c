#include <stdio.h>

int main(void)
{
	int c, cse = 1;
	printf("Case #1: ");
	while ((c = getchar()) != EOF) {
		putchar(c);
		if (c == '\n' && (c = getchar()) != EOF)
			printf("Case #%d: %c", ++cse, c);
	}
	return 0;
}
