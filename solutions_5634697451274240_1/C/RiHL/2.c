#include <stdio.h>

char peekchar(void)
{
	char c = getchar();
	ungetc(c, stdin);
	return c;
}

void vyres(void)
{
	int n;
	char p = peekchar();
	char c;
	int s = 0;
	while ((c = getchar()) != '\n'){
		if (p != c)
			s++;

		p = c;
	}

	if (p == '-')
		s++;

	printf("%d\n", s);
}

int main(void)
{
	int t;
	scanf("%d\n", &t);
	for (int i=0; i<t; i++){
		printf("Case #%d: ", i + 1);
		vyres();
	}
}
