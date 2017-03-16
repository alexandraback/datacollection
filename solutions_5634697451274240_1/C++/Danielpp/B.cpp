#include <bits/stdc++.h>
using namespace std;

int answer(string& S) {
	int n = 1;
	for (int i=1; i<(int)S.size(); i++) if (S[i] != S[i-1]) n++;
	if (S[0] == '+') return n - n%2;
	else return n - ((n%2)^1);
}

int main() {
	int T;
	cin >> T;
	string S;
	for (int c = 1; c <= T; c++) {
		cin >> S;
		cout << "Case #" << c << ": " << answer(S) << endl;
	}
}
