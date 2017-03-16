#include <iostream>
#include <assert.h>
#include <limits.h>
#include <vector>

using namespace std;

char S[20000];
int A[20000];
int64_t L, X;

int map[] = {
	1, 2, 3, 4,
	2, -1, 4, -3,
	3, -4, -1, 2,
	4, 3, -2, -1
};

inline int next(const int a, const int b) {
	// cout << "next(" << a << ", " << b << ") = ";
	// if (a > 0) {
	// 	cout << map[(b - 1) + ((a - 1) << 2)] << endl;
	// } else {
	// 	cout << -map[(b - 1) + (((-a) - 1) << 2)] << endl;
	// }
	if (a > 0) {
		return b > 0 ?
			map[(b - 1) + ((a - 1) << 2)] :
			-map[((-b) - 1) + ((a - 1) << 2)];
	} else {
		return b > 0 ?
			-map[(b - 1) + (((-a) - 1) << 2)] :
			map[((-b) - 1) + (((-a) - 1) << 2)];
	}
}

bool solve() {
	int state = 1;
	for (int64_t i = 0; i < L; i++) {
		state = next(state, A[i]);
	}
	int Lstate = state;
	// cout << "Lstate = " << Lstate << endl;
	state = 1;
	for (int64_t i = 0; i < X; i++) {
		state = next(state, Lstate);
	}
	// cout << "state = " << state << endl;
	if (state != -1) return false;
	
	const int64_t LX = L * X;
	state = 1;

	// seen i in M iterations, seen k in M iterations,

	int64_t atMost = 9 * (2 * L) + 10;

	int64_t stage0 = -1;
	int64_t stage1 = -1;

	int stage = 0;
	int drought = 0;
	for (int64_t i = 0, mod = 0; i < LX; i++, drought++) {
		if (stage == 2 || drought > atMost)
			break;
		state = next(state, A[mod]);
		switch (stage) {
			case 0:
				if (state == 2) {
					stage0 = i;
					stage = 1;
					drought = 0;
				}
				break;
			case 1:
				if (state == 4) {
					stage1 = i;
					stage = 2;
					drought = 0;
				}
				break;
			case 2:
				break;
		}
		mod++;
		if (mod == L) mod = 0;
	}
	// cout << "STATE = " << state << endl;
	// cout << "STAGE = " << stage << endl;
	return stage == 2;
}

int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> L;
		cin >> X;
		cin >> S;
		for (int j = 0; j < L; j++) {
			switch (S[j]) {
				case 'i': A[j] = 2; break;
				case 'j': A[j] = 3; break;
				case 'k': A[j] = 4; break;
			}
		}
		bool answer = solve();
		printf("Case #%d: %s\n", i + 1, answer ? "YES" : "NO");
	}
	return 0;
}
