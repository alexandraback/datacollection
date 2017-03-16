#include <bits/stdc++.h>

using namespace std;
typedef int64_t i64;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		string S;
		cin >> S;
		vector<bool> happy(S.size());
		for (int i = 0; i < S.size(); ++i) {
			happy[i] = S[i] == '+';
		}
		int moves = 0;
		int rem = S.size();
		while (rem > 0) {
			if (!happy[rem-1]) {
				int len = 0;
				while (happy[len]) {
					happy[len] = false;
					++len;
				}
				if (len > 0) ++moves;
				if (len < rem) {
					++moves;
					for (int i = 0, j = rem-1; i <= j; ++i, --j) {
						bool tmp = !happy[i];
						happy[i] = !happy[j];
						happy[j] = tmp;
					}
				}
			} else --rem;
		}
		cout << "Case #" << (t+1) << ": " << moves << endl;
	}
	return 0;
}