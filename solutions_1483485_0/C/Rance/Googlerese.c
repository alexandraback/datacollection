#include <stdio.h>
#include <string.h>

int main()
{
	int cnt;
	char *ptn = "yhesocvxduiglbkrztnwjpfmaq";
	char g[102], e[102];
	int len;
	char idx;

	scanf("%d", &cnt);

	for (int i = 1; i <= cnt; i++)
	{
		fgets(g, sizeof(g), stdin);
		len = strlen(g);
		g[--len] = '\0';
		printf("Case #%d: ", i);

		for (int j = 0; j < len; j++)
		{
			if (g[j] == ' ')
				e[j] = ' ';
			else
			{
				idx = g[j] - 'a';
				e[j] = ptn[idx];
			}
		}

		e[len] = '\0';
		printf("%s\n", e);
	}

	return 0;
}
