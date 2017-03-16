#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;

struct TestCase {
	string name;
	int n;
};

std::vector<TestCase> load(const std::string& fname) {
	std::ifstream fp(fname);
	std::vector<TestCase> res;
	int cases;
	fp >> cases;
	for (int i = 0; i < cases; i++) {
		TestCase c;
		fp >> c.name >> c.n;
		res.push_back(c);
	}
	return res;
}

bool consonant(char c) {
	return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

vector<int> starts(const string& s, int n) {
	vector<int> res;
	int consecutive = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		char c = s[i];
		if (consonant(c)) {
			consecutive++;
			if (consecutive == n) {
				res.push_back(i - n + 1);
				--consecutive;
			}
		} else {
			consecutive = 0;
		}
	}
	return res;
}

int solve(TestCase& cs) {
	vector<int> s = starts(cs.name, cs.n);
	if (s.empty())
		return 0;
	int res = 0;
	int namelen = (int)cs.name.size();
	int last = 0;
	for (auto it = s.begin(); it != s.end(); ++it) {
		const int before = *it - last;
		const int after = namelen - *it - cs.n;
		res += (before + 1) * (after + 1);
		last = *it + 1;
	}
	return res;
}

int main(int argc, const char *argv[]) {
	auto cases = load("A-small-attempt0.in");
	std::ofstream fp("A-small-attempt0.out");
	int i = 1;
	for (auto it = cases.begin(); it != cases.end(); ++it, ++i) {
		int r = solve(*it);
		fp << "Case #" << i << ": " << r << std::endl;
	}

	getchar();
	return 0;
}

