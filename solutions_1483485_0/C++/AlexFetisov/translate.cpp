#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string s, t = "yhesocvxduiglbkrztnwjpfmaq";
int T;
            
int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	getline(cin, s);
	stringstream ss(s);
	ss >> T;
	for (int i = 1; i <= T; ++i) {
		getline(cin, s);
		for (int j = 0; j < s.length(); ++j) {
			if (s[j] == ' ') continue;
			int id = (s[j] - 'a');
			s[j] = t[id];
		}
		cout << "Case #" << i << ": " << s << endl;
	}
	return 0;
}