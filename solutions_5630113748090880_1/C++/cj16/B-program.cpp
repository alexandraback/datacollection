#include <iostream>
#include <vector>
using namespace std;

const int MAX_H = 2500;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ":";
		
		int N;
		cin >> N;
		vector<int> H(MAX_H + 1, 0);
		for (int i = 0; i < 2 * N - 1; ++i) {
			for (int j = 0; j < N; ++j) {
				int h;
				cin >> h;
				++H[h];
			}
		}
		
		for (int i = 1; i <= MAX_H; ++i) {
			if (H[i] % 2 != 0) {
				cout << " " << i;
			}
		}
		cout << endl;
	}
	
	return 0;
}