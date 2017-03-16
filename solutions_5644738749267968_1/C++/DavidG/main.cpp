#include <algorithm>
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#ifdef DEBUG
#define DBGLOG  std::cerr
#else
#define DBGLOG  if (0) std::cerr
#endif



/*
 The first line of the input gives the number of test cases, T. T test cases follow.
Each test case starts with a line containing a single integer N, the number of blocks each player has.
Next follows a line containing N space-separated real numbers: the masses of Naomi's blocks, in kg.
Finally there will be a line containing N space-separated real numbers: the masses of Ken's blocks, in kg.

Each of the masses given to Ken and Naomi will be represented as a 0, followed by a decimal point, followed by 1-5 digits.
Even though all the numbers in the input have 1-5 digits after the decimal point, Ken and Naomi don't know that;
so Naomi can still tell Ken that she played a block with mass 0.5000001kg, and Ken has no reason not to believe her.
*/


unsigned get_deceitfulwar_wins(std::vector<double>& list_naomi, std::vector<double>& list_ken)
{
	/* make sure ken always uses his higest weights if he is in advantage anyway */
//	for (auto i : list_naomi)
//		DBGLOG << i << ", ";
//	DBGLOG << std::endl;

//	auto iter_n		= list_naomi.begin();
//	auto riter_n	= list_naomi.rbegin();
//	auto riter_k	= list_ken.rbegin();

	std::deque<double> qn(list_naomi.begin(), list_naomi.end());
	std::deque<double> qk(list_ken.begin(), list_ken.end());

	unsigned wins = 0;

	while (!qn.empty()) {
		auto last_n = qn.back();
		auto last_k = qk.back();

		if (last_k > last_n) {
			// sacrifice lowest value by bluffing
			qn.pop_front();
			qk.pop_back();
		}
		else {
			qn.pop_back();
			qk.pop_back();
			++wins;
		}
	}
	return wins;
}

unsigned get_war_wins(const std::vector<double>& list_naomi, const std::vector<double>& list_ken)
{
	unsigned wins = 0;

	auto iter_n = list_naomi.begin();
	auto iter_k = list_ken.begin();

	while (iter_n != list_naomi.end()) {
		while (iter_k != list_ken.end()
			   && *iter_k < *iter_n) {
			++iter_k;
		}
		if (iter_k == list_ken.end()) {
			wins = list_naomi.end() - iter_n;
			break;
		}
		++iter_n;
		++iter_k;
	}

	return wins;
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
			unsigned N;

			input >> N;
			std::vector<double> list_naomi;
			for (unsigned j = 0; j < N; ++j) {
				double weight;
				input >> weight;
				list_naomi.push_back(weight);
			}
			std::vector<double> list_ken;
			for (unsigned j = 0; j < N; ++j) {
				double weight;
				input >> weight;
				list_ken.push_back(weight);
			}

			std::sort(list_naomi.begin(), list_naomi.end());
			std::sort(list_ken.begin(), list_ken.end());

			unsigned deceitfulwar_wins	= get_deceitfulwar_wins(list_naomi, list_ken);
			unsigned war_wins			= get_war_wins(list_naomi, list_ken);

			std::cout << "Case #" << i << ": " << deceitfulwar_wins << " " << war_wins << std::endl;
		}
	}
	return 0;
}

