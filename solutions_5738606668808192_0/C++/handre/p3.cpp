#define P3
#ifdef P3

#include <iostream>
#include <stdint.h>
#include <string>
#include <list>
#include <sstream>
#include <cmath>

uint64_t findLCD(uint64_t N) {
	for (size_t i = 2; i <= (int)sqrt(N); i++) if (N % i == 0) return i;
	return 0;
}
uint64_t interpret(uint64_t N_2, uint64_t base) {
	uint64_t aux = 1;
	uint64_t retval = 0;
	while (N_2) {
		if (N_2 & 1) retval += aux;
		aux *= base;
		N_2 = N_2 >> 1;
	}
	return retval;
}
struct jamcoin {
	std::string coin;
	uint64_t divisors[9];
	
	void print() {
		std::cout << coin;
		for (size_t i = 0; i < 9; i++) std::cout << " " << divisors[i];
		std::cout << "\n";
	}
};
std::list<jamcoin*> getJamcoins(size_t length, size_t quantity) {
	std::list<jamcoin*> retval;
	
	uint64_t coin = (1 << (length - 1)) | 1;
	jamcoin * sol = new jamcoin;
	while (quantity) {
		
		bool isPrime = false;
		for (size_t b = 2; b <= 10 && !isPrime; b++) {
			sol->divisors[b-2] = findLCD(interpret(coin, b));
			if (!sol->divisors[b-2]) isPrime = true;
		}

		if (!isPrime) {
			
			std::ostringstream ostr;
			ostr << interpret(coin, 10);
			sol->coin = ostr.str();
			
			retval.push_back(sol);
			quantity--;
			if (quantity) sol = new jamcoin;
		}

		coin += 2;
	}

	return retval;
}

int main(void) {
	int testCases;
	std::cin >> testCases;

	for (int c = 1; c <= testCases; c++) {

		size_t N, J;
		std::cin >> N >> J;
		std::list<jamcoin*> sol = getJamcoins(N, J);
		std::cout << "Case #" << c << ":\n";
		for (auto coin : sol) coin->print();
	}
}

#endif
