#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

const int ONE = 1, I = 2, J = 3, K = 4;

inline int sign(int x) {
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}

inline int combine(int l, int r) {
	int sgn = sign(l * r), ret = 0;
	l = abs(l); r = abs(r);
	if (l == ONE && r == ONE) ret = ONE;
	if (l == ONE && r == I) ret = I;
	if (l == ONE && r == J) ret = J;
	if (l == ONE && r == K) ret = K;
	if (l == I && r == ONE) ret = I;
	if (l == I && r == I) ret = -ONE;
	if (l == I && r == J) ret = K;
	if (l == I && r == K) ret = -J;
	if (l == J && r == ONE) ret = J;
	if (l == J && r == I) ret = -K;
	if (l == J && r == J) ret = -ONE;
	if (l == J && r == K) ret = I;
	if (l == K && r == ONE) ret = K;
	if (l == K && r == I) ret = J;
	if (l == K && r == J) ret = -I;
	if (l == K && r == K) ret = -ONE;
	return sgn * ret;
}

inline int inverse(int x) {
	int sgn = sign(x); x = abs(x);
	if (x == ONE) return sgn * ONE;
	if (x == I) return -sgn * I;
	if (x == J) return -sgn * J;
	if (x == K) return -sgn * K;
}

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int L, X;
		cin >> L >> X;
		vector<int> A(L, ONE), P(L, ONE);
		for (int i = 0; i < L; ++i) {
			char c;
			cin >> c;
			if (c == 'i') A[i] = I;
			if (c == 'j') A[i] = J;
			if (c == 'k') A[i] = K;
		}

		int F = ONE;
		for (int i = 0; i < L; ++i) {
			P[i] = F = combine(F, A[i]);
		}

		int FULLPROD = ONE;
		for (int i = 0; i < (X % 4); ++i)
			FULLPROD = combine(FULLPROD, F);
		
		bool y = false;
		int LPre = ONE, RPre = ONE, BLOCKS = 4;
		if (FULLPROD == combine(I, combine(J, K))) {
			for (int leftblocks = 0; leftblocks < BLOCKS; leftblocks++) {
				RPre = ONE;

				for (int rightblocks = 0; rightblocks < BLOCKS; rightblocks++) {

					if (leftblocks + rightblocks + 1 > X) continue;

					int ibt = X - leftblocks - rightblocks - 2;
					ibt %= BLOCKS;
					int ibt_value = ONE;
					for (int ao = 0; ao < ibt; ++ao)
						ibt_value = combine(ibt_value, F);

					for (int l = (leftblocks == 0 ? 1 : 0); l < L; ++l) {
						for (int r = (leftblocks + rightblocks + 1 == X ? l : 0); r < (rightblocks == 0 ? L - 1 : L); ++r) {
							int LV = (l > 0 ? P[l - 1] : ONE),
								RV = combine(inverse(P[r]), F);
							int MV;

							if (leftblocks + rightblocks + 1 == X) {
								MV = combine(inverse(LV), combine(F, inverse(RV)));
							}
							else {
								int LC = combine(inverse(LV), F),
									RC = P[r];
								MV = combine(LC, combine(ibt_value, RC));
							}

							y = y || (combine(LPre, LV) == I && MV == J && combine(RV, RPre) == K);
							if (y)break;
						}
						if (y)break;
					}
					if (y)break;

					RPre = combine(F, RPre);
				}
				if (y)break;

				LPre = combine(LPre, F);
			}
		}

		cout << "Case #" << t << ": " << (y ? "YES" : "NO") << endl;
	}
}