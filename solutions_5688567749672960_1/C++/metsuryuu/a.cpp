/*	Arkadiusz Wróbel - metsuryuu
 *
 *	Konkurs: Google Code Jam 2015
 *	Zadanie: Counter Culture
 */
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <cmath>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

#define REP(I, N) for(int I = 0; I < (N); ++I)
#define FOR(I, M, N) for(int I = (M); I <= (N); ++I)
#define FORD(I, M, N) for(int I = (M); I >= (N); --I)
//#define FOREACH(IT, CON) for(__typeof((CON).begin()) IT = (CON).begin(); IT != (CON).end(); ++IT)

#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define SIZE(CON) ((int)(CON).size())
#define ALL(CON) (CON).begin(), (CON).end()

const int INF = 1000000000;
const LL INFLL = 1000000000000000000LL;

//######################################################################

vector<int> rozbij(LL x) {
	vector<int> v;
	while (x) {
		v.PB(x % 10);
		x /= 10;
	}
	return v;
}

LL odwroc(LL x) {
	LL wyn = 0;
	for (int digit : rozbij(x)) {
		wyn = 10 * wyn + digit;
	}
	return wyn;
}


const int MAX_DP = 2000000;
LL dp[MAX_DP + 1];


LL make(const LL X) {
	if (X < MAX_DP)
		return dp[(int)X];
	
	auto v = rozbij(X);
	LL modulo = 1;
	REP(i, (SIZE(v) / 2)) {
		modulo *= 10;
	}
	
	LL zaduzo = X % modulo;
	if (zaduzo == 0)
		return make(X-1) + 1;
	
	LL rev = odwroc(X - zaduzo + 1);
	
	if (rev < X - zaduzo + 1) {
		return make(rev) + zaduzo;
	} else {
		return make(X - zaduzo) + zaduzo;
	}
	
	return make(X-1) + 1;
}

int main()
{
	FOR(i, 1, MAX_DP) {
		dp[i] = INF;
	}
	dp[1] = 1;
	dp[2] = 2;
	
	FOR(i, 2, MAX_DP-1) {
		dp[i+1] = min(dp[i+1], dp[i] + 1);
		LL rev = odwroc(i);
		if (rev <= MAX_DP) {
			dp[rev] = min(dp[rev], dp[i] + 1);
		}
	}
	
	int T;
	scanf("%d", &T);
	FOR(testCounter, 1, T){
		//wej
		LL X;
		scanf("%lld", &X);
		//prog
		//if (X % 10000 == 0) fprintf(stderr, "(%lld)\n", X);
		//wyj
		printf("Case #%d: %lld\n", testCounter, make(X));
	}
	return 0;
}
