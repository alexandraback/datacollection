#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		
		string S, W = "";
		cin >> S;
		W += S[0];
		int len = S.length();
		for (int i = 1; i < len; ++i) {
			if (S[i] >= W[0]) {
				W = S[i] + W;
			} else {
				W = W + S[i];
			}
		}
		
		cout << W << endl;
	}
	return 0;
}