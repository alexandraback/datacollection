#include <iostream>
#include <cstdio>
#include <string>
#include <deque>
#include <map>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/multi_array.hpp>

#include <boost/pending/disjoint_sets.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

std::vector<std::string> digits_string = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
std::vector<int> order_digits_string = { 0, 2, 4, 6, 8, 3, 7, 5, 1, 9 };

void ProblemA() {
	int num_tests;
	std::cin >> num_tests;

	std::string input;
	std::vector<std::map<char, unsigned>> digits_string_count;
	std::string output;
	std::map<char, unsigned> input_count;

	for (auto& i : digits_string) {
		std::sort(i.begin(), i.end()); 
		digits_string_count.emplace_back();
		for (auto c : i) {
			digits_string_count.back()[c]++;
		}
	}

	for (int test = 1; test <= num_tests; test++) {
		std::cin >> input;
		//std::sort(input.begin(), input.end());
		for (auto c : input) {
			input_count[c]++;
		}
		
		output.clear();

		std::cout << "Case #" << test << ": ";

		//auto it_digits_string_count = digits_string_count.begin();
		for (auto digit : order_digits_string) { //cheking a digit ("ZERO"0
			size_t min_num_letters = size_t(-1);
			
			auto it_digits_string_count = digits_string_count.cbegin() + digit;

			//auto it = input.begin();
			for (auto char_count : *it_digits_string_count) {//cheking each character from a digit!
				//auto begin_c = std::lower_bound(it, input.end(), char_count.first);
				//auto end_c = std::upper_bound(begin_c, input.end(), char_count.first);
				auto it = input_count.find(char_count.first);
				size_t num_letters = it != input_count.end() ? it->second : 0;

				num_letters /= char_count.second;

				min_num_letters = std::min(min_num_letters, num_letters);
				//it = end_c;
			}


			if (min_num_letters > 0) {

				output.append(min_num_letters, digit + '0');

				//it = input.begin();
				for (auto char_count : *it_digits_string_count) {
					input_count[char_count.first] -= min_num_letters*char_count.second;
				}
			}
		}

		std::sort(output.begin(), output.end());
		std::cout << output << std::endl;
	}
}

void f() {
	std::map<char, std::vector<int>> c;

	int digit = 0;
	for (auto& i : digits_string) {
		for (auto& j : i) {
			c[j].push_back(digit);
		}
		digit++;
	}

	//output
	for (auto & i : c) {
		std::cout << i.first << "->";
		for (auto j : i.second) {
			std::cout << j << " ";
		}
		std::cout << "\n";
	}
}

int main() {
	std::string name = "../A-large";
	auto name_in = name + ".in";
	auto name_out = name + ".out2";

	freopen(name_in.c_str(), "r", stdin);
	freopen(name_out.c_str(), "w", stdout);

	ProblemA();
}