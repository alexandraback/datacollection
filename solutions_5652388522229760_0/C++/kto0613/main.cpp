
#include <iostream>
#include <string.h>

int main(void) {
	int T;
	int N;

	int min;

	unsigned int digit;
	int tmp;

	std::cin >> T;
	for (int i = 0; i < T; i++) {
		std::cin >> N;
		min = 0;
		digit = 0;
		if (N)
			for (int j = 1;; j++) {
				tmp = N*j;
				while (tmp > 0) {
					digit |= 1 << (tmp % 10);
					tmp /= 10;
				}
				if (0b1111111111 == digit) {
					min = N*j;
					break;
				}
			}
		std::cout << "Case #" << i + 1 << ": ";
		if (min) std::cout << min;
		else std::cout << "INSOMNIA";
		std::cout << std::endl;
	}
	return 0;
}