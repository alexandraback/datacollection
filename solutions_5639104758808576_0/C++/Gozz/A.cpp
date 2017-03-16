#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int Smax;
		cin >> Smax;
		vector<int> S;
		while (S.size() < Smax + 1) {
			char c;
			cin.get(c);
			if (!isdigit(c)) continue;
			S.push_back((int) (c - '0'));
		}
		int req = 0;
		int tot = 0;
		for (int i = 0; i < S.size(); ++i) {
			if (tot < i) {
				req += i - tot;
				tot = i;
			}
			tot += S[i];
		}
		cout << "Case #" << t << ": " << req << endl;
	}
	return 0;
}
