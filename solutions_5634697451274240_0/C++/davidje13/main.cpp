#include <iostream>
#include <string>

// https://code.google.com/codejam/contest/6254486/dashboard#s=p1

// algorithm:
// from top to bottom, make the set consistent with the next item
// e.g. --+-
// - is already consistent with -, so nothing
// -- is inconsistent with +, so flip 2
// +++ is inconsistent with -, so flip 3
// ---- is inconsistent with implicit final +, so flip 4
// therefore, 3 steps

// For counting steps, this simplifies to:
// add an implicit final +, then count the number of switches along the stack

class FlippingPancakeStack {
private:
	bool lastState = false;
	int size = 0;
	int flips = 0;

public:
	void push_back( const bool state ) {
		if( size > 0 && state != lastState ) {
			++ flips;
		}
		lastState = state;
		++ size;
	}

	int count_flips( ) const {
		if( lastState != true ) { // implicit final +
			return flips + 1;
		} else {
			return flips;
		}
	}
};

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
	(void) std::cin.get( ); // skip first newline

	for( long n = 0; n < totalTests; ++ n ) {
		FlippingPancakeStack stack;
		while( true ) {
			const int c = std::cin.get( );
			if( c == '+' ) {
				stack.push_back( true );
			} else if( c == '-' ) {
				stack.push_back( false );
			} else if( c == '\n' || c == std::char_traits<char>::eof( ) ) {
				break;
			} else {
				std::cerr
					<< "Unexpected token: " << c
					<< " in test case " << (n + 1)
					<< std::endl;
				return EXIT_FAILURE;
			}
		}
		const int flips = stack.count_flips( );
		std::cout << "Case #" << (n + 1) << ": " << flips << std::endl;
	}

	return EXIT_SUCCESS;
}
