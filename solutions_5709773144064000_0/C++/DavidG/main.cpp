#include <algorithm>
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <set>
#include <utility>
#include <vector>

using namespace std;

#ifdef DEBUG
#define DBGLOG  std::cerr
#else
#define DBGLOG  if (0) std::cerr
#endif




double calculate_cookie_clicker_alpha(double C, double F, double X, double production = 2.0)
{
	double result = X/production;

	if (((C / production) + X / (production + F)) < (X / production)) {
		double alternative = C/production + calculate_cookie_clicker_alpha(C, F, X, production + F);
		if (alternative < result)
			result = alternative;
	}

	return result;
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
			 *The first line of the input gives the number of test cases, T.
			 *T lines follow.
			 *
			 *Each line contains three space-separated real-valued numbers: C, F and X, whose meanings
			 *are described earlier in the problem statement.
			 *
			 *C, F and X will each consist of at least 1 digit followed by 1 decimal point followed by from
			 *1 to 5 digits. There will be no leading zeroes.
			 */
			double C, F, X;

			input >> C >> F >> X;

			double retval = calculate_cookie_clicker_alpha(C, F, X);
			std::cout.precision(7);
			std::cout.setf(std::ios::fixed, std:: ios::floatfield);
			std::cout << "Case #" << i << ": " << retval << std::endl;
		}
	}
	return 0;
}

