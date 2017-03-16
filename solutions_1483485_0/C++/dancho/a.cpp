#include <cstdio>
#include <cstring>

char m[256];

char in[1024];

int main()
{
	int t, T;
	
	m['a'] = 'y';
	m['b'] = 'h';
	m['c'] = 'e';
	m['d'] = 's';
	m['e'] = 'o';
	m['f'] = 'c'; //
	m['g'] = 'v';
	m['h'] = 'x';
	m['i'] = 'd';
	m['j'] = 'u';
	m['k'] = 'i';
	m['l'] = 'g';
	m['m'] = 'l';
	m['n'] = 'b';
	m['o'] = 'k';
	m['p'] = 'r';
	m['q'] = 'z';
	m['r'] = 't';
	m['s'] = 'n';
	m['t'] = 'w';
	m['u'] = 'j';
	m['v'] = 'p';
	m['w'] = 'f';
	m['x'] = 'm';
	m['y'] = 'a';
	m['z'] = 'q'; //
	
	scanf( "%d", &T );
		fgets( in, 1000, stdin );
	for ( t = 1; t <= T; t++ )
	{
		fgets( in, 1000, stdin );
		for (int i = 0; i < (int)strlen( in ); i++)
		{
			if ( ( in[i] >= 'a' ) && ( in[i] <= 'z' ) )
				in[i] = m[ (int)in[i] ];
		}
		printf( "Case #%d: %s", t, in );
	}
	return 0;
}
