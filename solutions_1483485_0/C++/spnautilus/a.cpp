#include <stdio.h>

#define maxc (256)
#define maxs (128)
#define maxt (32)

char map[maxc];

char s[maxs];
char s2[maxs];
int T;

int main()
{
/*	map['y'] = 'a';
	map['e'] = 'o';
	map['q'] = 'z';

	scanf("%d", &T);
	for(i = 0; i < T; ++i)
	{
		scanf("\n%[^\n]\n%[^\n]", s, s2);

		for(j = 0; s[j]; ++j)
		{
			if(s[j] >= 'a' && s[j] <= 'z')
			{
				map[s[j]] = s2[j];
			}
		}
	}

	for(i = 'a'; i <= 'z'; ++i)
	{
		printf("%c : %c (%d)\n", (char) i, map[i], (int) map[i]);
	}
*/

	map['a'] = 'y';
	map['b'] = 'h';
	map['c'] = 'e';
	map['d'] = 's';
	map['e'] = 'o';
	map['f'] = 'c';
	map['g'] = 'v';
	map['h'] = 'x';
	map['i'] = 'd';
	map['j'] = 'u';
	map['k'] = 'i';
	map['l'] = 'g';
	map['m'] = 'l';
	map['n'] = 'b';
	map['o'] = 'k';
	map['p'] = 'r';
	map['q'] = 'z';
	map['r'] = 't';
	map['s'] = 'n';
	map['t'] = 'w';
	map['u'] = 'j';
	map['v'] = 'p';
	map['w'] = 'f';
	map['x'] = 'm';
	map['y'] = 'a';
	map['z'] = 'q';

	int i;
	scanf("%d", &T);

	for(int tt = 1; tt <= T; ++tt)
	{
		scanf("\n%[^\n]", s);
		for(i = 0; s[i]; ++i)
		{
			if(s[i] != ' ')
				s[i] = map[s[i]];
		}
		printf("Case #%d: %s\n", tt, s);
	}

	return 0;
}
