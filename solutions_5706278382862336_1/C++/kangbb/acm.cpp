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

int N;
ull P, Q;

ull gcd(ull a, ull b) {
	if(a==0) return b;
	return gcd(b%a, a);
}

int main() {
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	//freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {

		scanf("%llu/%llu", &P, &Q);


		ull g = gcd(P, Q);
		P = P / g;
		Q = Q / g;

		int ansp = 0;
		int ansq = 0;
		int cnt = 0;

		forn(i, 64) {
			if((Q & ((ull)1 << i))) {
				ansq = i;
				cnt++;
			}
			if((P & ((ull)1 << i))) {
				ansp = i;
			}
		}

		if(cnt > 1) {
			printf("Case #%d: impossible\n", casenum++);
		} else {
			printf("Case #%d: %d\n", casenum++, ansq - ansp);
		}

		fflush(stdout);
	}
	return 0;
}
