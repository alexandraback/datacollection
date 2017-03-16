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

int n, m;
int a[105][105];

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int Tests, tts = 0;
	for (scanf("%d", &Tests); Tests--; ) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		scanf("%d", &a[i][j]);

		bool ff = 1;
		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			int tl = 0, tu = 0;
			for (int k = 1; k < j; ++k)
			if (a[i][k] > a[i][j]) tl = 1;
			for (int k = j + 1; k <= m; ++k)
			if (a[i][k] > a[i][j]) tl = 1;
			for (int k = 1; k < i; ++k)
			if (a[k][j] > a[i][j]) tu = 1;
			for (int k = i + 1; k <= n; ++k)
			if (a[k][j] > a[i][j]) tu = 1;
			if (tl + tu == 2) {
				ff = 0;
				break;
			}
		}
		printf("Case #%d: ", ++tts);
		if (ff) puts("YES"); else puts("NO");
	}
	return 0;
}
