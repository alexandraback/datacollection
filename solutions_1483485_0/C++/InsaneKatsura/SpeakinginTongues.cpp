#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

map<char, char> m;
int x = 0;

int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
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
	int T;
	string str;
	cin >> T;
	getchar();
	while (T--)
	{
		getline(cin, str);
		cout << "Case #" << ++x << ": ";
		int n = str.length();
		for (int i = 0; i < n; i++)
		{
			cout << m[str[i]];
		}
		cout << '\n';
	}
	return 0;
}
