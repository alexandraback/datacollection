#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

char map[256];

void Solve()
{
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
map[' '] = ' ';
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		cout << map[s[i]];
	}
	cout << "\n";

}

int main()
{
	int nt, tt;
	cin >> nt;
	string s;
	getline(cin, s);
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Solve(); 
	}
	return 0;
}
