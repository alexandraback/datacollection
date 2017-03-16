#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;

struct TestCase {
	vector<string> sets;
};

std::vector<TestCase> load(const std::string& fname) {
	std::ifstream fp(fname);
	std::vector<TestCase> res;
	int cases;
	fp >> cases;
	for (int i = 0; i < cases; i++) {
		TestCase c;
		int size = 0;
		fp >> size;
		for (int j = 0; j < size; j++) {
			string seta;
			fp >> seta;
			c.sets.push_back(seta);
		}
		res.push_back(c);
	}
	return res;
}

bool checkValid(const string& s) {
	unordered_set<char> seen;
	seen.insert(s[0]);
	for (int i = 1; i < s.size(); i++) {
		if (seen.find(s[i]) != seen.end() && s[i] != s[i - 1])
			return false;
	}
	return true;
}

vector<string> contrive(const vector<string>& cs) {
	/*vector<string> res;
	for (const string& s : cs) {
		string cont; cont += s[0]; cont += s[s.size() - 1];
		res.push_back(cont);
	}*/

	return cs;
}

int solve(TestCase& cs) {
	for (string& s : cs.sets) {
		if (!checkValid(s))
			return 0;
	}

	vector<string> contrived = contrive(cs.sets);
	bool connected = false;

	int interchangeable = 0;
	do {
		unordered_map<char, unordered_set<int> > starts;
		for (int i = 0; i < (int)contrived.size(); i++) {
			starts[contrived[i][0]].insert(i);
		}

		vector<string> newInput;
		for (int i = 0; i < contrived.size(); i++) {
			unordered_set<int> connects;
			connects = starts[*contrived[i].rbegin()];
			connects.erase(i);

			if (connects.size() == 1) {
				int j = *connects.begin();
				newInput.push_back(contrived[i] + contrived[j]);
				if (contrived[i] == contrived[j])
					++interchangeable;
				if (!checkValid(contrived[i] + contrived[j]))
					return 0;

				for (int k = 0; k < contrived.size(); k++) {
					if (k == i || k == j)
						continue;
					newInput.push_back(contrived[k]);
				}
				break;
			}

			if (connects.size() > 1) {
				for (int c : connects) {
					if (*contrived[c].begin() != *contrived[c].rbegin())
						return 0;
				}
			}
		}

		if (newInput.size() == 0) {
			connected = true;
		} else {
			connected = false;
			contrived = contrive(newInput);
		}
	} while (!connected);

	for (int i = 0; i < (int)contrived.size(); i++) {
		for (int j = 0; j < (int)contrived.size(); j++) {
			if (i != j) {
				if (!checkValid(contrived[i] + contrived[j]))
					return 0;
			}
		}
	}

	long long fact = 1;
	for (int i = 1; i <= (int)contrived.size(); i++) {
		fact *= i;
		fact %= 1000000007ll;
	}

	for (int i = 0; i < interchangeable; i++) {
		fact *= 2;
		fact %= 1000000007ll;
	}

	return (int)fact;
}

int main(int argc, const char *argv[]) {
	auto cases = load("B-small-attempt0.in");
	std::ofstream fp("B-small-attempt0.out");
	int i = 1;
	for (auto it = cases.begin(); it != cases.end(); ++it, ++i) {
		auto r = solve(*it);
		fp << "Case #" << i << ": " << r << std::endl;
	}

	getchar();
	return 0;
}

