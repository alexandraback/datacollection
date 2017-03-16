
#include <iostream>
#include <fstream>
#include <vector>
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

bool Solve(int number, int& result) {
	if (number == 0) {
		return false;
	}
	DigitCounter dc;
	for (int i = 1; i < 201; ++i) {
		int val = i * number;
		while (val > 0) {
			dc.Add(val % 10);
			val = val / 10;
		}
		if (dc.Count() == 10) {
			result = i * number;
			return true;
		}
	}
	return false;
}

int main(int argc, char** argv) {
	istream& is = cin;
	ostream& os = cout;
	int casecount = 0;
	vector<int> cases;
	is >> casecount;
	cases.resize(casecount);
	for (int i = 0; i < casecount; ++i) {
		is >> cases[i];
	}
	if (is.fail()) {
		return 1;
	}
	for (int i = 0; i < casecount; ++i) {
		int result = -1;
		bool hasresult = Solve(cases[i], result);
		os << "Case #" << (i + 1) << ": ";
		if (hasresult) {
			os << result;
		}
		else {
			os << "INSOMNIA";
		}
		os << endl;
	}
	return 0;
}
