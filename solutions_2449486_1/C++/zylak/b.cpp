#include <cstdio>
#include <algorithm>
#define REP(x,n) for(int x=0; x<(n); ++x)
#define FOR(i,b,e) for(int i=(b); i<=(e); ++i)
using namespace std;

const int MAX = 100;

int n, m, t[MAX][MAX], x[MAX], y[MAX];

bool ok()
{
	REP(i, n) REP(j, m) if (t[i][j]<x[i] && t[i][j]<y[j])
		return false;
	return true;
}


int main()
{
	int Q; scanf("%d", &Q);
	FOR(q, 1, Q) {
		scanf("%d%d", &n, &m);
		REP(i, n) x[i] = 0;
		REP(i, m) y[i] = 0;
		
		REP(i, n) REP(j, m) {
			scanf("%d", &t[i][j]);
			x[i] = max(x[i], t[i][j]);
			y[j] = max(y[j], t[i][j]);
		}
		
		printf("Case #%d: %s\n", q, ok() ? "YES" : "NO");
	}
	
	return 0;
}
