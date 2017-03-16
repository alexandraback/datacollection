#include <bits/stdc++.h>
using namespace std;

void code() {
	string s;
	cin >> s;
	string out = string("") + s[0];
	for(int i = 1; i < s.size(); i++) {
		if(s[i] >= out[0]) {
			out = s[i] + out;
		} else {
			out = out + s[i];
		}
	}
	cout << out;
}

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		code();
		cout << endl;
	}
}
