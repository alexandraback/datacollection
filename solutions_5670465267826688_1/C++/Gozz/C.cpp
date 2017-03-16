#include <iostream>
#include <vector>
#include <cctype>
#include <cmath>
#include <cstdint>

using namespace std;

typedef uint64_t u64;

u64 mulv[4][4] = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}};
bool muln[4][4] = {{false, false, false, false}, {false, true, false, true}, {false, true, true, false}, {false, false, true, true}};

int main() {
	u64 T;
	cin >> T;
	for (u64 t = 1; t <= T; ++t) {
		u64 L, X;
		cin >> L >> X;
		if (X > 24) X = 24 + X%4;
		vector<u64> D;
		cin >> ws;
		for (u64 i = 0; i < L; ++i) {
			char c;
			cin.get(c);
			D.push_back((u64) (c - 'h'));
		}
		bool possible = true;
		u64 di = 0;
		bool neg;
		u64 val;
		for (u64 targ = 1; targ < 4; ++targ) {
			neg = false;
			val = 0;
			while (di < L*X) {
				if (val == targ && !neg) break;
				neg = neg ^ muln[val][D[di%L]];
				val = mulv[val][D[di%L]];
				++di;
			}
			if (val != targ || neg) {
				possible = false;
				break;
			}
		}
		neg = false;
		val = 0;
		while (di < L*X) {
			neg = neg ^ muln[val][D[di%L]];
			val = mulv[val][D[di%L]];
			++di;
		}
		if (val != 0 || neg) possible = false;

		if (possible) {
			cout << "Case #" << t << ": YES" << endl;
		} else {
			cout << "Case #" << t << ": NO" << endl;
		}
	}
	return 0;
}
