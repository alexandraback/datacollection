#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define FOR(i,n) for(int i = 0 ; i < n ; i++)
#define FORL(i,i0,n) for(int i = i0 ; i < n ; i++)
#define FORIT(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define ALL(x) x.begin(), x.end()
#define SZ(x) int(x.size())
#define LEN(x) int(x.length())
#define PB push_back
#define MP make_pair
#define FST(x) (x).first
#define SEC(x) (x).second
#define LL long long
#define mem(x, n) memset(x, n, sizeof(x))
#define ni() ({int t;scanf("%d",&t);t;})
#define SRAND() srand(time(NULL))
#define RAND(from, to) ((rand() % (to-from+1)) + (from))
#if 1
#define DBG(z) cerr << #z << ": " << (z) << endl
#else
#define DBG(z)
#endif
#define LOCAL 0
using namespace std;

LL Cn[111], Cm[111];
int Tn[111], Tm[111];
int N, M;
LL dp[111][111];

LL f(int i, int j) {
	if (i == N || j == M)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	LL ret = f(i + 1, j);
	ret = max(ret, f(i, j + 1));

	if (Tn[i] == Tm[j]) {
		ret = max(ret, f(i + 1, j + 1) + min(Cn[i], Cm[j]));
		if (Cn[i] != Cm[j]) {
			int x = i, y = j;
			LL gain = 0;
			LL Cx = Cn[x], Cy = Cm[y];
			while (x < N && y < M) {
				if (Cx > Cy) {
					LL newgain = gain + Cy;
					ret = max(ret, f(x + 1, y + 1) + newgain);
					Cx -= Cy;
					y++;
					while (Tn[x] != Tm[y] && y < M)
						y++;
					if (y == M)
						break;
					Cy = Cm[y];
					gain = newgain;
				} else {
					LL newgain = gain + Cx;
					ret = max(ret, f(x + 1, y + 1) + newgain);
					Cy -= Cx;
					x++;
					while (Tn[x] != Tm[y] && x < N)
						x++;
					if (x == N)
						break;
					Cx = Cn[x];
					gain = newgain;
				}
			}
		}
	}
	return dp[i][j] = ret;
}

int main() {
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	int t = ni();
	FOR(kase, t) {
		N = ni();
		M = ni();
		FOR(i, N)
			scanf("%lld%d", &Cn[i], &Tn[i]);
		FOR(i, M)
			scanf("%lld%d", &Cm[i], &Tm[i]);
		mem(dp, -1);
		printf("Case #%d: %lld\n", kase+1, f(0, 0));
	}
	return 0;
}
