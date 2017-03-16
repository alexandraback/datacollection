#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define FILE_IN  "D-small-attempt1.in"
#define FILE_OUT "D-small-attempt1.out"

#define MAXK 202
#define MAXN 20

typedef vector<int> vi;

int key[MAXK];
int n;
int unlock[MAXN];
vi inside[MAXN];

int next[1<<MAXN];
void findnext(int state) {
	int mykeys[MAXK];
	copy(key, key + MAXK, mykeys);
	for (int i = 0; i < n; ++i) if (state & (1 << i)) {
		mykeys[unlock[i]] -= 1;
		for (int j = 0, jj = inside[i].size(); j < jj; ++j)
			mykeys[inside[i][j]] += 1;
	}
	for (int i = 0; i < n; ++i) {
		if (state & (1 << i))
			continue;
		if (mykeys[unlock[i]] <= 0)
			continue;
		if (next[state | (1 << i)] >= 0) {
			next[state] = i;
			return;
		}
	}
	next[state] = -1;
}

void solve() {
	int k;
	scanf("%d%d", &k, &n);
	fill(key, key + MAXK, 0);
	fill(inside, inside + MAXN, vi());
	for (int i = 0; i < k; ++i) {
		int x;
		scanf("%d", &x);
		key[x] += 1;
	}
	for (int i = 0; i < n; ++i) {
		int ki;
		scanf("%d%d", &unlock[i], &ki);
		for (int j = 0; j < ki; ++j) {
			int x;
			scanf("%d", &x);
			inside[i].push_back(x);
		}
	}
	next[(1 << n) - 1] = 0;
	for (int state = (1 << n) - 2; state >= 0; --state)
		findnext(state);
	if (next[0] >= 0) {
		int state = 0;
		while (state != (1 << n) - 1) {
			printf(" %d", next[state] + 1);
			state |= 1 << next[state];
		}
		printf("\n");
	} else {
		printf(" IMPOSSIBLE\n");
	}
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d:", i);
		solve();
	}
	return 0;
}
