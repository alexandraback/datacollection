#include <iostream>
#include <cstdio>
#include <string>
#include <deque>
#include <map>
#include <algorithm>
#include <vector>
#include <list>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/multi_array.hpp>

#include <boost/pending/disjoint_sets.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

unsigned count(const std::string& s, char c_goal) {
	unsigned ret = 0;
	for (auto c : s) {
		if (c == c_goal)
			ret++;
	}
	return ret;
}

void problemB_bf() {
	int num_tests;

	struct Board
	{
		int b1_n, b2_n;
		std::string b1, b2;

		Board() {
			b1_n = b2_n = -1;
		}
		void clear() {
			b1_n = b2_n = -1;
			b1.clear();
			b2.clear();
		}
	};

	Board original, best, current;
	//std::string board1, board2;
	//std::string best_board1, best_board2;

	auto next_values = [](std::vector<int>& v) {
		
		for (auto& i : v) {
			i++;
			if (i < 10) {
				return;
			}
			else {
				i = 0;
			}
		}

		v.back() = 10;
	};

	auto valid_values = [](std::vector<int>& v) {
		return v.back() < 10;
	};

	auto apply_values = [](std::vector<int>& v, Board& b) {
		int offset = 0;
		int i;

		for (i = 0; i < v.size(); i++) {
			offset = b.b1.find('?', offset);

			if (offset != b.b1.npos) {
				b.b1[offset] = v[i] + '0';
				offset++;
			}
			else {
				offset = 0;
				break;
			}
		}
		for (; i < v.size(); i++) {
			offset = b.b2.find('?', offset);

			if (offset != b.b2.npos) {
				b.b2[offset] = v[i] + '0';
				offset++;
			}
			else {
				offset = 0;
				break;
			}
		}

		if (i != v.size()) {
			throw std::exception("ERROR");
		}

		b.b1_n = std::atoi(b.b1.c_str());
		b.b2_n = std::atoi(b.b2.c_str());
	};

	auto best_board = [&](const Board& current) {
		if (best.b1.empty()) {
			best = current;
		}
		else {
			auto best_dif = std::abs(best.b1_n - best.b2_n);
			auto current_dif = std::abs(current.b1_n - current.b2_n);

			if (current_dif < best_dif) {
				best = current;
			}
			else if (current_dif == best_dif && current.b1_n < best.b1_n) {
				best = current;
			}
			else if (current_dif == best_dif && current.b2_n < best.b2_n) {
				best = current;
			}
		}
	};

	std::cin >> num_tests;
	for (int test = 1; test <= num_tests; test++) {
		std::cin >> original.b1 >> original.b2;
		best.clear();

		int num_questions_marks = count(original.b1, '?') + count(original.b2, '?');
		std::vector<int> values(num_questions_marks, 0);

		for (; valid_values(values); next_values(values)) {
			current = original;
			apply_values(values, current);
			best_board(current);
		}

		std::cout << "Case #" << test << ": " << best.b1 << " " << best.b2 << std::endl;
	}
}

void problemB() {
	int num_tests;

	struct Board
	{
		std::string b1, b2;

	};

	Board original;

	std::cin >> num_tests;
	for (int test = 1; test <= num_tests; test++) {
		std::cin >> original.b1 >> original.b2;


		bool b1_bigger_b2 = false;
		bool b1_equal_b2 = true;

		for (int i = 0; i < original.b1.size(); i++) {
			if (original.b1[i] == '?' && original.b2[i] == '?') {
				if (b1_equal_b2) {
					original.b1[i] = original.b2[i] = '0';
				}
				else if (b1_bigger_b2) {
					original.b1[i] = '0';
					original.b2[i] = '9';
				}
				else {
					original.b1[i] = '9';
					original.b2[i] = '0';
				}
			}
			else if (original.b1[i] == '?') {
				original.b1[i] = original.b2[i];
			}
			else if (original.b2[i] == '?') {
				original.b2[i] = original.b1[i];
			}
			else if (b1_equal_b2) {
				if (original.b1[i] > original.b2[i]) {
					b1_bigger_b2 = true;
					b1_equal_b2 = false;
				}
				else if (original.b1[i] < original.b2[i]) {
					b1_bigger_b2 = false;
					b1_equal_b2 = false;
				}
			}
		}

		std::cout << "Case #" << test << ": " << original.b1 << " " << original.b2 << std::endl;
	}
}

int main() {
	//std::string name = "../B-example";
	std::string name = "../B-small-attempt2";
	auto name_in = name + ".in";
	auto name_out = name + ".out2";

	freopen(name_in.c_str(), "r", stdin);
	freopen(name_out.c_str(), "w", stdout);

	problemB_bf();
	//problemB();
	return 0;
}