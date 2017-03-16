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

const int N = 55555;

int n;
int result;
int timer = 0;
int p[N];
int tin[N];
bool used[N];
int pp[N];

int go;

void dfs(int x, int y) {
	++timer;
	int nxt = p[x];
	if (nxt == y || nxt == go) {
		result = max(result, timer);
	}
	if (nxt == y) {
		for (int i = 1; i <= n; i++) {
			if (!used[i]) {

			}
		}
	}
	if (used[nxt]) {
		if (go == nxt) {
			result = max(result, timer);
		}
		return;
	}
	used[x] = true;
	dfs(p[x], x);
}

void solve(int test) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		scanf("%d", &pp[i]);
	}
	/*result = 0;
	for (int i = 1; i <= n; i++) {
		go = i;
		timer = 0;
		for (int j = 1; j <= n; j++) used[j] = false;
		dfs(i, -1);
	}*/
	result = 0;
	do {
		for (int i = 2; i <= n; i++) {
			int head = p[1];
			int tail = p[i];
			bool cor = true;
			for (int j = 1; j <= i; j++) {
				int id = p[j];
				id = pp[id];
				int nxt = p[j + 1];
				if (j + 1 > i) nxt = head;
				int pr = p[j - 1];
				if (j == 1) {
					pr = tail;
				}
				if (id == nxt || id == pr) {
					continue;
				} else {
					cor = false;
					break;
				}
			}
			if (cor) result = max(result, i);
		}
	} while (next_permutation(p + 1, p + 1 + n));
	printf("Case #%d: %d\n", test, result);
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