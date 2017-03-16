// p2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <assert.h>

int calc_overlap(std::vector<char> word) {
	for (int i = 1; i < word.size(); i++) {
		if (word[i] == word[0]) {
			// attempt
			bool success = true;
			for (int j = 0; i + j < word.size(); j++) {
				if (word[i + j] != word[j]) {
					success = false;
					break;
				}
			}
			if (success) {
				return word.size() - i;
			}
		}
	}
	return 0;
 }

double prob(std::vector<char> keyboard, std::vector<char> word) {
	double result = 1.0;
	for (int i = 0; i < word.size(); i++) {
		int occ = std::count(keyboard.begin(), keyboard.end(), word[i]);
		double p_letter = (double)occ / (double)keyboard.size();
		result *= p_letter;
	}
	return result;
}

bool spellable(std::vector<char> keyboard, std::vector<char> word) {
	for (int i = 0; i < word.size(); i++) {
		if (std::count(keyboard.begin(), keyboard.end(), word[i]) == 0) {
			return false;
		}
	}
	return true;
}

double solve_case(int K, int L, int S, std::vector<char> keyboard, std::vector<char> word) {
	if (!spellable(keyboard, word)) {
		return 0.0;
	}
	int O = calc_overlap(word);
	int max_bananas = (S - L) / (L - O);
	if (S - L >= 0) {
		max_bananas++;
	}
	double p = prob(keyboard, word);
	double exp_bananas = (S - L + 1) * p;
	return (double) max_bananas - exp_bananas;
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
		int K, L, S;
		std::cin >> K >> L >> S;
		std::vector<char> keyboard, word;
		char c;
		for (int i = 0; i < K; i++) {
			std::cin >> c;
			keyboard.push_back(c);
		}
		for (int j = 0; j < L; j++) {
			std::cin >> c;
			word.push_back(c);
		}
		// compute output
		std::cout.precision(15);
		std::cout << "Case #" << i << ": " << solve_case(K, L, S, keyboard, word) << std::endl;
	}


	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
	//std::cin.ignore();
	return 0;
}