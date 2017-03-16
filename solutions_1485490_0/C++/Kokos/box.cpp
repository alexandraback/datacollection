#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <sstream>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define FOR(x, b, e) for (int x = (b); x <= (e); ++x)
#define FORD(x, b, e) for (int x = (b); x >= (e); --x)
#define REP(x, n) for (int x = 0; x < (n); ++x)
#define VAR(v, n) typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int) (x).size())
#define EACH(i, c) for (VAR(i, (c).begin()); i != (c).end(); ++i)
#define REACH(i, c) for (VAR(i,(c).rbegin()); i != (c).rend(); ++i)
#define UNIQUE(v) do { sort(ALL(v)); (v).resize(unique(ALL(v)) - (v).begin()); } while (0)
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
#define skip continue
const int INF = 1000000001;

#define GET(x)			(scanf("%d", &(x)) == 1)
#define GETLL(x)			(scanf("%lld", &(x)) == 1)
#define GET2(x, y)		(scanf("%d %d", &(x), &(y)) == 2)
#define GET3(x, y, z)	(scanf("%d %d %d", &(x), &(y), &(z)) == 3)
#define GETS(x)			(scanf("%s", (x)) == 1)
#define DGET(x)			int x; GET(x);

template<class T, class U>
bool remax(T &_a, const U &_b) { return _a < _b ? (_a = _b, 1) : 0; }


#define DISP_LINE ""
//~ #define DISP_LINE __LINE__ << " "
#define DEB_COND 0
#define db(x) { if (DEB_COND) { cerr << DISP_LINE << #x << " " << x << endl; } }
#define dbv(x) { if (DEB_COND) { cerr << DISP_LINE << #x << ": "; EACH (__i, x) cerr << *__i << " "; cerr << endl; } }
#define dbf(x, b, e) { if (DEB_COND) { cerr << DISP_LINE << #x << ": "; FOR (__i, (b), (e)) cerr << x[__i] << " "; cerr << endl; } }
#define dbm(x) { if (DEB_COND) { cerr << DISP_LINE << #x << endl; } }



const int N = 101;

int TT[N][N], ttt;
ULL F[N][N];
int A[N], B[N];
LL a[N], b[N];
int n, m;

ULL f(int i, int j)
{
	db(i)db(j)
	if (i >= n || j >= m) {
		return 0;
	}
	if (TT[i][j] == ttt) {
		return F[i][j];
	}
	if (A[i] == B[j]) {
		LL get = min(a[i], b[j]);
		db(get)
		a[i] -= get;
		b[j] -= get;
		assert(a[i] == 0 || b[j] == 0);
		F[i][j] = get + f(i + (a[i] == 0), j + (b[j] == 0));
		
		a[i] += get;
		b[j] += get;
		
		TT[i][j] = ttt;
		return F[i][j];
	}
	TT[i][j] = ttt;
	return F[i][j] = max(f(i+1, j), f(i, j+1));
}

int main()
{
	DGET(t);
	FOR (tt, 1, t) {
		ttt = tt;
		GET2(n, m);
		
		REP (i, n) {
			GETLL(a[i]);
			GET(A[i]);
			if (i && A[i] == A[i-1]) {
				a[i-1] += a[i];
				--i;
				--n;
			}
		}
		
		REP (i, m) {
			GETLL(b[i]);
			GET(B[i]);
			if (i && B[i] == B[i-1]) {
				b[i-1] += b[i];
				--i;
				--m;
			}
		}
		
		printf("Case #%d: %llu\n", tt, f(0, 0));
	}
}
