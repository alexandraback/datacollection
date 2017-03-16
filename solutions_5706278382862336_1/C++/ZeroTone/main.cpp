#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;

struct TestCase {
	long long p, q;
};

std::vector<TestCase> load(const std::string& fname) {
	std::ifstream fp(fname);
	std::vector<TestCase> res;
	int cases;
	fp >> cases;
	for (int i = 0; i < cases; i++) {
		TestCase c;
		char slash;
		fp >> c.p >> slash >> c.q;
		res.push_back(c);
	}
	return res;
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

bool powerof2(long long x) {
	return !(x == 0) && !(x & (x - 1));
}

string solve(TestCase& cs) {
	long long g = gcd(cs.p, cs.q);
	cs.p /= g;
	cs.q /= g;

	if (!powerof2(cs.q) || cs.p > cs.q) {
		return "impossible";
	}

	long long p = cs.p;
	long long q = cs.q;
	int generations = 0;
	while (p <= q && q > 1) {
		q /= 2;
		p = std::max(0ll, p);
		++generations;
	}

	return std::to_string(generations);
}

int main(int argc, const char *argv[]) {
	auto cases = load("A-large.in");
	std::ofstream fp("A-large.out");
	int i = 1;
	for (auto it = cases.begin(); it != cases.end(); ++it, ++i) {
		auto r = solve(*it);
		fp << "Case #" << i << ": " << r << std::endl;
	}

	getchar();
	return 0;
}

