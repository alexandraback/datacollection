#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define FOR(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
using namespace std;
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }

const int MAXN = 105;

bool gao() {
	static map<int, vector<pair<int, int>>> mp;
	mp.clear();

	int N, M, height;
	scanf("%d%d", &N, &M);
	REP (i, N) {
		REP (j, M) {
			scanf("%d", &height);
			mp[-height].push_back(make_pair(i, j));
		}
	}

	static bool row[MAXN], col[MAXN];
	fill(row, row + N, false);
	fill(col, col + M, false);
	FOR (iter, mp) {
		FOR (it, iter->second) {
			int x = it->first, y = it->second;
			if (row[x] && col[y]) {
				return false;
			}
		}
		FOR (it, iter->second) {
			int x = it->first, y = it->second;
			row[x] = col[y] = true;
		}
	}
	return true;
}

int main() {
	int n_case;
	scanf("%d", &n_case);
	for (int index = 1; index <= n_case; ++index) {
		printf("Case #%d: %s\n", index, gao() ? "YES" : "NO");
	}
	return 0;
}
