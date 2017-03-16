#define P2
#ifdef P2

#include <iostream>
#include <stdint.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

template<bool happy>
int solve(const char * p, size_t len) {
	if (len == 0) return 0;
	else if (p[len - 1] == (happy ? '+' : '-')) return solve<happy>(p, len - 1);
	else return 1 + solve<!happy>(p, len - 1);
}

int main(void) {
	int testCases;
	std::cin >> testCases;

	for (int c = 1; c <= testCases; c++) {
		char p[256];
		scanf("%s", p);

		int sol = solve<true>(p, strlen(p));
		std::cout << "Case #" << c << ": " << sol << "\n";
	}
}
#endif
