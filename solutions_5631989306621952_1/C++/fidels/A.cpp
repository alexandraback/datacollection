#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, t, i, N;
	string s, RES;
	
	cin >> T;
	for (t=1; t<=T; t++) {
		cin >> s; N = (int)s.size();
		
		RES = s[0];
		for (i=1; i<N; i++) {
			if (s[i] < RES[0]) RES += s[i];
			else RES = s[i]+RES;
		}
		cout << "Case #" << t << ": " << RES << endl;
	}

	return 0;
}
