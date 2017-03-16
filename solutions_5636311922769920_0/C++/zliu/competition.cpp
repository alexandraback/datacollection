
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
	int tilecount = 0;
	int power = 0;
	int triallimit = 0;
	is >> tilecount;
	is >> power;
	is >> triallimit;
	if (power * triallimit < tilecount) {
		os << "IMPOSSIBLE";
		return;
	}
	for (int i = 0; i < tilecount; i += power) {
		long long tileindex = 0;
		vector<int> coords;
		coords.resize(power);
		for (int j = 0; j < power; ++j) {
			if (i + j < tilecount) {
				coords[j] = i + j;
			}
			else {
				coords[j] = 0;
			}
		}
		long long index = 0;
		for (int j = 0; j < power; ++j) {
			index = index * tilecount + coords[j];
		}
		if (i != 0) {
			os << " ";
		}
		os << index + 1;
	}
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
