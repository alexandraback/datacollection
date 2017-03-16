#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
using namespace std;
#define VI vector<int>
#define L(s) (int)((s).size())
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define x first
#define y second
#define ll long long
#define inf 1000000000
int cases, N, S, p;
int f[111][111];
int main() {
	freopen("/home/maksay/Downloads/B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> cases;
	for(int casenum = 1; casenum <= cases; ++casenum) {
		cerr << casenum << endl;
		memset(f, 0, sizeof(f));
		cin >> N >> S >> p;
		for(int i = 0; i < N; ++i) {
			int x; cin >> x;
			for(int a = 0; a <= 10 && a <= x; ++a) {
				for(int b = 0; b <= a && a + b <= x; ++b) {
					int c = x - a - b;
					if (c > 10) continue;
					int up = max(max(a, b), c);
					int dn = min(min(a, b), c);
					if (up - dn > 2) continue;
					int sup = 0; if (up - dn == 2) sup = 1;
					int over = 0; if (up >= p) over = 1;
					for(int j = 0; j <= i; ++j) {
						f[i + 1][j + sup] = max(f[i + 1][j + sup], f[i][j] + over);
					}
				}
			}
		}
		printf("Case #%d: %d\n", casenum, f[N][S]);
	}
	return 0;
}
