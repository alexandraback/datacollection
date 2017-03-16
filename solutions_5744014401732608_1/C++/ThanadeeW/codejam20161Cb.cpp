#include "main.h"
#include <list>
using namespace Core;
using namespace std;

void Core::init() {}

string printBin(long long l, long long N) {
	string s;
	for (int i = 0; i < N; ++i) {
		s += (l % 2 == 0) ? "0" : "1";
		l /= 2;
	}
	std::reverse(s.begin(), s.end());
	return s;
}

int bitCount(long long l) {
	int bit = 0;
	while (l > 0) {
		l /= 2;
		++bit;
	}
	return bit;
}

void Core::solve() {
	long long N, W;
	CGET(N);
	CGET(W);
	long long i = 1;
	int bit = bitCount(W - 1) + 1;
	if (bit + 1 > N) {
		cout << "IMPOSSIBLE" << endl;
		return;
	} else {
		cout << "POSSIBLE" << endl;
	}
	if (bit < N - 1) {
		fori(i, N - 1 - bit) {
			cout << "0";
		}
		cout << "1";
		fori(i, bit) {
			cout << "0";
		}
		cout << endl;
		fori(i, N - bit - 2) {
			fori(i, N) {
				cout << "0";
			}
			cout << endl;
		}
	}
	cout << printBin((W - 1) * 2 + 1, N) << endl;
	fori(i, bit - 1) {
		fori(j, N - (bit - 1 - i)) {
			cout << "0";
		}
		fori(j, (bit - 1 - i)) {
			cout << "1";
		}
		cout << endl;
	}
	fori(i, N) {
		cout << "0";
	}
	cout << endl;
}