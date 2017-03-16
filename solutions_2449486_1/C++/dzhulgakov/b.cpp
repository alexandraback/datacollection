#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define FN "B-large"
#define N 128
int n,m;
int a[N][N];

bool go() {
	while (true) {
		int mn = 101;
		REP(i,n) REP(j,m)
			if (a[i][j] != -1)
				mn = min(a[i][j],mn);
		if (mn==101) return true;
		REP(i,n) {
			bool ok = true;
			bool one = false;
			REP(j,m) if (a[i][j] != -1)  if (a[i][j] == mn) one = true; else {ok = false; break; }
			if (ok && one) {
				REP(j,m) a[i][j] = -1;
				goto end;
			}
		}
		REP(j,m) {
			bool ok = true;
			bool one = false;
			REP(i,n) if (a[i][j] != -1)  if (a[i][j] == mn) one = true; else {ok = false; break; }
			if (ok && one) {
				REP(i,n) a[i][j] = -1;
				goto end;
			}
		}
		return false;
		end:;
	}
}

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		printf("Case #%d: ",test);

		scanf("%d%d",&n,&m);
		REP(i,n) REP(j,m) scanf("%d",&a[i][j]);
		printf("%s\n", go()?"YES":"NO");
	}
	return 0;
}