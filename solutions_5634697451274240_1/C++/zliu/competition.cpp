
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
typedef unsigned char byte;

class DigitCounter {
public:
	DigitCounter() {
		flags_.resize(10, 0);
		count_ = 0;
	}
	int Count() {
		return count_;
	}
	void Add(int digit) {
		if (flags_[digit] == 0) {
			flags_[digit] = 1;
			count_ += 1;
		}
	}
private:
	vector<byte> flags_;
	int count_;
};

void Solve(istream& is, ostream& os) {
	string s;
	is >> s;
	int count = 0;
	char current = s[0];
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] != current) {
			count += 1;
			current = s[i];
		}
	}
	if ('+' != current) {
		count += 1;
	}
	os << count;
}

int main(int argc, char** argv) {
	istream& is = cin;
	ostream& os = cout;
	int casecount = 0;
	is >> casecount;
	for (int i = 0; i < casecount; ++i) {
		os << "Case #" << (i + 1) << ": ";
		Solve(is, os);
		os << endl;
	}
	if (is.fail()) {
		return 1;
	}
	return 0;
}
