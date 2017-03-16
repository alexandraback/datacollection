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

int64 a, b;
int n;
int64 p[10005];

	int chk(int64 u)
	{
		stringstream IN;
		IN << u;
		string ss;
		IN >> ss;
		string tt = ss;
		reverse(tt.begin(), tt.end());
		if (ss == tt) return 1;
		return 0;
	}

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);

	n = 0;
	for (int i = 1; i <= 10000000; ++i)
	if (chk(i)) {
		if (chk((int64)i * i)) p[++n] = (int64)i * i;
	}
	//printf("%d\n", n);

	int Tests, tts = 0;
	for (scanf("%d", &Tests); Tests--; ) {
		scanf("%I64d%I64d", &a, &b);
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		if (a <= p[i] && p[i] <= b) ++ans;
		printf("Case #%d: %d\n", ++tts, ans);
	}
	return 0;
}
