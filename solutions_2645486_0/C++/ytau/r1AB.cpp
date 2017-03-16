#include <iostream>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <sstream>
#include <string>

#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>

#include <algorithm>

#include <utility>

using namespace std;

#define INF 2000000000
#define INFL 9000000000000000000LL
#define INFF 1.0e18
#define EPS 1.0e-8

int T, E, R, N, v[10005], q[100005][4], qr, qw;
long long ans;

long long dp[15][15];

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d%d%d", &E, &R, &N);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &v[i]);
		}
		memset(dp, -1, sizeof(dp));
		dp[0][E] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= E; ++j) {
				if (dp[i][j] >= 0) {
					int X = min(E, j + R);
					for (int k = 0; k <= X; ++k) {
						dp[i+1][X-k] = max(dp[i+1][X-k], dp[i][j] + k * v[i+1]);
					}
				}
			}
		}
		printf("Case #%d: %lld\n", tc, dp[N][0]);
	}
	return 0;
}

/*

void qpush(int i, int j, int x, int y) {
	q[qw][0] = i;
	q[qw][1] = j;
	q[qw][2] = x;
	q[qw][3] = y;
	qw++;
	if (qw == 100005) qw = 0;
}

int m[10005], mw;
void doit() {
	int I = q[qr][0];
	int J = q[qr][1];
	int X = q[qr][2];
	int Y = q[qr][3];
	qr++;
	if (qr == 100005) qr = 0;
	if (I == J) {
		ans += max(0, X - max(0, Y - R)) * (long long) v[I];
		return ;
	}
	mw = 0;
	for (int i = J; i >= I; --i) {
		if (mw == 0 || v[i] >= v[m[mw-1]]) {
			m[mw++] = i;
		}
	}
	for (int i = 0; i < mw; ++i) {
		
	}
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d%d%d", &E, &R, &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &v[i]);
		}
		ans = 0;
		qr = qw = 0;
		qpush(E, 0, N-1, 0);
		while (qr != qw) {
			doit();
		}
	}
	return 0;
}
*/

