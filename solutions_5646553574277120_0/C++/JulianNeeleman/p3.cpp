// p3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <assert.h>

int solve_case(int C, int D, int V, std::vector<int> coins) {
	int result = 0;
	std::vector<bool> amounts(V + 1, false);
	amounts[0] = true;
	int max_entry = 0;
	for (int i = 0; i < D; i++) {
		for (int j = max_entry; j >= 0; j--) {
			if (amounts[j]) {
				for (int k = 1; k <= C && (j + k*coins[i] <= V); k++) {
					amounts[j + k*coins[i]] = true;
					max_entry = std::max(max_entry, j + k*coins[i]);
				}
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (!amounts[i]) {
			result++;
			for (int j = max_entry; j >= 0; j--) {
				if (amounts[j]) {
					for (int k = 1; k <= C && (j + k*i <= V); k++) {
						amounts[j + k*i] = true;
						max_entry = std::max(max_entry, j + k*i);
					}
				}
			}
			i *= (C - 1) + 1;
		}
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
		int C, D, V;
		std::cin >> C >> D >> V;
		// compute output
		std::vector<int> coins;
		for (int i = 0; i < D; i++) {
			int c;
			std::cin >> c;
			coins.push_back(c);
		}
		std::cout << "Case #" << i << ": " << solve_case(C, D, V, coins) << std::endl;
	}


	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
	//std::cin.ignore();
	return 0;
}