#include <iostream>
#include <string>
using namespace std;

int main()
{
	char a[100];
	a['y' - 'a'] = 'a';
	a['n' - 'a'] = 'b';
	a['f' - 'a'] = 'c';
	a['i' - 'a'] = 'd';
	a['c' - 'a'] = 'e';
	a['w' - 'a'] = 'f';
	a['l' - 'a'] = 'g';
	a['b' - 'a'] = 'h';
	a['k' - 'a'] = 'i';
	a['u' - 'a'] = 'j';
	a['o' - 'a'] = 'k';
	a['m' - 'a'] = 'l';
	a['x' - 'a'] = 'm';
	a['s' - 'a'] = 'n';
	a['e' - 'a'] = 'o';
	a['v' - 'a'] = 'p';
	a['p' - 'a'] = 'r';
	a['d' - 'a'] = 's';
	a['r' - 'a'] = 't';
	a['j' - 'a'] = 'u';
	a['g' - 'a'] = 'v';
	a['t' - 'a'] = 'w';
	a['h' - 'a'] = 'x';
	a['a' - 'a'] = 'y';
	a['q' - 'a'] = 'z';
	a['z' - 'a'] = 'q';
	int T, ca = 0;
	string s;
	cin >> T;
	getline(cin, s);
	while (T--) {
		getline(cin, s);
		int n = s.size();
		cout << "Case #" << ++ca << ": ";
		for (int i = 0; i < n; ++i) {
			if (s[i] == ' ') cout << ' '; else 
			cout << a[s[i] - 'a'];
		}
		cout << endl;
	}
	return 0;
}
