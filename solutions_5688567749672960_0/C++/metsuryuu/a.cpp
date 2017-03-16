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


LL odwroc(LL x) {
	vector<int> v;
	while (x) {
		v.PB(x % 10);
		x /= 10;
	}
	LL wyn = 0;
	for (int digit : v) {
		wyn = 10 * wyn + digit;
	}
	return wyn;
}


LL X;
const int MAX_DP = 2000000;
LL dp[MAX_DP + 1];

int main()
{
	FOR(i, 1, MAX_DP) {
		dp[i] = INF;
	}
	dp[1] = 1;
	dp[2] = 2;
	
	FOR(i, 2, MAX_DP-1) {
		dp[i+1] = min(dp[i+1], dp[i] + 1);
		int rev = odwroc(i);
		if (rev <= MAX_DP) {
			dp[rev] = min(dp[rev], dp[i] + 1);
		}
	}
	
	int T;
	scanf("%d", &T);
	FOR(testCounter, 1, T){
		//wej
		scanf("%lld", &X);
		//prog
		
		//wyj
		printf("Case #%d: %lld\n", testCounter, dp[(int)X]);
	}
	return 0;
}
