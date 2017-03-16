#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	map<char,char> mymap;
	mymap['a'] = 'y';
	mymap['b'] = 'h';
	mymap['c'] = 'e';
	mymap['d'] = 's';
	mymap['e'] = 'o';
	mymap['f'] = 'c';
	mymap['g'] = 'v';
	mymap['h'] = 'x';
	mymap['i'] = 'd';
	mymap['j'] = 'u';
	mymap['k'] = 'i';
	mymap['l'] = 'g';
	mymap['m'] = 'l';
	mymap['n'] = 'b';
	mymap['o'] = 'k';
	mymap['p'] = 'r';
	mymap['q'] = 'z';
	mymap['r'] = 't';
	mymap['s'] = 'n';
	mymap['t'] = 'w';
	mymap['u'] = 'j';
	mymap['v'] = 'p';
	mymap['w'] = 'f';
	mymap['x'] = 'm';
	mymap['y'] = 'a';
	mymap['z'] = 'q';
	mymap[' '] = ' ';
	string s,o,sT;
	int T;
	cin >> T;
	getline(cin,s);
	for (int i = 0; i < T; i++) {
		getline(cin,s);
		for ( int j = 0; j < s.length(); j++ ) {
			o+= mymap[s[j]];
		}
		cout << "Case #" << i+1 << ": " << o << endl;
		o = "";
	}
}
