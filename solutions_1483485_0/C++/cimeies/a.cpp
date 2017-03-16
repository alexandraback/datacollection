#include <stdio.h>

int main()
{
	int n;
	scanf("%d\n", &n);
	const char *map = "yhesocvxduiglbkrztnwjpfmaq";
	for (int i = 0; i < n; )
	{
		printf("Case #%d: ", ++i);
		for (char c = 0; !feof(stdin) && c != '\n'; scanf("%c", &c))
		{
			if (c == ' ' || (c >= 'a' && c <= 'z'))
			{
				printf("%c", c == ' ' ? c : map[c - 'a']);
			}
		}
		printf("\n");
	}
	return 0;
}
