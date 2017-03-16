#include <iostream>
#include <cassert>
using namespace std;

int f(string s) {
	int res = 0;
	for(int i = s.size() - 1; i >= 0; --i) {
		if((s[i] == '+') == (res & 1)) ++res;
	}
	return res;
}

int main() {
	int T;
	string s;
	cin >> T;
	for(int cs = 1; cs <= T; ++cs) {
		cin >> s;
		cout << "Case #" << cs << ": " << f(s) << endl;
		
	}
	return 0;
}