#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		vector<bool> odd(2501, false);
		int i;
		for (int r = 0; r < 2 * N - 1; ++r) {
			for (int c = 0; c < N; ++c) {
				cin >> i;
				odd[i] = !odd[i];
			}
		}
		cout << "Case #" << t << ":";
		for (int j = 0; j < odd.size(); ++j) {
			if (odd[j]) cout << " " << j;
		}
		cout << endl;
	}
	return 0;
}