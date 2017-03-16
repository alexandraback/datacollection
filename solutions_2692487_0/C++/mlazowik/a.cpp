// Michal Lazowik
// Google Code Jam 2013
// Round 1b
// Problem A.

#define REP(x, n) for (int x = 0; x < (n); ++x)

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 110;

long long a;
int n, motes[MAXN];

long long solve() {
	long long ops = 0, na, tmp;
	
	sort(motes, motes+n);

	REP(i, n) {
		if (motes[i] < a)
			a += motes[i];
		else {
			na = a;
			tmp = 0;
			while (motes[i] >= na && tmp < (n-i)) {
				na += (na-1);
				tmp++;
			}

			if (motes[i] < na) {
				a = na + motes[i];
				ops += tmp;
			} else {
				return ops + (n-i);
			}
		}
	}

	return min(ops, (long long)n);
}

int main() {
	int t, c = 0;

	scanf("%d", &t);
	while (t--) {
		c++;
		scanf("%lld %d", &a, &n);
		REP(i, n) {
			scanf("%d", &motes[i]);
		}

		printf("Case #%d: %lld\n", c, solve());
	}

	return 0;
}
