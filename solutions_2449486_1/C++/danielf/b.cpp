#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << endl)

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define _FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define foreach(x...) _FOR(x)
#define fu(i, a) foreach(i, 0, a)
#define forall(i, v) foreach(i, all(v))

#define MSET(c, v) memset(c, v, sizeof(c))

#define pb push_back
#define sz(c) int((c).size())

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int L[110][110];

bool mark[110][110];

int main() {
	int T;
	scanf("%d", &T);
	fu(t, T) {
		printf("Case #%d: ", t+1);
		int N, M;
		scanf("%d %d", &N, &M);
		fu(i,N) fu(j,M) scanf("%d", &L[i][j]);
		MSET(mark, false);
		// horizontal
		fu(i, N) {
			int ma = L[i][0];
			fu(j, M) ma = max(ma, L[i][j]);
			fu(j, M) if (L[i][j] == ma) mark[i][j] = true;
		}
		// vertical
		fu (j, M) {
			int ma = L[0][j];
			fu(i, N) ma = max(ma, L[i][j]);
			fu(i, N) if (L[i][j] == ma) mark[i][j] = true;
		}
		bool ans = true;
		fu(i, N) fu(j, M) if (!mark[i][j]) ans = false;
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
