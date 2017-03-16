#include <iostream>
#include <string>

using namespace std;

int flips() {
	string s;
	cin >> s;
	
	int f = 0;
	for (int i=1; i<s.length(); i++) {
		if (s[i] != s[i-1]) f++;
	}
	if (s[s.length()-1] == '-') f++;
	return f;
}

int main() {
	int T;
	cin >> T;
	for (int i=0; i<T; i++) {
		int f = flips();
		cout << "Case #" << i+1 << ": " << f << endl;
	}
	return 0;
}