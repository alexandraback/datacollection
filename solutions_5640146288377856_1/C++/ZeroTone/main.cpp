#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;

struct TestCase {
	int r, c, w;
};

std::vector<TestCase> load(const std::string& fname) {
	std::ifstream fp(fname);
	std::vector<TestCase> res;
	int cases;
	fp >> cases;
	for (int i = 0; i < cases; i++) {
		TestCase c;
		fp >> c.r >> c.c >> c.w;
		res.push_back(c);
	}
	return res;
}

int solve(int c, int w) {
	if (c <= w)
		return c;
	if (w >= c / 2) {
		int rest = c / 2 - ((c + 1) % 2);
		return 2 + solve(rest, w) + max(0, w - 1 - rest);
	}
	return min(c / w - 1 + solve(c - (c / w - 1) * w, w), 1 + 2 * solve(c / 2, w));
}

string solve(TestCase& cs) {
	int p = cs.w + (cs.w < cs.c ? 1 + (cs.c - cs.w - 1) / cs.w : 0);
	int s = solve(cs.c, cs.w);
	assert(s == p);
	std::cout << s << endl;
	return to_string((cs.c / cs.w) * (cs.r - 1) + solve(cs.c, cs.w));
}

int main(int argc, const char *argv[]) {
	auto cases = load("A-large.in");
	std::ofstream fp("A-large.out");
	int i = 1;
	for (auto it = cases.begin(); it != cases.end(); ++it, ++i) {
		auto r = solve(*it);
		fp << "Case #" << i << ": " << r << std::endl;
	}

	return 0;
}

