#include <stdio.h>
#define L 100

int main()
{
	char table[128] = {};
	table[' '] = ' ';
	table['a'] = 'y';
	table['b'] = 'h';
	table['c'] = 'e';
	table['d'] = 's';
	table['e'] = 'o';
	table['f'] = 'c';
	table['g'] = 'v';
	table['h'] = 'x';
	table['i'] = 'd';
	table['j'] = 'u';
	table['k'] = 'i';
	table['l'] = 'g';
	table['m'] = 'l';
	table['n'] = 'b';
	table['o'] = 'k';
	table['p'] = 'r';
	table['q'] = 'z';
	table['r'] = 't';
	table['s'] = 'n';
	table['t'] = 'w';
	table['u'] = 'j';
	table['v'] = 'p';
	table['w'] = 'f';
	table['x'] = 'm';
	table['y'] = 'a';
	table['z'] = 'q';
	
	int t;
	char get[L+1];
	gets(get);
	sscanf(get, "%d", &t);
	for (int i=1;i<=t;++i)
	{
		gets(get);
		for (char *j=get;*j;++j)
			*j = table[*j];
		printf("Case #%d: %s\n", i, get);
	}
}
