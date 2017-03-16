#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define SIZE(v) ((int)(v).size())

#define BEGIN(v) ((v).begin())
#define END(v) ((v).end())
#define ALL(v) BEGIN(v),END(v)
#define SORT(v) sort(ALL(v))
#define UNIQUE(v) SORT(v);(v).erase(unique(ALL(v)),END(v))

#define FOR(i,l,r) for(int i=(l);i<(r);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)

const int MAXN = 5000;

int x, y, sum;
int guess[MAXN];

bool solvable(int bound) {
	int cursum = bound * (bound + 1) / 2, diff = cursum - sum;
	if (diff & 1) return false;
	diff >>= 1;
	FOR(i, 0, min(bound, diff) + 1) {
		int j = diff - i;
		if (i > 0 && i == j) continue;
		memset(guess, 0, sizeof(int) * (bound + 1));
		guess[i] = -1;
		guess[j] = -2;
		int rem = abs(x) + i;
		for (int k = bound; k > 0; k--) {
			if (guess[k]) continue;
			if (rem >= k) {
				rem -= k;
				guess[k] = 1;
			} else {
				guess[k] = 2;
			}
		}
		if (!rem) return true;
	}
	return false;
}

int main() {
	int taskNumber;
	scanf("%d", &taskNumber);
	for (int taskIdx = 1; taskIdx <= taskNumber; taskIdx++) {
		scanf("%d%d", &x, &y);
		sum = abs(x) + abs(y);
		int tmpsum = 0, bound;
		for (bound = 1; tmpsum < sum; bound++) tmpsum += bound;
		bound--;
		for ( ; !solvable(bound); bound++) ;
		printf("Case #%d: ", taskIdx);
		for (int i = 1; i <= bound; i++) {
			if (guess[i] == 1) {
				if (x > 0) putchar('E');
				else putchar('W');
			} else if (guess[i] == 2) {
				if (y > 0) putchar('N');
				else putchar('S');
			} else if (guess[i] == -1) {
				if (x > 0) putchar('W');
				else putchar('E');
			} else if (guess[i] == -2) {
				if (y > 0) putchar('S');
				else putchar('N');
			}
		}
		putchar('\n');
	}
	return 0;
}
