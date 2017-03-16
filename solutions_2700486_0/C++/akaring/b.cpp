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

namespace abc {
	int tot, cnt;
	int n, y;
	int stk[2];
	void dfs(int i, int upper) {
		if (i == n) {
			tot += 1;
			cnt += stk[0] >= y;
			return;
		}
		if (stk[0] < upper) {
			stk[0] += 1;
			dfs(i + 1, upper);
			stk[0] -= 1;
		}
		if (stk[1] < upper) {
			stk[1] += 1;
			dfs(i + 1, upper);
			stk[1] -= 1;
		}
	}

	int N, X, Y;
	double gao() {
		if (abs(X) + Y == 0) {
			return N >= 1;
		} else if (abs(X) + Y == 2) {
			if (N >= 6) {
				return 1;
			} else if (2 <= N && N <= 5) {
				tot = 0, cnt = 0, n = N - 1, y = Y + 1;
				stk[0] = stk[1] = 0;
				dfs(0, 2);
				return (double)cnt / tot;
			}
			return 0;

		} else if (abs(X) + Y == 4) {
			if (N >= 15) {
				return 1;
			} else if (7 <= N && N <= 14) {
				tot = 0, cnt = 0, n = N - 6, y = Y + 1;
				stk[0] = stk[1] = 0;
				dfs(0, 4);
				return (double)cnt / tot;
			}
			return 0;

		} else if (abs(X) + Y == 6) {
			if (16 <= N && N <= 20) {
				tot = 0, cnt = 0, n = N - 15, y = Y + 1;
				stk[0] = stk[1] = 0;
				dfs(0, 6);
				return (double)cnt / tot;
			}
			return 0;
		}
		return 0;
	}
}

int main() {
	int n_case;
	scanf("%d", &n_case);
	for (int index = 1; index <= n_case; ++index) {
		scanf("%d%d%d", &abc::N, &abc::X, &abc::Y);
		printf("Case #%d: %.10lf\n", index, abc::gao());
	}
	return 0;
}
