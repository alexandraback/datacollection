#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int K, C, S;
		cin >> K >> C >> S;
		cout << "Case #" << t << ":";
		for (int s = 1; s <= S; ++s) {
			cout << " " << s;
		}
		cout << endl;
	}
	return 0;
}