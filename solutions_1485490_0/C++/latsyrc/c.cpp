#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100 + 10;

long long a[maxn], b[maxn];
int A[maxn], B[maxn];
int n, m;
long long ans;

void DFS(int x, int y, long long cnt) {
	if (x == n - 1) {
		long long remain = a[x];
		for (int i = y; i < m && remain > 0; ++i)
			if (A[x] == B[i]) {
				long long tmp = min(remain, b[i]);
				remain -= tmp;
				cnt += tmp;
			}
		if (cnt > ans) ans = cnt;

		return;
	}

	DFS(x + 1, y, cnt);

	long long remain = a[x];
	for (int i = y; i < m && remain > 0; ++i) {
		if (A[x] == B[i]) {
			long long tmp = min(remain, b[i]);
			remain -= tmp;
			b[i] -= tmp;
			cnt += tmp;
			DFS(x + 1, i, cnt);
			b[i] += tmp;
		}
	}
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%I64d%d", &a[i], &A[i]);
		for (int i = 0; i < m; ++i) scanf("%I64d%d", &b[i], &B[i]);

		ans = 0;
		DFS(0, 0, 0);

		printf("Case #%d: %I64d\n", nCase, ans);
	}

	return 0;
}
