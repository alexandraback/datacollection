#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory>
#include <iterator>

int pancake(std::vector<bool> &vec) {
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	if (vec.back()) {
		vec.pop_back();
	}
	return vec.size();
}

void conquer() {
	std::string stk;
	std::cin >> stk;
	std::vector<bool> vec;
	vec.reserve(stk.size());
	std::transform(stk.begin(), stk.end(), std::back_inserter(vec), [](char c){return c == '+'; });
	std::cout << pancake(vec);
}

int main(int argc, char **argv) {
	int T;
	std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		std::cout << "Case #" << t << ": ";
		conquer();
		std::cout << "\n";
	}
}
