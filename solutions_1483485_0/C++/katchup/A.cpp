/*
	GOOGLE CODE JAM
	Contestant 			: Alex "katchup" AUVOLAT
	Contest reference	: 
	Problem				: 
*/



#include <iostream>
#include <map>

using namespace std;

void one_case(map<char, char> &table) {
	string s;
	getline(cin, s);

	for (unsigned i = 0; i < s.length(); i++) {
		if (table.count(s[i]) > 0) {
			cout << table[s[i]];
		} else {
			cout << s[i];
		}
	}
}

int main(int argc, char *argv[]) {

	int cases;
	cin >> cases;

	string l;
	getline(cin, l);	// eat end of line

	map<char, char> t;
	t['y'] = 'a';
	t['n'] = 'b';
	t['f'] = 'c';
	t['i'] = 'd';
	t['c'] = 'e';
	t['w'] = 'f';
	t['l'] = 'g';
	t['b'] = 'h';
	t['k'] = 'i';
	t['u'] = 'j';
	t['o'] = 'k';
	t['m'] = 'l';
	t['x'] = 'm';
	t['s'] = 'n';
	t['e'] = 'o';
	t['v'] = 'p';
	t['z'] = 'q';
	t['p'] = 'r';
	t['d'] = 's';
	t['r'] = 't';
	t['j'] = 'u';
	t['g'] = 'v';
	t['t'] = 'w';
	t['h'] = 'x';
	t['a'] = 'y';
	t['q'] = 'z';

	for (int i = 0; i < cases; i++) {
		cout << "Case #" << (i+1) << ": ";
		one_case(t);
		cout << endl;
	}

	return 0;
}

