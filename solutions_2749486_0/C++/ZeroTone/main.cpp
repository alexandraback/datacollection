#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <cassert>

using namespace std;

struct TestCase {
	int x, y;
};

std::vector<TestCase> load(const string& file) {
	ifstream fp(file);
	std::vector<TestCase> res;
	int t; fp >> t;
	for (int i = 0; i < t; ++i) {
		TestCase c; fp >> c.x >> c.y;
		res.push_back(c);
	}
	fp.close();
	return res;
}

string getTo(int& start, int d, char nc, char pc) {
	const int dabs = abs(d);
	string res;
	int pos = 0;
	int jmp = start;
	for (int i = 0; i < dabs; i++) {
		pos += jmp;
		if (jmp < 0) {
			res += nc;
			jmp = -jmp + 1;
		} else {
			res += pc;
			jmp = -jmp - 1;
		}
		if (pos == d)
			break;

		pos += jmp;
		if (jmp < 0) {
			res += nc;
			jmp = -jmp + 1;
		} else {
			res += pc;
			jmp = -jmp - 1;
		}
		if (pos == d)
			break;
	}
	assert(res.size() < 500);
	return res;
}

string solve(TestCase &cs) {
	int start = cs.x < 0 ? -1 : 1;
	string r = getTo(start, cs.x, 'W', 'E');
	start = cs.y > 0 ? -1 : 1;
	r += getTo(start, cs.y, 'S', 'N');
	return r;
}

bool check(string& s, int tx, int ty) {
	int jmp = 1;
	int x = 0, y = 0;
	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case 'N': y += jmp; break;
		case 'S': y -= jmp; break;
		case 'W': x -= jmp; break;
		case 'E': x += jmp; break;
		}
		jmp++;
	}
	std::cout << (x - tx) << ", " << (y - ty) << std::endl;
	return x == tx && y == ty;
}

int main(int argc, const char *argv[]) {
	auto cases = load("B-small-attempt1.in");
	ofstream fp("B-small-attempt1.out");
	int i = 1;
	for (auto it = cases.begin(); it != cases.end(); ++it, ++i) {
		string s = solve(*it);
		assert(check(s, it->x, it->y));
		fp << "Case #" << i << ": " << s << std::endl;
	}

	getchar();
}

