#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

typedef long long ll;

const int MAXN= 20;
int a[MAXN][MAXN];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int r = n * m;
	int ans = k;
	forn(mask, (1 << r)) {
		int c = 0;
		int cnt = 0;
		forn(i, n) {
			forn(j, m) {
				a[i][j] = (mask & (1 << c)) ? 1 : 0;
				++c;
				cnt += a[i][j];
			}
		}
		int cur = 0;
		forn(i, n) {
			bool left = false;
			forn(j, m) {
				if (a[i][j]) {
					++cur;
					left = true;
				} else if (left) {
					bool down = false, up = false;
					bool right = false;
					for (int j1 = j + 1; j1 < m; ++j1) if (a[i][j1] > 0) {
						right = true;
					}
					if (right) {
						for (int i1 = 0; i1 < n; ++i1) {
							if (a[i1][j]) {
								if (i1 < i) {
									up = true;
								} else {
									down = true;
								}
							}
						}
						if (up && down) {
							++cur;
						}
					}
				}
			}
		}
		if (cur >= k) {
			ans = min(ans, cnt);
		}
	}
	cout << ans << endl;
}

int main(int argc, char **argv) {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int tt;
	cin >> tt;
	forn(t, tt) {
		cout << "Case #" << (t + 1) << ": ";
		solve();
	}
	return 0;
}
