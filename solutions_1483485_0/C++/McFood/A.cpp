#include <iostream>
#include <string>
#include <map>

using namespace std;

#define for0(i,n) for( int i = 0; i < (n); i++)


void main()
{

	int T;
	cin >> T;

	map<char, char> Ginv;

	{
		Ginv['a'] = 'y';
		Ginv['b'] = 'n';
		Ginv['c'] = 'f';
		Ginv['d'] = 'i';
		Ginv['e'] = 'c';
		Ginv['f'] = 'w';
		Ginv['g'] = 'l';
		Ginv['h'] = 'b';
		Ginv['i'] = 'k';
		Ginv['j'] = 'u';
		Ginv['k'] = 'o';
		Ginv['l'] = 'm';
		Ginv['m'] = 'x';
		Ginv['n'] = 's';
		Ginv['o'] = 'e';
		Ginv['p'] = 'v';
		Ginv['q'] = 'z';
		Ginv['r'] = 'p';
		Ginv['s'] = 'd';
		Ginv['t'] = 'r';
		Ginv['u'] = 'j';
		Ginv['v'] = 'g';
		Ginv['w'] = 't';
		Ginv['x'] = 'h';
		Ginv['y'] = 'a';
		Ginv['z'] = 'q';
	}
	map<char,char> G;
	for( char c = 'a'; c <= 'z'; ++c)
	{
		G[Ginv[c]] = c;

	}

	for0( CASE, T)
	{
		string line;
		getline((cin >> ws), line);

		for0(i, line.size())
		{
			line[i] = G[line[i]];
		}
		cout << "Case #" << CASE + 1 << ": " << line << endl;
	}


}