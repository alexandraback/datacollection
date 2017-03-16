#include <iostream>

using namespace std;

int moves[1000007];

inline int min(int a, int b) {
	return (a < b) ? a : b;
}

int flip(int a) {
	int result = 0;
	while (a != 0) {
		result = result * 10 + a % 10;
		a /= 10;
	}
	return result;
}

int main() {
	moves[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		if (moves[i] == 0)
			moves[i] = moves[i - 1] + 1;
		else
			moves[i] = min(moves[i - 1] + 1, moves[i]);
		if (flip(i) > i)
			moves[flip(i)] = moves[i] + 1;
	}
	int t;
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		int n;
		cin >> n;
		
		cout << "Case #" << t1 << ": " << moves[n] << endl;
	}
}
