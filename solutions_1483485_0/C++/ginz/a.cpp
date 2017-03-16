#include <iostream>
#include <fstream>

using namespace std;

int main() {
	char trans_back[26] = {'y' /*a*/, 'h' /*b*/, 'e' /*c*/, 's' /*d*/, 'o' /*e*/, 'c' /*f*/, 'v' /*g*/, 'x' /*h*/, 'd' /*i*/, 'u' /*j*/, 'i' /*k*/, 'g' /*l*/, 'l' /*m*/, 'b' /*n*/, 'k' /*o*/, 'r' /*p*/, 'z' /*q*/, 't' /*r*/, 'n' /*s*/, 'w' /*t*/, 'j' /*u*/, 'p' /*v*/, 'f' /*w*/, 'm' /*x*/, 'a' /*y*/, 'q' /*z*/};
	int t;
	string s;
	cin >> t;
	getline (cin, s);
	for (int i = 0; i < t; ++i) {
		getline (cin, s);
		for (unsigned int j = 0; j < s.length(); ++j) {
			if ('a' <= s[j] && s[j] <= 'z')
				s[j] = trans_back [s[j] - 'a'];
		}
		cout << "Case #" << i + 1 << ": " << s << endl;
	}
	return 0;
}
