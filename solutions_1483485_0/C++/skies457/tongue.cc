#include <iostream>
#include <cctype>
#include <string>
using namespace std;

const char *table = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	int n;
	string s;
	//freopen("test.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	cin.get();
	for(int i = 0; i < n; i++) {
		getline(cin, s);
		cout << "Case #" << i + 1 << ": ";
		for(string::iterator i = s.begin(); i != s.end(); ++i) {
			if(isalpha(*i)) {
				cout << table[*i - 'a'];
			} else {
				cout << *i;
			}
		}
		cout << endl;
	}
	return 0;
}
