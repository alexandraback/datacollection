#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <ctime>

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <iostream>
#include <numeric>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair


typedef long long int64;
typedef unsigned long long uint64;

template<typename T> int size(const T& c) { return (int)c.size(); }
template<typename T> inline void relaxmin(T& a, const T& b) { if (a > b) a = b; }
template<typename T> inline void relaxmax(T& a, const T& b) { if (a < b) a = b; }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }
template<typename T> int sign(T x) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; } 

string str( int i ) { char s[100]; sprintf(s, "%d", i); return string(s); }


void Solve(int caseNo)
{
	int n;
	string s;
	cin >> s >> n;

	int64 ans = 0;
	forn(i,s.length()) {
		for(int j = i; j < s.length(); ++j) {
			int consCnt = 0;
			for(int k = i; k <= j; ++k) {
				if (s[k] == 'a' || s[k] == 'e' || s[k] == 'i' || s[k] == 'o' || s[k] == 'u') {
					consCnt = 0;
				} else {
					consCnt++;
					if (consCnt >= n) {
						ans++;
						break;
					}
				}
			}
		}
	}

	printf("Case #%d: %d\n", caseNo, ans);
	//printf( "%2.1f\n", ans );
}


int main()
{
	//if (freopen("c:\\_temp\\A.in", "rt", stdin) == NULL) throw 1;
	//if (freopen("c:\\_temp\\A.out", "wt", stdout) == NULL) throw 2;

	if (freopen("c:\\_temp\\A-small-attempt1.in", "rt", stdin) == NULL) throw 1;
	if (freopen("c:\\_temp\\A-small-attempt1.out", "wt", stdout) == NULL) throw 2;

	//if (freopen("c:\\_temp\\A_test.in", "rt", stdin) == NULL) throw 1;
	//if (freopen("c:\\_temp\\A_test.out", "wt", stdout) == NULL) throw 2;

	//if (freopen("c:\\_temp\\A-large.in", "rt", stdin) == NULL) throw 1;
	//if (freopen("c:\\_temp\\A-large.out", "wt", stdout) == NULL) throw 2;

	int caseCount;
	scanf("%d%", &caseCount);
	clock_t totalNow = clock();

	forab(i, 1, caseCount) {
		clock_t now = clock();
		cerr << "case " << i << "...";

		Solve(i);
		fflush(stdout);

		cerr << "Done!; Elapsed ms:" << (double)(clock() - now) * 1000 / CLOCKS_PER_SEC << "\n";
	}
	cerr << "Total elapsed seconds:" << (double)(clock() - totalNow) / CLOCKS_PER_SEC << "\n";

	exit(0);
}
