#define R1AP2
#ifdef R1AP2


#include <iostream>
#include <stdint.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

int main(void) {
	int testCases;
	std::cin >> testCases;

	int * count = new int[4096];

	for (int c = 1; c <= testCases; c++) {
		std::cout << "Case #" << c << ": ";

		memset(count, 0x00, 4096 * sizeof(int));

		int N; std::cin >> N;
		for (size_t i = 0; i < (2 * N - 1)*N; i++) {
			int val; std::cin >> val;
			count[val]++;
		}
		for (size_t i = 0; i < 4096; i++) if (count[i] & 1) printf(" %i", i);
		printf("\n");

	}
	delete[] count;

	return 0;
}

#endif