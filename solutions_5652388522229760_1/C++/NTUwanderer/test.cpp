#include <iostream>
#include <queue>

using namespace std;

bool checkNumber(long number, bool* array, int& remain) {
	while(number != 0) {
		int temp = number % 10;
		if (array[temp] == false) {
			array[temp] = true;
			--remain;
		}
		number /= 10;
	}
	return (remain == 0);
}

int main() {
	int round = 0, counter = 1, remain = 10;
	long T;
	bool* array = new bool[10];

	for (int i = 0; i < 10; ++i)
		array[i] = false;

	cin >> round;

	for (int k = 0; k < round; ++k) {
		cin >> T;
		bool find = false;
		if (T != 0) {
			for (int j = 1; true; ++j) {
				if (checkNumber(T * j, array, remain)) {
					find = true;
					cout << "Case #" << counter << ": " << T * j << endl;
					break;
				}
			}
		}
		
		if (find == false)
			cout << "Case #" << counter << ": INSOMNIA" << endl;


		for (int i = 0; i < 10; ++i)
			array[i] = false;
		remain = 10;
		++counter;
	}
	return 0;
}