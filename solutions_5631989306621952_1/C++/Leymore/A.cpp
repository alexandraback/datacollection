#include <bits/stdc++.h>

using namespace std;

int T, n;
char s[1010];
string S;

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
	cin >> T;
	for(int cas = 1; cas <= T; cas ++) {
		cin >> s; n = strlen(s);
		S = s[0];
		for(int i = 1; i < n; i ++) {
			if(S[0] <= s[i]) S = s[i] + S;
			else S = S + s[i];
		}
		cout << "Case #" << cas << ": " << S << endl;
	}
	return 0;
}

