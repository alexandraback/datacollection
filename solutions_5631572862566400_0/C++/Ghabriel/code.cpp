#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool contains(const std::vector<unsigned> list, unsigned value) {
	for (unsigned v : list) {
		if (v == value) {
			return true;
		}
	}
	return false;
}

std::string parse(std::vector<unsigned> list){
	unsigned N = list.size() - 1;
	unsigned result = 0;
	unsigned index = 0;
	std::vector<unsigned> memory;
	for (unsigned i = 1; i <= N; i++) {
		std::vector<unsigned> attempt;
		attempt.push_back(i);

		while (true) {
			while (!contains(attempt, list[attempt.back()])) {
				attempt.push_back(list[attempt.back()]);
			}

			bool stop = true;
			if (list[list[attempt.back()]] == attempt.back()) {
				for (unsigned j = 1; j <= N; j++) {
					if (!contains(attempt, j) && list[j] == attempt.back()) {
						attempt.push_back(j);
						stop = false;
						break;
					}
				}
			}

			if (stop) {
				break;
			}
		}

		unsigned last = list[attempt.back()];
		if (attempt[0] != last && attempt[attempt.size() - 2] != last) {
			attempt.pop_back();
		}

		if (attempt.size() > result) {
			result = attempt.size();
			index = i;
			memory = attempt;
		}
	}

	/*
	std::string buffer;
	for (unsigned v : memory) {
		buffer += std::to_string(v) + " ";
	}
	buffer += " (";
	buffer += std::to_string(index);
	buffer += ")";
	return buffer;
	//*/
	return std::to_string(result);
}

int main(){
	unsigned T, i = 0;
	unsigned N;

	std::cin >> T;
	for (unsigned i = 0; i < T; i++) {
		std::cin >> N;
		std::vector<unsigned> bff;
		bff.reserve(N + 1);
		bff.push_back(0);
		for (unsigned j = 0; j < N; j++) {
			unsigned value;
			std::cin >> value;
			bff.push_back(value);
		}
		auto r = parse(bff);
		std::cout << "Case #" << (i+1) << ": " << r << std::endl;
	}
}