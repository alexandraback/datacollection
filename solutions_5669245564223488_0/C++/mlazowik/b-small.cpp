// Michał Łazowik

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <utility>

using namespace std;

typedef long long LL;

#define REP(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, b, e) for (int x = b; x <= (e); ++x)
#define FORD(x, b, e) for (int x = b; x >= (e); --x)
#define FOREACH(it, cont) for (__typeof(cont.begin()) it = cont.begin(); it != cont.end(); ++it)

#define F first
#define S second
#define MP make_pair
#define PB push_back

const int MAX = 15;
const int MAXL = 105;
const int AS = 30;

int n, setsLen[MAX];
char sets[MAX][MAXL];

bool is_valid(vector<int> &p) {
	char last, curr;
	bool used[AS];

	REP(i, AS) {
		used[i] = false;
	}

	last = sets[p[0]][0];
	REP(i, n) {
		REP(j, setsLen[p[i]]) {
			curr = sets[p[i]][j];
			if (curr != last) {
				if (used[last - 'a'] || used[curr - 'a']) return false;
				used[last - 'a'] = true;
			}
			last = curr;
		}
	}

	return true;
}

int solve() {
	int ret = 0;
	vector<int> perm(n);

	REP(i, n) {
		perm[i] = i;
	}

	do {
		if (is_valid(perm)) ret++;
	} while (next_permutation(perm.begin(), perm.end()));

	return ret;
}

int main() {
	int t;
	char tmp[MAXL];

	scanf("%d", &t);

	FOR(q, 1, t) {
		scanf("%d", &n);
		REP(i, n) {
			scanf("%s", sets[i]);
			setsLen[i] = strlen(sets[i]);
		}

		printf("Case #%d: ", q);
		printf("%d", solve());
		printf("\n");
	}

	return 0;
}
