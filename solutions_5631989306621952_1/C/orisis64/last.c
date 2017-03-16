#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i=0; i<t; ++i) {
		string s;
		cin >> s;
		string r = s.substr(0, 1);
		for (int j=0; j<s.length()-1; ++j) {
			string x = r + s[j+1];
			string y = s[j+1] + r;
			if (x>y) {r = x;}
			else {r = y;}
		}
		cout << "Case #" << i+1 << ": " << r << endl;
	}
}