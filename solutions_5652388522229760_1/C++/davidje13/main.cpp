#include <iostream>
#include <vector>
#include <stdlib.h>

// https://code.google.com/codejam/contest/6254486/dashboard#s=p0

void observe( const long value, std::vector<bool> &seen, int &seenCount, const int base ) {
	for( long v = value; v; v /= base ) {
		const int d = (int) (v % base);
		if( !seen[d] ) {
			seen[d] = true;
			++ seenCount;
		}
	}
}

long count_sheep( const long multiplier, const int base ) {
	if( multiplier == 0 || base <= 1 ) {
		return -1;
	}
	// Brute-force it!
	std::vector<bool> seen( base );
	int seenCount = 0;
	for( int i = 1; i < 10000000; ++ i ) {
		observe( multiplier * i, seen, seenCount, base );
		if( seenCount == base ) {
			return multiplier * i;
		}
	}
	std::cerr << "No answer for " << multiplier << std::endl;
	return -1;
}

int main( int argc, const char *const *const argv ) {
	if( argc != 1 ) {
		std::cerr
			<< "Usage: " << argv[0] << std::endl
			<< std::endl
			<< "Takes input on stdin" << std::endl;
		return EXIT_FAILURE;
	}

	long totalTests;
	std::cin >> totalTests;

	for( long n = 0; n < totalTests; ++ n ) {
		long multiplier;
		std::cin >> multiplier;

		const long largest = count_sheep( multiplier, 10 );

		std::cout << "Case #" << (n + 1) << ": ";
		if( largest == -1 ) {
			std::cout << "INSOMNIA";
		} else {
			std::cout << largest;
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}
