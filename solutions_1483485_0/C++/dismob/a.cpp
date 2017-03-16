
#include <iostream>

#include <vector>
#include <string>

#include <map>

using namespace std;

int tests;


map< char, char > cmap;
char mem[4096];

int main()
{
	cin >> tests;
	cin.getline( mem, sizeof(mem) );

	cmap['a'] = 'y';
	cmap['b'] = 'h';
	cmap['c'] = 'e';
	cmap['d'] = 's';
	cmap['e'] = 'o';
	cmap['f'] = 'c';
	cmap['g'] = 'v';
	cmap['h'] = 'x';
	cmap['i'] = 'd';
	cmap['j'] = 'u';
	cmap['k'] = 'i';
	cmap['l'] = 'g';
	cmap['m'] = 'l';
	cmap['n'] = 'b';
	cmap['r'] = 't';
	cmap['o'] = 'k';
	cmap['p'] = 'r';
	cmap['q'] = 'z';
	cmap['r'] = 't';
	cmap['s'] = 'n';
	cmap['t'] = 'w';
	cmap['u'] = 'j';
	cmap['v'] = 'p';
	cmap['w'] = 'f';
	cmap['x'] = 'm';
	cmap['y'] = 'a';
	cmap['z'] = 'q';

	for( int curTest=0; curTest<tests; ++curTest )
	{
		cin.getline( mem, sizeof(mem) );

		const int len = strlen( mem );
		for( int i=0; i<len; ++i )
		{
			if ( cmap.count( mem[i] ) )
			{
				mem[i] = cmap[mem[i]];
			}
		}

		cout << "Case #" << (curTest+1) << ": ";
		cout << mem;
		cout << endl;
	}

	return 0;
}

