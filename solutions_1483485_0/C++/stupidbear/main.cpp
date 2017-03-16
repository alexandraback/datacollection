#include <iostream>
#include <string>
#include <sstream>

using namespace std;
char replace[30] = "yhesocvxduiglbkrztnwjpfmaq";
char buffer[200];

int main() {	
	int n ; stringstream ss;
	string s;
	getline (cin, s);
	ss << s; ss >> n;
	for (int i = 0; i < n; ++i) {
		cout << "Case #" << i+1 << ": ";
		cin.getline(buffer, 199);
		int j = -1; 
		while (buffer[++j] != '\0') {
			if (buffer[j] - 'a' >= 0 && buffer[j] - 'a' < 26) {
				cout << replace [ buffer[j] - 'a' ];
			}
			else cout << buffer[j];
		}
		cout << '\n';
	}
}