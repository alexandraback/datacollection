// Michal Lazowik
// Google Code Jam 2013
// Round 1c
// Problem A.

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

typedef long long ll;

#define REP(x, n) for (int x = 0; x < (n); ++x)
#define FOR(x, b, e) for (int x = b; x <= (e); ++x)
#define FORD(x, b, e) for (int x = b; x >= (e); --x)

#define FOREACH(it, cont) for (__typeof(cont.begin()) it = cont.begin(); it != cont.end(); ++it)

#define PB push_back

#define F first
#define S second
#define MP make_pair

const int MAX = 1e6;

int n;
char str[MAX+10];

int check(char a) {
	switch (a) {
		case 'a': return 0;
		case 'e': return 0;
		case 'i': return 0;
		case 'o': return 0;
		case 'u': return 0;
		default: return 1;
	}

	return 1;
}

ll count() {
	int count = 0, l = strlen(str), m = 0;
	ll ret = 0;

	REP(i, l) {
		FOR(j, i, l-1) {
			count = 0;
			m = 0;
			FOR(k, i, j) {
				if (check( str[k] ) == 0) {
					m = max(count, m);
					count = 0;
				} else
					count++;
			}

			m = max(count, m);

			if (m >= n)
				ret++;
		}
	}

	return ret;
}

int main() {
	int t;

	scanf("%d", &t);
	REP(case_num, t) {
		scanf("%s %d", str, &n);

		printf("Case #%d: %lld\n", case_num+1, count());
	}

	return 0;
}
