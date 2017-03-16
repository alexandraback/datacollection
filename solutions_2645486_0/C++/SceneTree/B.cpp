#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1E-7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
#define Abs(x) ((x) < 0 ? (-(x)) : (x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

int E, R, n;
int f[100][100];
int a[100];

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

	int Tests, tts = 0;
	for (scanf("%d", &Tests); Tests--; ) {
		scanf("%d%d%d", &E, &R, &n);
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

		memset(f, -1, sizeof(f));
		f[0][E] = 0;
		for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= E; ++j)
		if (f[i - 1][j] >= 0) {
			for (int k = 0; k <= j; ++k) {
				if (f[i - 1][j] + k * a[i] > f[i][min(E, j - k + R)]) {
					f[i][min(E, j - k + R)] = f[i - 1][j] + k * a[i];
				}
			}
		}

		int ans = -1;
		for (int j = 0; j <= E; ++j) ans = max(ans, f[n][j]);

		printf("Case #%d: %d\n", ++tts, ans);
	}
	return 0;
}
