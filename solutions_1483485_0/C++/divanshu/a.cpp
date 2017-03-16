#include <iostream>
#include <map>

using namespace std;

int main() {

	map<char, char> m;
	int t, i, x;
	char s[150];

	m['y'] = 'a';
	m['n'] = 'b';
	m['f'] = 'c';
	m['i'] = 'd';
	m['c'] = 'e';
	m['w'] = 'f';
	m['l'] = 'g';
	m['b'] = 'h';
	m['k'] = 'i';
	m['u'] = 'j';
	m['o'] = 'k';
	m['m'] = 'l';
	m['x'] = 'm';
	m['s'] = 'n';
	m['e'] = 'o';
	m['v'] = 'p';
	m['z'] = 'q';
	m['p'] = 'r';
	m['d'] = 's';
	m['r'] = 't';
	m['j'] = 'u';
	m['g'] = 'v';
	m['t'] = 'w';
	m['h'] = 'x';
	m['a'] = 'y';
	m['q'] = 'z';
	m[' '] = ' ';

	cin >> t;

	getchar();

	for ( x = 1; x <= t; x++ ) {

		gets(s);

		cout << "Case #" << x << ": ";
		
		for ( i = 0; s[i] != '\0'; i++ ) {

			cout << m[s[i]];

		}

		cout << endl;

	}

	return 0;
}
