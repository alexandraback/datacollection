#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
#include <vector>
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define taskname "b"
using namespace std;

const int N = 200 + 1;
int t, n, s, p, x, ans[N][N];

int main() {
	freopen(taskname".in", "r", stdin);
	freopen(taskname".out", "w", stdout);
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		memset(ans, 0, sizeof(ans));
		scanf("%d%d%d", &n, &s, &p);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			for (int m1 = 0; m1 <= 10; ++m1)
				for (int m2 = m1; m2 <= 10; ++m2) {
					int m3 = x - m1 - m2;
					if ((m3 < m2) || (m3 > 10) || (m3 > m1 + 2)) continue;
					int surprise = (m3 == m1 + 2), win = (m3 >= p);
					for (int j = 0; j <= s; ++j)
						ans[i + 1][j + surprise] = max(ans[i + 1][j + surprise], ans[i][j] + win);
				}
		}
		printf("Case #%d: %d\n", it + 1, ans[n][s]);
	}
	return 0;
}