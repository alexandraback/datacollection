#include <cstdio>

char line[101];
char map[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main()
{
	int t;
	scanf("%d", &t);
	gets(line);
	for (int c=1; c<=t; ++c)
	{
		gets(line);
		printf("Case #%d: ", c);
		for (int i=0; line[i]!=0; ++i)
		{
			if (line[i] == ' ')
				putchar(' ');
			else
				putchar(map[line[i]-'a']);			
		}
		putchar('\n');
	}
	
	return 0;
}