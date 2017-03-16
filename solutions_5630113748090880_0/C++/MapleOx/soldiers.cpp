#include <iostream>
#include <string>
#include <sstream>

#define MAX_HEIGHT 2500

using namespace std;

void printcase(int i) {
	cout << "Case #" << i+1 << ": ";
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		printcase(i);
		int N;
		cin >> N;
		int H[MAX_HEIGHT];
		for (int i = 0; i < MAX_HEIGHT; ++i) {
			H[i] = 0;
		}
		for (int i = 0; i < 2*N - 1; ++i) {
			for (int j = 0; j < N; ++j) {
				int k;
				cin >> k;
				H[k]++;
			}
		}
		for (int i = 0; i < MAX_HEIGHT; ++i) {
			if (H[i]%2 == 1) {
				cout << i << " ";
			}
		}
		cout << endl;
	}

	return 0;
}