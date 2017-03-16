//2012-04-14T08:25:01

#include <iostream>
using namespace std;

char codes[26];


int main(int argc, char const* argv[])
{

codes['e' - 'a'] = 'o';
codes['j' - 'a'] = 'u';
codes['p' - 'a'] = 'r';
codes['m' - 'a'] = 'l';
codes['y' - 'a'] = 'a';
codes['s' - 'a'] = 'n';
codes['l' - 'a'] = 'g';
codes['j' - 'a'] = 'u';
codes['y' - 'a'] = 'a';
codes['l' - 'a'] = 'g';
codes['c' - 'a'] = 'e';
codes['k' - 'a'] = 'i';
codes['d' - 'a'] = 's';
codes['k' - 'a'] = 'i';
codes['x' - 'a'] = 'm';
codes['v' - 'a'] = 'p';
codes['e' - 'a'] = 'o';
codes['d' - 'a'] = 's';
codes['d' - 'a'] = 's';
codes['k' - 'a'] = 'i';
codes['n' - 'a'] = 'b';
codes['m' - 'a'] = 'l';
codes['c' - 'a'] = 'e';
codes['r' - 'a'] = 't';
codes['e' - 'a'] = 'o';
codes['j' - 'a'] = 'u';
codes['s' - 'a'] = 'n';
codes['i' - 'a'] = 'd';
codes['c' - 'a'] = 'e';
codes['p' - 'a'] = 'r';
codes['d' - 'a'] = 's';
codes['r' - 'a'] = 't';
codes['y' - 'a'] = 'a';
codes['s' - 'a'] = 'n';
codes['i' - 'a'] = 'd';
codes['r' - 'a'] = 't';
codes['b' - 'a'] = 'h';
codes['c' - 'a'] = 'e';
codes['p' - 'a'] = 'r';
codes['c' - 'a'] = 'e';
codes['y' - 'a'] = 'a';
codes['p' - 'a'] = 'r';
codes['c' - 'a'] = 'e';
codes['r' - 'a'] = 't';
codes['t' - 'a'] = 'w';
codes['c' - 'a'] = 'e';
codes['s' - 'a'] = 'n';
codes['r' - 'a'] = 't';
codes['a' - 'a'] = 'y';
codes['d' - 'a'] = 's';
codes['k' - 'a'] = 'i';
codes['h' - 'a'] = 'x';
codes['w' - 'a'] = 'f';
codes['y' - 'a'] = 'a';
codes['f' - 'a'] = 'c';
codes['r' - 'a'] = 't';
codes['e' - 'a'] = 'o';
codes['p' - 'a'] = 'r';
codes['k' - 'a'] = 'i';
codes['y' - 'a'] = 'a';
codes['m' - 'a'] = 'l';
codes['v' - 'a'] = 'p';
codes['e' - 'a'] = 'o';
codes['d' - 'a'] = 's';
codes['d' - 'a'] = 's';
codes['k' - 'a'] = 'i';
codes['n' - 'a'] = 'b';
codes['k' - 'a'] = 'i';
codes['m' - 'a'] = 'l';
codes['k' - 'a'] = 'i';
codes['r' - 'a'] = 't';
codes['k' - 'a'] = 'i';
codes['c' - 'a'] = 'e';
codes['d' - 'a'] = 's';
codes['d' - 'a'] = 's';
codes['e' - 'a'] = 'o';
codes['k' - 'a'] = 'i';
codes['r' - 'a'] = 't';
codes['k' - 'a'] = 'i';
codes['d' - 'a'] = 's';
codes['e' - 'a'] = 'o';
codes['o' - 'a'] = 'k';
codes['y' - 'a'] = 'a';
codes['a' - 'a'] = 'y';
codes['k' - 'a'] = 'i';
codes['w' - 'a'] = 'f';
codes['a' - 'a'] = 'y';
codes['e' - 'a'] = 'o';
codes['j' - 'a'] = 'u';
codes['t' - 'a'] = 'w';
codes['y' - 'a'] = 'a';
codes['s' - 'a'] = 'n';
codes['r' - 'a'] = 't';
codes['r' - 'a'] = 't';
codes['e' - 'a'] = 'o';
codes['u' - 'a'] = 'j';
codes['j' - 'a'] = 'u';
codes['d' - 'a'] = 's';
codes['r' - 'a'] = 't';
codes['l' - 'a'] = 'g';
codes['k' - 'a'] = 'i';
codes['g' - 'a'] = 'v';
codes['c' - 'a'] = 'e';
codes['j' - 'a'] = 'u';
codes['v' - 'a'] = 'p';
codes['z' - 'a'] = 'q';
codes['q' - 'a'] = 'z';

	int T;
	cin >> T;
	cin.ignore();
	for (int ii = 0; ii < T; ii++) {
		string line;
		getline(cin, line);
		string ans = "";

		for (int i = 0; i < line.length(); i++) {
			if (line.at(i) != ' ') {
				ans += codes[line.at(i) - 'a'];
			} else {
				ans += ' ';
			}
		}

		cout << "Case #" << ii + 1 << ": " << ans << endl;
	}
	return 0;
}

//2012-04-14T08:53:20
