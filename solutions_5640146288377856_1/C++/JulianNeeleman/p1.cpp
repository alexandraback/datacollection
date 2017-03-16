// p1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <assert.h>

int solve_case(int R, int C, int W) {
	int result = C / W;
	result *= R;
	result += W - 1;
	if (C % W != 0) {
		result++;
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());

	std::ofstream out("out.txt");
	std::streambuf *coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(out.rdbuf());

	int T;
	std::cin >> T;
	for (int i = 1; i <= T; i++) {
		// build input for single test case
		int R, C, W;
		std::cin >> R >> C >> W;
		// compute output
		std::cout << "Case #" << i << ": " << solve_case(R, C, W) << std::endl;
	}


	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
	//std::cin.ignore();
	return 0;
}