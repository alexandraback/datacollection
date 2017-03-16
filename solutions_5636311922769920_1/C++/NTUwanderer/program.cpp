#include <iostream>

using namespace std;

// int power(const int& base, int pow) {
// 	int value = 1;
// 	while (pow != 0) {
// 		value *= base;
// 		--pow;
// 	}
// 	return value;
// }

long getIndex(const int& k, const int& c, const int* array) {
	long index = 0;
	for (int i = 0; i < c; ++i) {
		index = k * index + array[i];
	}

	return index + 1;
}

int main() {
	int round = 0;
	
	cin >> round;

	for (int k = 0; k < round; ++k) {
		int K = 0, C = 0, S = 0;
		cin >> K >> C >> S;
		int* array = new int[C];
		cout << "Case #" << k + 1 << ":";
		
		// if (K == S) {
		// 	for (int i = 1; i <= S; ++i)
		// 		cout << ' ' << i;
		// 	cout << endl;
		// } else 

		if (K > (C * S)) {
			cout << " IMPOSSIBLE" << endl;
		} else {
			int count = 0;
			while (count != K) {
				for (int i = C - 1; i >= 0; --i) {
					if (count != K) {
						array[i] = count;
						++count;
					} else {
						array[i] = 0;
					}
				}
				cout << ' ' << getIndex(K, C, array);
			}
			cout << endl;
		}
	}
	return 0;
}