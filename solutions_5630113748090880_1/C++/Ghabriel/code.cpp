#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::string parse(const std::vector<std::vector<unsigned>>& lists){
	std::unordered_map<unsigned, unsigned> pairs;
	for (auto list : lists) {
		for (unsigned v : list) {
			if (pairs.find(v) == pairs.end()) {
				pairs.insert(std::make_pair(v, 0));
			}
			pairs[v]++;
		}		
	}

	std::vector<unsigned> answer;
	for (auto pair : pairs) {
		if (pair.second % 2 != 0) {
			answer.push_back(pair.first);
		}
	}
	std::sort(answer.begin(), answer.end());

	std::string buffer;
	unsigned c = 0;
	for (unsigned v : answer) {
		buffer += std::to_string(v);
		if (c < answer.size() - 1) {
			buffer += " ";
		}
		c++;
	}
	return buffer;
}

int main(){
	unsigned T, i = 0;
	unsigned N;

	std::cin >> T;
	for (unsigned i = 0; i < T; i++) {
		std::cin >> N;
		std::vector<std::vector<unsigned>> lists(2 * N - 1);
		for (unsigned j = 0; j < 2 * N - 1; j++) {
			for (unsigned k = 0; k < N; k++) {
				unsigned value;
				std::cin >> value;
				lists[j].push_back(value);
			}
		}
		auto r = parse(lists);
		std::cout << "Case #" << (i+1) << ": " << r << std::endl;
	}
}