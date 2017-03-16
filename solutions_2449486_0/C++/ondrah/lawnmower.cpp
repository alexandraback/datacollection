#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B)	for(int I = (A); I < (B); ++I)
#define REP(I,N)	FOR(I,0,N)
#define ALL(A)		(A).begin(), (A).end()

using namespace std;
int n,m;
int A[111][111];
int B[111][111];
int main()
{
	int T;
	scanf("%d", &T);
	REP(t, T) {
		scanf("%d %d", &n, &m);
		REP(i, n) REP(j, m) B[i][j] = 100;
		REP(i, n) REP(j, m) scanf("%d", &A[i][j]);
		REP(i, n) {
			int x = 0;
			REP(j, m) x = max(x, A[i][j]);
			REP(j, m) B[i][j] = x;
		}
		REP(i, m) {
			int x = 0;
			REP(j, n) x = max(x, A[j][i]);
			REP(j, n) B[j][i] = min(B[j][i], x);
		}
		bool same = true;
		REP(i, n) REP(j, m) if(A[i][j] != B[i][j]) same = false;
		printf("Case #%d: ", t+1);
		if(same) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
