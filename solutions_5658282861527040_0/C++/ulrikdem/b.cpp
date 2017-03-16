#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test) {
		int max1, max2, max3, counter = 0;
		cin >> max1 >> max2 >> max3;
		for(int number1 = 0; number1 < max1; ++number1) {
			for(int number2 = 0; number2 < max2; ++number2) {
				if((number1 & number2) < max3) {
					++counter;
				}
			}
		}
		cout << "Case #" << test << ": " << counter << '\n';
	}
	return 0;
}
