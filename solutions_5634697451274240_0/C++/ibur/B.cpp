#include <bits/stdc++.h>
using namespace std;

void code() {
	string s;
	cin >> s;

	char prev = s[0];
	int num = 0;
	for(int i = 1; i < s.size(); i++) {
		if(s[i] != prev) {
			num++;
			prev = s[i];
		}
	}
	if(prev == '-') num++;
	cout << num;
}

int main() {
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		code();
		cout << endl;
	}
}
