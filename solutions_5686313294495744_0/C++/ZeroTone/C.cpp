#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <unordered_map>
#include <set>

using namespace std;

struct TestCase {
	vector<pair<string, string>> topics;
};

std::vector<TestCase> load(const std::string& s) {
	std::ifstream fs(s);
	if (!fs.is_open())
		std::cout << "Not found" << std::endl;

	int n;
	std::vector<TestCase> res;
	fs >> n;
	for (int i = 0; i < n; i++) {
		TestCase tc;
		int k;
		fs >> k;
		for (int j = 0; j < k; j++) {
			pair<string, string> topic;
			fs >> topic.first >> topic.second;
			tc.topics.push_back(topic);
		}
		res.push_back(tc);
	}
	fs.close();
	return res;
}

template<typename Map>
bool contains(const Map& map, string word) {
	return map.find(word) != map.end();
}

std::string solve(TestCase& tc) {
	int i = 0;
	int res = 0;
	for (auto& topic1 : tc.topics) {
		bool firstFake = false, secondFake = false;
		int j = 0;
		for (auto& topic2 : tc.topics) {
			if (j == i) {
				j++;
				continue;
			}

			if (topic1.first == topic2.first && topic1.second == topic2.second) {
				if (j < i)
					res++;
				break;
			}

			if (topic1.first == topic2.first) {
				firstFake = true;
			}

			if (topic1.second == topic2.second) {
				secondFake = true;
			}

			if (firstFake && secondFake) {
				res++;
				break;
			}

			j++;
		}
		
		i++;
	}
	return to_string((long long)res);

}

int main(int argc, const char *argv[]) {
	std::ofstream fs("C-small-attempt1.out");
	int i = 1;
	auto cases = load("C-small-attempt1.in");
	for (auto it = cases.begin(); it != cases.end(); ++it) {
		fs << "Case #" << i << ": " << solve(*it) << endl;
		i++;
	}
	fs.close();

	return 0;
}
