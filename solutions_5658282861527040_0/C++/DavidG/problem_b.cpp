#include <algorithm>
#include <cassert>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>

#ifdef DEBUG
#define DBGMSG	std::cerr
#else
#define DBGMSG	if (0) std::cerr
#endif

using namespace std;

unsigned solve(unsigned short A, unsigned short B, unsigned short K)
{
	unsigned retval = 0;

	// After an AND, the number never gets higher!
	if (K > A || K > B) {
		return (A * B);
	}

	// For a_i in range 0 .. K, we always win
	// For b_i in range 0 .. K, we always win
	// there's K*K overlap
	retval = (A + B - K) * K;
	DBGMSG << retval << endl;

	for (int a = K; a < A; ++a) {
		for (int b = K; b < B; ++b) {
			if ((a & b) < K)
				retval++;
		}
	}
	return retval;
}

int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cerr << "Need an input file" << std::endl;
	}
	else {
		std::fstream input;
		input.open(argv[1], std::fstream::in);

		if (!input.is_open())
			return -1;

		unsigned num_testcases;
		input >> num_testcases;
		for (unsigned i = 1; i <= num_testcases; ++i) {
			/*
			 * The first line of the input gives the number of test cases, T.
			 *
			 * T lines follow, each line with three numbers A B K.
			 */

			unsigned short A, B, K;

			input >> A >> B >> K;
			DBGMSG << A << ", " << B << ", " << K << endl;

			unsigned retval = solve(A, B, K);

			std::cout << "Case #" << i << ": " << retval << std::endl;
		}
	}
	return 0;
}
