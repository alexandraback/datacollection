#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <utility>
#include <memory.h>
#include <cassert>
#include <iterator>
#include <bitset>
#include <iomanip>
#include <complex>
#include <queue>
#include <ctime>
#include <deque>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N = 555;

int n;
int p[N];
bool used[N];
int a[N][N];

bool cmp(int x, int y) {
	if (x < 0) return true;
	for (int i = 1; i <= n; i++) {
		if (a[x][i] < a[y][i]) {
			return true;
		}
		if (a[x][i] > a[y][i]) {
			return false;
		}
	}
	return false;
}

bool SOLVED;

void go(int x, int y, int w, int test) {
	int px = p[x];
	int py = p[y];
	vector<int> idxs;
	multiset< vector<int> > have;
	idxs.pb(-1);
	int ptr = 1;
	if (w == 1) {
		ptr++;
	}
	int may = ptr;
	for (int i = 1; i < n + n; i++) {
		if (i == y) {
			continue;
		}
		if (ptr == may && i < x) {
			continue;
		}
		int pi = p[i];
		int id = ptr;
		if (id == w) {
			++ptr;
			id = ptr;
		}
		if (id > n) {
			break;
		}
		if (a[pi][n] != a[py][id]) {
			continue;
		}
		if (cmp(idxs.back(), pi)) {
			idxs.pb(pi);
			ptr++;
			if ((int)idxs.size() == n) {
				break;
			}
		}
	}

	if ((int)idxs.size() < n) {
		return;
	}
	if ((int)idxs.size() == n) {
		for (int i = 1; i <= n + n; i++) used[i] = false;
		for (int i = 0; i < (int)idxs.size(); i++) {
			used[idxs[i]] = true;
		}
		vector<int> rem;
		int id = 0;
		for (int i = 1; i < n + n; i++) {
			if (used[i]) continue;
			id++;
			a[n + n][id] = a[i][w];
			rem.pb(a[i][w]);
		}
		sort(rem.begin(), rem.end());
		for (int i = 1; i < n; i++) {
			if (rem[i] == rem[i - 1]) {
				return;
			}
		}
		int i1, i2;
		i1 = w - 1;
		i2 = i1 + 1;
		bool is = true;
		if (i1 >= 0 && i1 < idxs.size()) {
			is = cmp(idxs[i1], n + n);
		}
		if (i2 >= 0 && i2 < idxs.size()) {
			is &= cmp(idxs[i2], n + n);
		}
		if (!is) return;
		printf("Case #%d:", test);
		for (int j = 0; j < n; j++) {
			printf(" %d", rem[j]);
		}
		puts("");
		SOLVED = true;
		return;
	}
	for (int i = 1; i <= n + n; i++) used[i] = false;
	for (int i = 0; i < (int)idxs.size(); i++) {
		used[idxs[i]] = true;
	}
	for (int i = 1; i < n + n; i++) {
		if (!used[p[i]]) {
			vector<int> tmp;
			for (int j = 1; j <= n; j++) {
				tmp.pb(a[p[i]][j]);
			}
			have.insert(tmp);
		}
	}
	vector< vector<int> > rem;
	for (int i = 1; i <= n; i++) {
		vector<int> tmp;
		for (int j = 0; j < n; j++) {
			tmp.pb(a[idxs[j]][i]);
		}
		if (have.find(tmp) == have.end()) {
			rem.pb(tmp);
		} else {
			have.erase(have.find(tmp));
		}
	}
	if ((int)rem.size() == 1) {
		printf("Case #%d:", test);
		for (int j = 0; j < n; j++) {
			printf(" %d", rem[0][j]);
		}
		puts("");
		SOLVED = true;
		return;
	}
}

int cnt[3030];

void solve(int test) {
	scanf("%d", &n);
	for (int i = 0; i < 3030; i++) {
		cnt[i] = 0;
	}
	for (int i = 1; i < n + n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			cnt[x] ^= 1;
		}
	}
	printf("Case #%d:", test);
	for (int i = 1; i < 3030; i++) {
		if (cnt[i] == 1) {
			printf(" %d", i);
		}
	}
	puts("");
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		solve(i);
	}
	return 0;
}