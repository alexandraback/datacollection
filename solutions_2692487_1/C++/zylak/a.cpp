#include <cstdio>
#include <algorithm>
#define REP(x,n) for(int x=0; x<(n); ++x)
#define FOR(i,b,e) for(int i=(b); i<=(e); ++i)
using namespace std;

const int MAXN = 100;


int a, n, t[MAXN], r;


int main()
{
	int Q; scanf("%d", &Q);
	FOR(q, 1, Q) {
		scanf("%d%d", &a, &n);
		REP(i, n) scanf("%d", &t[i]);
		sort(t, t+n);
		
		r = n;
		if (a > 1) {
			int now = 0;
			REP(i, n) {
				while (a <= t[i]) a += a-1, ++now;
				a += t[i];
				r = min(r, now + n-i-1);
			}
		}
		
		printf("Case #%d: %d\n", q, r);
	}
	
	return 0;
}
