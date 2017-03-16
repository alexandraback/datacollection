
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
typedef unsigned char byte;

class Mods {
public:
	Mods(int base, int numbits, const vector<int>& primes) {
		base_ = base;
		primes_ = primes;
		currentmods_.resize(primes.size(), 0);
		bitmods_.resize(numbits);
		bitmods_[0].resize(primes.size(), 1);
		for (int b = 1; b < numbits; ++b) {
			bitmods_[b].resize(primes.size());
			for (int i = 0; i < primes.size(); ++i) {
				int prime = primes[i];
				bitmods_[b][i] = (bitmods_[b - 1][i] * base) % prime;
			}
		}
	}
	void Increment(int bitnum) {
		for (int i = 0; i < primes_.size(); ++i) {
			int prime = primes_[i];
			currentmods_[i] = (currentmods_[i] + bitmods_[bitnum][i]) % prime;
		}
	}
	void Decrement(int bitnum) {
		for (int i = 0; i < primes_.size(); ++i) {
			int prime = primes_[i];
			currentmods_[i] = (currentmods_[i] + prime - bitmods_[bitnum][i]) % prime;
		}
	}
	int GetFactor() {
		for (int i = 0; i < primes_.size(); ++i) {
			if (currentmods_[i] == 0) {
				return primes_[i];
			}
		}
		return -1;
	}
private:
	int base_;
	vector<int> primes_;
	vector<int> currentmods_;
	vector<vector<int>> bitmods_;
};

void Solve(istream& is, ostream& os) {
	int coinlength = 0;
	int desired = 0;
	int found = 0;
	is >> coinlength;
	is >> desired;
	vector<int> primes{ 2,3,5,7,11,13,17,19,23,29,31 };
	vector<int> bases{ 2,3,4,5,6,7,8,9,10 };
	vector<Mods> counters;
	for (int base : bases) {
		counters.push_back({ base, coinlength, primes });
	}
	for (Mods& counter : counters) {
		counter.Increment(0);
		counter.Increment(coinlength - 1);
	}
	vector<byte> coin;
	coin.resize(coinlength, 0);
	coin[0] = 1;
	coin[coinlength - 1] = 1;
	for (unsigned long long i = 0; i < (1ULL << (coinlength - 2)); ++i) {
		for (int j = 0; j < coinlength - 2; ++j) {
			if (i & (1ULL << j)) {
				if (coin[j + 1] == 0) {
					coin[j + 1] = 1;
					for (Mods& counter : counters) {
						counter.Increment(j + 1);
					}
				}
			}
			else {
				if (coin[j + 1] == 1) {
					coin[j + 1] = 0;
					for (Mods& counter : counters) {
						counter.Decrement(j + 1);
					}
				}
			}
		}
		bool anyprime = false;
		for (Mods& counter : counters) {
			if (counter.GetFactor() == -1) {
				anyprime = true;
				break;
			}
		}
		if (!anyprime) {
			for (int j = coinlength - 1; j > -1; --j) {
				os << (int)coin[j];
			}
			for (Mods& counter : counters) {
				os << " " << counter.GetFactor();
			}
			os << endl;
			found += 1;
			if (found >= desired) {
				return;
			}
		}
	}
}

int main(int argc, char** argv) {
	istream& is = cin;
	ostream& os = cout;
	int casecount = 0;
	is >> casecount;
	for (int i = 0; i < casecount; ++i) {
#if 1 // multiline output
		os << "Case #" << (i + 1) << ":" << endl;
		Solve(is, os);
#else
		os << "Case #" << (i + 1) << ": ";
		Solve(is, os);
		os << endl;
#endif
	}
	if (is.fail()) {
		return 1;
	}
	return 0;
}
