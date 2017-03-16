#include <stdio.h>
using namespace std;

char map[1000];

int main()
{
	int i;
	for(i='a'; i<='z'; i++) map[i] = '?';
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

	char buf[102400];
	int ca,cc;
	scanf("%d", &ca); fgets(buf, 102400, stdin);
	for(cc=1; cc<=ca; cc++)
	{
		fgets(buf, 102400, stdin);
		printf("Case #%d: ", cc);
		char *p;
		p = buf;
		while(*p != '\n')
		{
			if (*p != ' ')
				printf("%c", map[*p]);
			else
				printf(" ");
			p++;
		}
		printf("\n");
	}	
}
