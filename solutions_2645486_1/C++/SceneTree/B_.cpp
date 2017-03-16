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

const int lim = 10000000;

map<int, int> mym;
int E, R, n;
struct TData {
	int x, y;
} a[11111];
int64 s[11111];
int l[11111], r[11111];

	int cmpa(TData u, TData v)
	{
		return u.x > v.x;
	}

	int getfa(int v)
	{
		if (mym[v] == -1) return v;
		mym[v] = getfa(mym[v]);
		return mym[v];
	}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int Tests, tts = 0;
	for (scanf("%d", &Tests); Tests--; ) {
		scanf("%d%d%d", &E, &R, &n);

		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i].x);
			a[i].y = i;
		}
		mym.clear();
		sort(a + 1, a + n + 1, cmpa);
		mym[-lim] = -1;
		mym[lim] = -1;

		int64 ans = 0;
		for (int i = 1; i <= n; ++i) {
			mym[a[i].y] = -1;
			s[a[i].y] = 0;
			l[a[i].y] = r[a[i].y] = a[i].y;
			map<int, int>::iterator p = mym.find(a[i].y);
			--p;
			if (p->first > -lim && (int64)(a[i].y - p->first) * R <= E) {
				int v = a[i].y, u = p->first;
				u = getfa(u);
				v = getfa(v);
				if (u != v) {
					mym[v] = u;
					l[u] = min(l[u], l[v]);
					r[u] = max(r[u], r[v]);
					s[u] += s[v];
				}
			}
			++p;
			++p;
			if (p->first < lim && (int64)(p->first - a[i].y) * R <= E) {
				int u = a[i].y, v = p->first;
				u = getfa(u);
				v = getfa(v);
				if (u != v) {
					mym[v] = u;
					l[u] = min(l[u], l[v]);
					r[u] = max(r[u], r[v]);
					s[u] += s[v];
				}
			}

			int xx = getfa(a[i].y);
			int64 tt = s[xx];
			s[xx] = (int64)E + (int64)(r[xx] - l[xx]) * R;
			ans += (int64)(s[xx] - tt) * a[i].x;
		}
		printf("Case #%d: %I64d\n", ++tts, ans);
	}
	return 0;
}
