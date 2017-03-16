#include <stdio.h>
#include <string.h>

char lib[521196][11];
int liblen[521196];
char string[4001];
int d[4001];

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int abs(int a)
{
	return (a < 0) ? -a : a;
}

int main()
{
	freopen("garbled_email_dictionary.txt", "r", stdin);
	int c = 0;
	while(1)
	{
		if(scanf("%s", lib[c]) == -1) break;
		liblen[c] = strlen(lib[c]);
		c++;
	}
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, t, s, len, m;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%s", string);
		len = strlen(string);
		d[0] = 0;
		for(j = 1; j <= len; j++) d[j] = 10000000;
		for(j = 0; j < len; j++)
		{
			for(s = 0; s < 521196; s++)
			{
				if(len - j >= liblen[s])
				{
					c = 0;
					int last = -10;
					for(m = 0; m < liblen[s]; m++)
					{
						if(string[j + m] != lib[s][m])
						{
							if(m - last < 5) break;
							last = m;
							c++;
						}
					}
					if(m == liblen[s])
					{
						d[j + liblen[s]] = min(d[j + liblen[s]], d[j] + c);
					}
				}
			}
		}
		printf("Case #%d: %d\n", i + 1, d[len]);
	}
	return 0;
}
