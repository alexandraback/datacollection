#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <unordered_map>
#include <set>

using namespace std;

struct ScoreComparator {
	bool operator() (const pair<pair<int, string>, pair<int, string>>& a, const pair<pair<int, string>, pair<int, string>>& b) {
		int d1 = abs(a.first.first - a.second.first);
		int d2 = abs(b.first.first - b.second.first);
		if (d1 == d2) {
			if (a.first.first == b.first.first)
				return a.second.first < b.second.first;
			return a.first.first < b.first.first;
		}
		return d1 < d2;
	}
};

struct TestCase {
	string c, j;
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
		fs >> tc.c >> tc.j;
			
		res.push_back(tc);
	}
	fs.close();
	return res;
}

vector<string> produce(string score) {
	if (score.empty()) {
		vector<string> res;
		res.push_back("");
		return res;
	}
	const vector<string>& rests = produce(score.substr(1));
	vector<string> res;
	if (score[0] == '?') {
		for (char c = '0'; c <= '9'; c++) {
			for (const string& rest : rests) {
				res.push_back(c + rest);
			}
		}
	} else {
		for (const string& rest : rests) {
			res.push_back(score[0] + rest);
		}
	}
	return res;
}

std::string solve(TestCase& tc) {
	const vector<string> coders = produce(tc.c);
	const vector<string> jammers = produce(tc.j);
	vector<pair<pair<int, string>, pair<int, string>>> cross;
	for (const string& code : coders) {
		for (const string& jam : jammers) {
			cross.push_back(make_pair(make_pair(stoi(code), code), make_pair(stoi(jam), jam)));
		}
	}

	sort(cross.begin(), cross.end(), ScoreComparator());
	return cross[0].first.second + " " + cross[0].second.second;
}

int main(int argc, const char *argv[]) {
	std::ofstream fs("B-small-attempt0.out");
	int i = 1;
	for (auto tc : load("B-small-attempt0.in")) {
		fs << "Case #" << i << ": " << solve(tc) << std::endl;
		i++;
	}
	fs.close();
	return 0;
}

