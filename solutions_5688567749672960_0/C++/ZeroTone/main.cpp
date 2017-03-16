#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <boost/lexical_cast.hpp>
using namespace std;

struct TestCase {
	long long n;
};

std::vector<TestCase> load(const std::string& fname) {
	std::ifstream fp(fname);
	std::vector<TestCase> res;
	int cases;
	fp >> cases;
	for (int i = 0; i < cases; i++) {
		TestCase c;
		fp >> c.n;
		res.push_back(c);
	}
	return res;
}

long long revnum(long long num) {
	string s = to_string(num);
	std::reverse(s.begin(), s.end());
	return boost::lexical_cast<long long>(s);
}

string solve(TestCase& cs) {
	long long attempts = 1;
	long long i = 1;
	while (i != cs.n) {
		long long rev = revnum(i);
		if (rev > i && rev <= cs.n)
			i = rev;
		else
			i++;

		++attempts;
	}
	return to_string(attempts);
}

int main(int argc, const char *argv[]) {
	auto cases = load("A-small-attempt0.in");
	std::ofstream fp("A-small-attempt0.out");
	int i = 1;
	for (auto it = cases.begin(); it != cases.end(); ++it, ++i) {
		auto r = solve(*it);
		fp << "Case #" << i << ": " << r << std::endl;
	}

	return 0;
}

