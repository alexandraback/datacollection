#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory>
#include <iterator>

void update(int *array) {
	array[2] += 2;
	if (array[2] > 28) {
		array[1] += 2;
		if (array[1] > 26) {
			array[0] += 2;
			array[1] = array[0] + 2;
		}
		array[2] = array[1] + 2;
	}
}

int main() {
	int n = 32;
	int j = 500;
	std::cout << "Case #1:" << "\n";
	std::vector<int> digits(32);
	int odd[4] = { 1, 3, 5, 31};
	int even[4] = { 2, 4, 6, 0 };
	for (odd[0] = 1; odd[0] < 31; odd[0] += 2) {
		for (odd[1] = odd[0] + 2; odd[1] < 31; odd[1] += 2) {
			for (odd[2] = odd[1] + 2; odd[2] < 31; odd[2] += 2) {
				for (even[0] = 2; even[0] < 31; even[0] += 2) {
					for (even[1] = even[0] + 2; even[1] < 31; even[1] += 2) {
						for (even[2] = even[1] + 2; even[2] < 31; even[2] += 2) {
							if (j-- == 0){
								return 0;
							}
							std::fill(digits.begin(), digits.end(), 0);
							for (int k = 0; k < 4; ++k) {
								digits[odd[k]] = digits[even[k]] = 1;
							}
							std::copy(digits.begin(), digits.end(), std::ostream_iterator<int>(std::cout, ""));
							for (int k = 3; k <= 11; ++k) {
								std::cout << " " << k;
							}
							std::cout << "\n";
						}
					}
				}
			}
		}
	}
}