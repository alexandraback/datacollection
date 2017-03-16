#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>

using namespace std;

int r, n, m, k;
int arr[5];
int v[7];
int my[3];

bool ok(int idx, int p, int q) {
	if(idx == n) {
		return p == 1;
	}
	if(q == n)
		return false;
	if(p % my[idx] == 0) {
		return ok(idx + 1, p, q + 1) || ok(idx, p / my[idx], q + 1) || ok(idx + 1, p / my[idx], q + 1);
	}
	return ok(idx + 1, p, q + 1);
}

bool solve() {
	for(int i = 0; i < k; ++i) {
		if(!ok(0, v[i], 0)) {
			return false;
		}
	}
	return true;
}

bool rec(int idx, int c) {
	if(c == n) {
		return solve();
	}
	if(idx == 4)
		return false;
	my[c] = arr[idx];
	if(rec(idx, c + 1)) {
		return true;
	}
	my[c] = arr[idx];
	if(rec(idx + 1, c + 1))
		return true;
	if(rec(idx + 1, c)) {
		return true;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif
	
	arr[0] = 2; arr[1] = 3; arr[2] = 4; arr[3] = 5;
	int T;
	scanf("%d", &T);
	for(int tst = 1; tst <= T; ++tst) {
		printf("Case #%d:\n", tst);
		scanf("%d %d %d %d", &r, &n, &m, &k);
		while(r--) {
			for(int i = 0; i < k; ++i)
				scanf("%d", &v[i]);
			rec(0, 0);
			for(int i = 0; i < n; ++i)
				cout << my[i];
			cout << endl;
		}
	}

	return 0;
}
