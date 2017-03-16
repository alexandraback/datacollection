#include <stdio.h>
#include <string.h>
char mapping[] = "yhesocvxduiglbkrztnwjpfmaq";
int main()
{
	int n;
	char line[1024];
	gets(line);
	sscanf(line, "%d", &n);
	for (int nc = 1; nc <= n; nc++)
	{
		gets(line);
		int len = strlen(line);
		for (int i = 0; i < len; i++)
		{
			if ('a' <= line[i] && line[i] <= 'z')
			{
				line[i] = mapping[line[i] - 'a'];
			}
		}

		printf("Case #%d: %s\n", nc, line);
	}

	return 0;
}
