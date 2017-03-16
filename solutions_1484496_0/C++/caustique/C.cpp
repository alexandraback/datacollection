#pragma comment(linker, "/stack:64000000")

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

typedef long long llong;

const int MAX = 22;

int n;
int a[MAX];
map <int, int> h;

void print(int mask) {
	REP(i, n) {
		if (mask & (1 << i)) {
			cout << a[i] << " ";
		}
	}
	cout << endl;
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int tests;
	cin >> tests;
	for (int tst = 1; tst <= tests; tst++) {		
		printf("Case #%d:\n", tst);
		cin >> n;
		REP(i, n) cin >> a[i];
		h.clear();
		bool OK = false;
		for (int mask = 1; mask < (1 << n); mask++) {
			int res = 0;
			REP(i, n) {
				if (mask & (1 << i)) {
					res += a[i];
				}
			}
			if (h.count(res)) {						
				print(h[res]);
				print(mask);
				OK = true;
				break;
			} else {
				h[res] = mask;
			}
		}
		if (!OK) {
			puts("Impossible");
		}
	}
	return 0;
}