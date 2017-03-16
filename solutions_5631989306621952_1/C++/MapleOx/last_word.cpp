#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void printcase(int i) {
	cout << "Case #" << i+1 << ": ";
}

int main() {
	int T;
	string S;
	cin >> T;	
	for (int i = 0; i < T; ++i) {
		printcase(i);
		cin >> S;
		string ans = "";
		for (int j = 0; j < S.length(); ++j) {
			char c = S[j];
			//cout << ans[0];
			if (c >= ans[0]) {
				ans.insert(0, 1, c);
			} else {
				ans += c;
			}
		}
		cout << ans << endl;
	}
	return 0;
}