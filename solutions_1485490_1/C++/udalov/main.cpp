#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <functional>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define forit(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define eprintf(...) { fprintf(stderr, __VA_ARGS__); fflush(stderr); }
#define sz(v) ((int)((v).size()))
typedef pair<int, int> ii;
typedef long long LL;

#define N 104
const LL inf = 3000000000000000000LL;
int n, m;
LL a[N], b[N];
int A[N], B[N];
LL mem[N][N], sum[N][N];

LL go(int i, int j) {
	if (i == n || j == m) return 0;
	LL& z = mem[i][j];
	if (z != -1) return z;
	LL total = 0;
	z = -inf;
	for (int ii = i; ii <= n; ii++) {
		LL u = 0, left = total;
		for (int jj = j; jj <= m; jj++) {
			if (ii == i && jj == j) continue;
			if (u + sum[ii][jj] < z) continue;
			z = max(z, u + go(ii, jj));
			if (A[i] == B[jj]) {
				LL x = min(left, (LL)b[jj]);
				left -= x;
				u += x;
			}
		}
		if (A[i] == A[ii])
			total += a[ii];
	}
	return z;
}

int main() {
	int __;
	scanf("%d", &__);
	forn(_, __) {
		scanf("%d%d", &n, &m);
		forn(i, n) scanf("%I64d%d", &a[i], &A[i]);
		forn(i, m) scanf("%I64d%d", &b[i], &B[i]);
		memset(sum, 0, sizeof sum);
		memset(mem, -1, sizeof mem);
		for (int i = n-1; i >= 0; i--) sum[i][m] = a[i] + sum[i+1][m];
		for (int j = m-1; j >= 0; j--) sum[n][j] = b[j] + sum[n][j+1];
		for (int i = n-1; i >= 0; i--) for (int j = m-1; j >= 0; j--)
			sum[i][j] = a[i] + sum[i+1][j], assert(sum[i][j] == b[j] + sum[i][j+1]);
//		forn(i, n) forn(j, m) printf("go(%d, %d) = %I64d\n", i, j, go(i, j));
		printf("Case #%d: %I64d\n", _+1, go(0, 0));
		eprintf("%d\n", _+1);
	}
	return 0;
}
