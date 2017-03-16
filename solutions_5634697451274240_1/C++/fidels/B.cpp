#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, t, N, i, RES;
	string s;
	
	cin >> T;
	for (t=1; t<=T; t++) {
		cin >> s; N = s.size();
		
		s += "+"; RES = 0;
		for (i=0; i<N; i++) if (s[i] != s[i+1]) RES++;
		cout << "Case #" << t << ": " << RES << endl;
	}

	return 0;
}
