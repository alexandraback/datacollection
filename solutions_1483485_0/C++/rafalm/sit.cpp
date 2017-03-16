#include <cstdio>

int main()
{
	const char map[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i',
		'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
	int i, j, T;
	char ch, G[102];

	scanf("%d", &T);
	for (i = 1; i <= T; i++)
	{
		do
		{
			scanf("%c", &ch);
		}
		while (ch < 'a' || ch > 'z');
		
		j = 0;
		G[j++] = map[(ch - 'a')];
		
		do
		{
			scanf("%c", &ch);
			if (ch >= 'a' && ch <= 'z')
			{
				G[j++] = map[(ch - 'a')];
			}
			else if (ch == ' ')
			{
				G[j++] = ' ';
			}
		}
		while ((ch >= 'a' && ch <= 'z') || ch == ' ');

		G[j] = '\0';

		printf("Case #%d: %s\n", i, G);
	}

	return 0;
}
