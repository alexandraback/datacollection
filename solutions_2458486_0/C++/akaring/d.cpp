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

const int MAXK = 205;

int N, T[20], initKey[MAXK];
vector<int> chest[20];
bool dp[1 << 20];
vector<int> path[1 << 20];

inline bool LexicalLess(const vector<int>& lhs, const vector<int>& rhs) {
	REP (i, (int)lhs.size()) {
		if (lhs[i] != rhs[i]) {
			return lhs[i] < rhs[i];
		}
	}
	return false;
}

void gao() {
	REP (s, 1 << N) {
		if (dp[s]) {
			static int key[MAXK];
			copy(initKey, initKey + MAXK, key);
			REP (i, N) {
				if ((s & (1 << i)) != 0) {
					FOR (iter, chest[i]) {
						key[*iter] += 1;
					}
					key[T[i]] -= 1;
				}
			}
			REP (i, N) {
				if ((s & (1 << i)) == 0 && key[T[i]] > 0) {
					int t = s | (1 << i);
					vector<int> pt = path[s];
					pt.push_back(i);
					if (!dp[t] || LexicalLess(pt, path[t])) {
						path[t] = pt;
					}
					dp[t] = true;
				}
			}
		}
	}
}

int main() {
	int n_case;
	scanf("%d", &n_case);
	for (int index = 1; index <= n_case; ++index) {
		int K;
		scanf("%d%d", &K, &N);

		fill(initKey, initKey + MAXK, 0);
		REP (i, K) {
			int type;
			scanf("%d", &type);
			initKey[type] += 1;
		}

		fill(chest, chest + 20, vector<int>());
		REP (i, N) {
			int Ki, k;
			scanf("%d%d", &T[i], &Ki);
			REP (j, Ki) {
				scanf("%d", &k);
				chest[i].push_back(k);
			}
		}

		fill(dp, dp + (1 << N), false);
		dp[0] = true;
		fill(path, path + (1 << N), vector<int>());
		gao();

		printf("Case #%d:", index);
		if (dp[(1 << N) - 1]) {
			FOR (iter, path[(1 << N) - 1]) {
				printf(" %d", *iter + 1);
			}
			printf("\n");
		} else {
			printf(" IMPOSSIBLE\n");
		}
	}
	return 0;
}
