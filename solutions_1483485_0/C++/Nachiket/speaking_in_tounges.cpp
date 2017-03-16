#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>

using namespace std;


map<char, char> init()
{
	map<char, char> key;
	key['a'] = 'y';
	key['b'] = 'h';
	key['c'] = 'e';
	key['d'] = 's';
	key['e'] = 'o';
	key['f'] = 'c';
	key['g'] = 'v';
	key['h'] = 'x';
	key['i'] = 'd';
	key['j'] = 'u';
	key['k'] = 'i';
	key['l'] = 'g';
	key['m'] = 'l';
	key['n'] = 'b';
	key['o'] = 'k';
	key['p'] = 'r';
	key['q'] = 'z';
	key['r'] = 't';
	key['s'] = 'n';
	key['t'] = 'w';
	key['u'] = 'j';
	key['v'] = 'p';
	key['w'] = 'f';
	key['x'] = 'm';
	key['y'] = 'a';
	key['z'] = 'q';
	key[' '] = ' ';
	return key;
}

map<char, char> key = init();

void solve_case(void)
{
	string input;
	getline(cin, input);
	for (string::iterator it = input.begin(); it != input.end(); ++it) {
		cout << key[*it];
	}
}

int main()
{
	int T;
	string input;
	getline(cin, input);
	stringstream ss(input);
	ss >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": ";
		solve_case();
		cout << endl;
	}
	return 0;
}
