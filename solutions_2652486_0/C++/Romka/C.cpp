#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

void solve() {
	int r, n, m, k, a[14];
	scanf("%d %d %d %d", &r, &n, &m, &k);
	forn(i, r) {
		forn(j, k) scanf("%d", &a[j]);
		for (int q = 2; q <= m; q++)
			for (int w = q; w <= m; w++)
				for (int e = w; e <= m; e++) {
					set<int> ss;
					ss.insert(1);
					ss.insert(q);
					ss.insert(w);
					ss.insert(e);
					ss.insert(q*w);
					ss.insert(q*e);
					ss.insert(w*e);
					ss.insert(q*w*e);

					bool ok = true;
					forn(j, k)
						if (ss.find(a[j]) == ss.end()) {
							ok = false;
							break;
						}

					if (ok) {
						printf("%d%d%d\n", q, w, e);
						goto next;
					}
				}
		next:;
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int q = 1; q <= tc; q++) {
		printf("Case #%d:\n", q);
		solve();
	}
	return 0;
}