#include <iostream>

using namespace std;

int power(const int& base, int pow) {
	int value = 1;
	while (pow != 0) {
		value *= base;
		--pow;
	}
	return value;
}

void next(bool* array, const int& size) {
	for (int i = 0; i < size; ++i) {
		if (array[i] == false) {
			array[i] = true;
			break;
		} else {
			array[i] = false;
		}
	}
}

int main() {
	int round = 0;
	
	cin >> round;

	for (int k = 0; k < round; ++k) {
		int N = 0, J = 0;
		bool odd = false;
		cin >> N >> J;
		cout << "Case #" << k + 1 << ": " << endl;
		int set = N / 2 - 2;
		odd = (N % 2 == 1);
		if (J <= power(2, set)) {
			bool* array = new bool[set];
			for (int i = 0; i < set; ++i)	array[i] = false;
			for (int i = 0; i < J; ++i) {
				cout << "11";
				if (odd)	cout << "0";
				for (int j = 0; j < set; ++j) {
					if (array[set - j - 1])	cout << "11";
					else					cout << "00";
				}
				cout << "11";

				for (int j = 3; j <= 11; ++j)
					cout << ' ' << j;

				cout << endl;

				next(array, set);
			}
		}
	}
	return 0;
}