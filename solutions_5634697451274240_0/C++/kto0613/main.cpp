
#include <iostream>
#include <string.h>

int main(void) {
	int T;
	char S[101];

	int count;
	char current;

	std::cin >> T;
	for (int i = 0; i < T; i++) {
		std::cin >> S;
		count = 0;
		for (int j = strlen(S); j > 0; j--) {
			if (count) {
				if (S[j - 1] != current) {
					current = S[j - 1];
					count++;
				}
			}
			else {
				if (S[j - 1] == '-') {
					current = '-';
					count = 1;
				}
			}
		}
		std::cout << "Case #" << i + 1 << ": " << count << std::endl;
	}
	return 0;
}