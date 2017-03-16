#include <iostream>



using namespace std;


char s[100146];
char mp[1146];


void init()
{
	mp['a'] = 'y';
	mp['b'] = 'h';
	mp['c'] = 'e';
	mp['d'] = 's';
	mp['e'] = 'o';
	mp['f'] = 'c';
	mp['g'] = 'v';
	mp['h'] = 'x';
	mp['i'] = 'd';
	mp['j'] = 'u';
	mp['k'] = 'i';
	mp['l'] = 'g';
	mp['m'] = 'l';
	mp['n'] = 'b';
	mp['o'] = 'k';
	mp['p'] = 'r';
	mp['q'] = 'z';
	mp['r'] = 't';
	mp['s'] = 'n';
	mp['t'] = 'w';
	mp['u'] = 'j';
	mp['v'] = 'p';
	mp['w'] = 'f';
	mp['x'] = 'm';
	mp['y'] = 'a';
	mp['z'] = 'q';   
	mp[' '] = ' ';
}


void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d", &n);
	gets(s);
	init();
	for(int i = 0; i < n; i++)
	{
		gets(s);
		int len = strlen(s);            
		for(int j = 0; j < len; j++)
		{               
			s[j] = mp[s[j]];
		}
		printf("Case #%d: %s\n", i + 1, s);
	}
}
