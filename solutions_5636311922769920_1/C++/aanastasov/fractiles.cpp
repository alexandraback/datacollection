#include <cassert>
#include <iostream>
using namespace std;

int main() {
	int testCases;
	cin >> testCases;
	for (int testCase = 0; testCase < testCases; ++testCase) {
		int K, C, S;
		cin >> K >> C >> S;
		cout << "Case #" << testCase + 1 << ":";
		if (S == K) {
			for (int i = 0; i < S; ++i) {
				cout << " " << i + 1;
			}
			cout << endl;
		} else {
			cout << " IMPOSSIBLE" << endl;
		}
	}
	return 0;
}