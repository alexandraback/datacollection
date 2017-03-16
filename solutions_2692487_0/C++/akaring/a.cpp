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

const int MAXN = 1000100;

int main() {
	int n_case;
	scanf("%d", &n_case);
	for (int index = 1; index <= n_case; ++index) {
		long long A;
		int N;
		scanf("%lld%d", &A, &N);

		static long long a[MAXN];
		REP (i, N) {
			scanf("%lld", &a[i + 1]);
		}
		sort(a + 1, a + 1 + N);

		int ans = N;
		for (int i = 1, all = 0; i <= N && A != 1; ++i) {
			long long At = A;
			int cnt = 0;
			while (At <= a[i]) {
				++cnt;
				++all;
				At = At * 2 - 1;
			}
			checkMin(ans, all + N - i);
			REP (i, cnt) {
				A = A * 2 - 1;
			}
			A += a[i];
		}
		printf("Case #%d: %d\n", index, ans);
	}
	return 0;
}
