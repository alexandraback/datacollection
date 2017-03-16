#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <unordered_map>
#include <map>

using namespace std;

struct TestCase {
	string s;
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
		fs >> tc.s;
		res.push_back(tc);
	}
	fs.close();
	return res;
}



map<char, int> toMap(const string& s) {
	map<char, int> res;
	for (size_t i = 0; i < s.size(); i++)
		res[s[i]] = res[s[i]] + 1;
	return res;
}

static const string numbers[] = { "ZERO", "TWO", "FOUR", "SIX", "EIGHT", "FIVE", "THREE", "SEVEN", "NINE", "ONE" };
static const int conversion[] = { 0, 2, 4, 6, 8, 5, 3, 7, 9, 1 };

pair<bool, map<char, int>> subtract(map<char, int> from, const map<char, int>& what) {
	bool hasNeg = false;
	for (auto it = what.begin(); it != what.end(); ++it) {
		int d = from[it->first] - it->second;
		if (d == 0)
			from.erase(from.find(it->first));
		else
			from[it->first] = d;
		hasNeg |= d < 0;
	}
	return make_pair(hasNeg, from);
}

pair<bool, vector<int>> solveRec(const map<char, int>& input, const vector<map<char, int>>& mapNrs) {
	if (input.empty()) {
		return make_pair(true, vector<int>());
	}

	int i = 0;
	for (auto& s : mapNrs) {
		bool all = true;
		auto sub = subtract(input, s);
		if (!sub.first) {
			auto subRes = solveRec(sub.second, mapNrs);
			if (subRes.first) {
				subRes.second.push_back(conversion[i]);
				return make_pair(true, subRes.second);
			}
		}
		i++;
	}

	return make_pair(false, vector<int>());
}

std::string solve(TestCase& tc) {
	vector<map<char, int>> mapNrs;
	for (int i = 0; i <= 10; i++) {
		mapNrs.push_back(toMap(numbers[i]));
	}

	auto res = solveRec(toMap(tc.s), mapNrs);
	assert(res.first);
	sort(res.second.begin(), res.second.end());
	string out;
	for (int n : res.second)
		out += to_string(n);
	return out;
}

int main(int argc, const char *argv[]) {


	std::ofstream fs("A-large.out");
	int i = 1;
	for (auto tc : load("A-large.in")) {
		fs << "Case #" << i << ": " << solve(tc) << std::endl;
		std::cout << i << endl;
		i++;
	}
	fs.close();
	return 0;
}
