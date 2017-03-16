// Speaking in Tongues.cpp
//

#include <cstdio>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char* argv[])
{
	// Build the cypher map

	map<char,char> cypherMap;

	cypherMap['y'] = 'a';
	cypherMap['n'] = 'b';
	cypherMap['f'] = 'c';
	cypherMap['i'] = 'd';
	cypherMap['c'] = 'e';
	cypherMap['w'] = 'f';
	cypherMap['l'] = 'g';
	cypherMap['b'] = 'h';
	cypherMap['k'] = 'i';
	cypherMap['u'] = 'j';
	cypherMap['o'] = 'k';
	cypherMap['m'] = 'l';
	cypherMap['x'] = 'm';
	cypherMap['s'] = 'n';
	cypherMap['e'] = 'o';
	cypherMap['v'] = 'p';
	cypherMap['z'] = 'q';
	cypherMap['p'] = 'r';
	cypherMap['d'] = 's';
	cypherMap['r'] = 't';
	cypherMap['j'] = 'u';
	cypherMap['g'] = 'v';
	cypherMap['t'] = 'w';
	cypherMap['h'] = 'x';
	cypherMap['a'] = 'y';
	cypherMap['q'] = 'z';
	cypherMap[' '] = ' ';

	int numTests = 0;
	scanf("%d\n", &numTests);
	for( int j = 0; j < numTests; ++j )
	{
		string str;
		getline(cin, str);
		printf("Case #%d: ", j+1 );
		unsigned int i = 0;
		while(i < str.size() )
		{
			putchar( cypherMap[str[i]] );
			++i;
		}
		if( j < (numTests-1) )
			putchar('\n');
	}

	return 0;
}

