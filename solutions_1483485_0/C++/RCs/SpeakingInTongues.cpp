#include <stdio.h>

int main()
{
	char mapping[256];
	mapping['a'] = 'y';
	mapping['b'] = 'h';
	mapping['c'] = 'e';
	mapping['d'] = 's';
	mapping['e'] = 'o';
	mapping['f'] = 'c';
	mapping['g'] = 'v';
	mapping['h'] = 'x';
	mapping['i'] = 'd';
	mapping['j'] = 'u';
	mapping['k'] = 'i';
	mapping['l'] = 'g';
	mapping['m'] = 'l';
	mapping['n'] = 'b';
	mapping['o'] = 'k';
	mapping['p'] = 'r';
	mapping['q'] = 'z';
	mapping['r'] = 't';
	mapping['s'] = 'n';
	mapping['t'] = 'w';
	mapping['u'] = 'j';
	mapping['v'] = 'p';
	mapping['w'] = 'f';
	mapping['x'] = 'm';
	mapping['y'] = 'a';
	mapping['z'] = 'q';
	mapping[' '] = ' ';

	char input[1000];
	int numCase, cases, i;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%i\n", &cases);
	for(numCase = 1; numCase <= cases; numCase++)
	{
		gets(input);
		printf("Case #%i: ", numCase);
		for(i = 0; input[i]; i++)
			printf("%c", mapping[input[i]]);
		printf("\n");
	}

	return 0;
}