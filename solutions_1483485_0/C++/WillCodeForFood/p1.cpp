#include <iostream>
#include <string>
#include <vector>
using namespace std;
string rep="yhesocvxduiglbkrztnwjpfmaq";
int main() {
	int T;
	cin >> T;
	string s;
		getline(cin, s);
	int ctr = 0;
	while(T--) {
		getline(cin, s);
		cout << "Case #" << ++ctr << ": ";
		for(int i = 0;i < s.length(); ++i)
			if (s[i]==' ') cout << " "; else cout << rep[s[i]-'a'];
		cout << "\n";
	}
	return 0;
}
