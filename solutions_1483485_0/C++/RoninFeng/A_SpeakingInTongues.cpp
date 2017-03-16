#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	
	map<char, char> m;

	m['a'] = 'y';
	m['b'] = 'h';
	m['c'] = 'e';
	m['d'] = 's';
	m['e'] = 'o';
	
	m['f'] = 'c';
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
	
	m['z'] = 'q';
	m[' '] = ' ';

	string temp; 
	getline(cin, temp);
	for (int i = 0; i < temp.length(); i++) {
		cout << m[temp[i]];
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int T;
	cin >> T;
	string temp;
	getline(cin, temp);

	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": "; 
		solve(); 
		cout << endl;
	}

	return 0;
}