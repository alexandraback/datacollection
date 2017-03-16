#pragma comment(linker, "/stack:256000000")

#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <cassert>
#include <queue>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long start = clock();
#endif
	srand(time(NULL));
	int tst;
	int n, m, k, r;
	cin >> tst >> r >> n >> m >> k;
	cout << "Case #1:\n";
	REP(_, r) {
		vector <int> a(k);
		REP(i, k) cin >> a[i];
		vector <vector <int> > res;
		for (int x = 2; x <= m; x++) {
			for (int y = x; y <= m; y++) {
				for (int z = y; z <= m; z++) {
					vector <int> v;
					v.push_back(x);
					v.push_back(y);
					v.push_back(z);
					vector <int> can;
					REP(mask, 8) {
						int x = 1;
						REP(i, 3) {
							if (mask & (1 << i)) {
								x *= v[i];
							}
						}
						can.push_back(x);
					}
					sort(all(can));
					bool OK = 1;
					REP(i, sz(a)) {
						if (!binary_search(all(can), a[i])) {
							OK = 0;
							break;
						}
					}
					if (OK) {
						res.push_back(v);
					}
				}
			}
		}
		int pos = rand() % sz(res);
		REP(i, 3) cout << res[pos][i];
		cout << "\n";
	}
#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3lf\n\n", (clock() - start) / 1000.);
#endif
	return 0;
}