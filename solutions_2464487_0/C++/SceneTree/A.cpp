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

int64 r, t;

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int Tests, tts = 0;
	for (scanf("%d", &Tests); Tests--; ) {
		scanf("%I64d%I64d", &r, &t);
		/*double A = 2.0;
		double B = 2.0 * (double)r + 3.0;
		double C = B - 2.0 -(double)t;
		double delta = B * B - 4 * A * C;
		double x = (-B + sqrt(delta)) / 2.0 / A + 1;
		printf("%.5lf\n", x);*/
		int64 L = 0, R = 2000000000;
		for (; L + 1 < R; ) {
			int64 M = (L + R) / 2;
			int64 tt = 2LL * r + 2LL * M + 1;
			if (tt <= t / (M + 1)) L = M; else R = M;
		}
		printf("Case #%d: %I64d\n", ++tts, L + 1);
	}
	return 0;
}
