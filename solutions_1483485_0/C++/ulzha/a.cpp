#include <iostream>
using namespace std;

char m[] = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
	int nc, ic, i;
	string s, t;
	
	cin >> nc;
	getline(cin, s);
	for (ic = 1; ic <= nc; ic++) {
		getline(cin, s);
/*
		getline(cin, t);
		for (i = 0; i < s.size(); i++) if (s[i] >= 'a' && s[i] <= 'z') {
			m[s[i] - 'a'] = t[i];
		}
*/
		cout << "Case #" << ic << ": ";
		for (i = 0; i < s.size(); i++) {
			cout << (s[i] >= 'a' && s[i] <= 'z' ? m[s[i] - 'a'] : s[i]);
		}
		cout << endl;
	}
/*
	for (i = 0; i < 26; i++) cout << (m[i] ? m[i] : '_');
*/
	
	return 0;
}
