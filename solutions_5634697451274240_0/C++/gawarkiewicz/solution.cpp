#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string shorten(string S) {
	for (int i = 1; i < S.length(); ++i) {
		if (S[i] == S[i - 1]) {
			S = S.substr(0, i) + S.substr(i + 1);
			--i;
		}
	}
	return S;
}

string flip(string S) {
	string ret;
	ret.resize(S.length());
	for (int i = 0; i < S.length(); ++i) {
		ret[i] = S[S.length() - 1 - i] == '-' ? '+' : '-';
	}
	return ret;
}

int solve(string S) {
	if (S.length() == 0) 
		return 0;
	S = shorten(S);
	if (S.back() == '+') {
		return solve(S.substr(0, S.length() - 1));
	}
	int ret = solve(S.substr(0, S.length() - 1)) + 2;
	if (S.length() % 2) {
		int ret2 = solve(flip(S)) + 1;
		if (ret2 < ret) ret = ret2;
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string S;
		cin >> S;
		cout << "Case #" << t << ": " << solve(S) << endl;
	}
	return 0;
}