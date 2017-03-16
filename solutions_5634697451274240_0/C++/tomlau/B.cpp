#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int main() {
	cin >> T;
	for (int t=1; t<=T; t++) {
		cin >> S;
		int i = S.length()-1;
		int ans = S[i] == '+' ? 0 : 1;
		while (--i >= 0) 
			if (S[i] != S[i+1]) ans++;
		cout << "Case #" << t << ": " << ans << endl;
	}
}
