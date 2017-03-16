#include <bits/stdc++.h>
using namespace std;

int T, N, J;
#define LL long long

LL tobase(LL n, LL base) {
	LL r = 0, p = 1, b = 1;
	while (p < n) {
		if (n & p) r += b;
		p <<= 1;
		b *= base;
	}
	return r;
}

int main() {
	cin >> T >> N >> J;
	cout << "Case #1:" << endl;

	LL v = (1LL << (N-1)) + 1;
	LL lim = 1LL << N;
	while (J) {
		vector <LL> divisor(11);
		int Dmask = 0;
		for (int b=2; b<11; b++) {
			LL x = tobase(v, b);
			if (x%2 == 0) divisor[b] = 2, Dmask += 1<<(b-2);
			else {
				LL sx = sqrt(x);
				for (LL d=3; d<=sx; d+=2)
					if (x%d == 0) {
						divisor[b] = d, Dmask += 1<<(b-2);
						break;
					}
			}
		}

		if (Dmask == 511) {
			cout << tobase(v, 10);
			for (int b=2; b<11; b++)
				cout << " " << divisor[b];
			cout << endl;
			J--;
		}
		v+=2;
	}
}
