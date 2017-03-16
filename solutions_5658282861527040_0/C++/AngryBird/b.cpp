#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int times(int a, int b, int k) {
	int count = 0;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (int(i & j) < k) {
				count++;
			}
		}
	}
	return count;
}

int main() {
	int T, A, B, K;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B >> K;
		int count = times(A, B, K);
		cout << "Case #" << i+1 << ": " << count << endl;
	}
	return 0;
}