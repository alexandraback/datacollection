#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cmath>

#define Fill(x,y) memset(x, y, sizeof(x))
#define Cpy(x,y) memcpy(x, y, sizeof(x))
#define fi first
#define se second
#define pb push_back
#define fo(i,a,b) for (int i = a; i <= b; i ++)
#define fd(i,a,b) for (int i = a; i >= b; i --)
#define SQR(x) ((x)*(x))
#define mkp make_pair

using namespace std;

typedef double DB;
typedef long long LL;
typedef pair <LL, LL> PL;
typedef pair <int, int> PI;
typedef pair <DB, DB> PD;
typedef pair <PI, PI> PIII;
typedef pair <PD, DB> LINE;

int Read()
 {
	char c; while (c = getchar(), (c != '-') && (c < '0' || c > '9'));
	bool neg = (c == '-'); int ret = (neg ? 0 : c - 48);
	while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
	return neg ? -ret : ret;
 }
 
const int MAXN = 105;

int E, R, N, v[MAXN], dp[MAXN][MAXN];

void update(int &x, int y) { if (x < y) x = y; }

int main()
 {
	freopen("B.in", "r", stdin), freopen("B.out", "w", stdout);
	int cases = Read(); fo (cas, 1, cases)
	 {
		scanf("%d%d%d", &E, &R, &N);
		fo (i, 1, N) v[i] = Read();
		printf("Case #%d: ", cas);
		Fill(dp, -1); dp[0][E] = 0;
		fo (i, 1, N) fo (j, 0, E) if (dp[i-1][j] >= 0)
			fo (k, 0, j) update(dp[i][min(j-k+R, E)], dp[i-1][j] + k * v[i]);
		int ans = -1;
		fo (i, 0, E) ans = max(ans, dp[N][i]);
		printf("%d\n", ans);
	 }
	return 0;
 }
