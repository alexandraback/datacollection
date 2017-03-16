#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>

using namespace std;
//-----------------------------------------------------------
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull) 1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

#define bit(i) ((ull)1 << i)
//-----------------------------------------------------------
//#define DBG
#define MAXN 110

int N, M, K;


int solve(int Ktmp){
	int p,  q;
	while(true) {
		p = (int)(sqrt(Ktmp) + 0.5);
		p = min(p, N);
		p = min(p, M);
		if((Ktmp % p == 0) || p == 1) break;
		Ktmp++;

	}

	q = Ktmp / p;
	//printf("p = %d q = %d\n", p, q);
	// skip 2 pieces
	if(q * p - 4 >= K + 2 && p >= 4 && q >= 4) {
		return p * 2 + q * 2 - 8 - 1;
	}

	//
	return p * 2 + q * 2 - 8;
}

int main() {
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	//freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {

		scanf("%d%d%d", &N, &M, &K);

		if(N <= 2 || M <= 2) {
			printf("Case #%d: %d\n", casenum++, K);
			fflush(stdout);
			continue;
		}

		if(K >= N * M - 4) {
			printf("Case #%d: %d\n", casenum++, N * 2 + M * 2 - 4 + K - N * M);
			fflush(stdout);
			continue;
		}

		int ans1 = solve(K + 4);



		int ans2 = solve(K + 3) + 1;

		int ans = min(ans1, ans2);

		//fflush(stdout);

		printf("Case #%d: %d\n", casenum++, min(ans, K));
		fflush(stdout);
	}
	return 0;
}
