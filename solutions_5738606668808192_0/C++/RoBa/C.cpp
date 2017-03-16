#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
LL sol[20];

LL fact(LL k) {
	if (k % 2 == 0) return 2;
	for (LL i = 3 ; i * i <= k ; i += 2) {
		if (k % i == 0) return i;
	}
	return k;
}

bool check(LL mask, int base) {
	LL v = 0;
	while (mask) {
		v = v * base + (mask&1);
		mask >>= 1;
	}
	LL f = fact(v);
	if (f != v) {
		sol[base] = f;
		return true;
	}
	return false;
}

void output(LL mask) {
	while (mask) {
		if (mask&1) cout << "1";
		else cout << "0";
		mask >>= 1;
	}
}

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		int N, J;
		printf("Case #%d:\n", ca);
		scanf("%d%d",&N,&J);
		for (LL mask = (1LL<<(N-1)) + 1 ; J > 0; mask += 2) {
			int succ = 1;
			for (int base = 2 ; base <= 10 ; ++base) {
				if (!check(mask, base)) {
					succ = 0;
					break;
				}
			}
			if (succ) {
				// cout << "[" << mask << "] ";
				output(mask);
				for (int i = 2 ; i <= 10 ; ++i)
					cout << " " << sol[i];
				cout << endl;
				--J;
			}
		}
	}
	return 0;
}