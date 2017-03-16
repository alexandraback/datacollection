#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <cassert>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
#include <iomanip>

#define SZ(x) (int((x).size()))
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i, a, b) for(int (i) = (a); (i) >= (b); --(i))
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define REPD(i, n) for (int (i) = (n); (i)--; )
#define FE(i, a) for (int (i) = 0; (i) < (int((a).size())); ++(i))
#define MEM(a, val) memset((a), val, sizeof(a))
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define PB push_back
#define PPB pop_back
#define ALL(c) (c).begin(), (c).end()
#define SQR(a) ((a)*(a))
#define MP(a,b) make_pair((a), (b))
#define XX first
#define YY second

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef double dbl;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<LL> vLL;

const int nmax = 100009;

dbl dp;
dbl cnt;

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	cout << fixed << setprecision(7);
	FOR(test, 1, T) {
		dbl C, F, X;
		cin >> C >> F >> X;
		cnt = 2.0;
		dp = 0.0;
		
		dbl ans = X / 2;
		while (1) {
			dp += C / cnt;
			cnt += F;
			if (dp + X / cnt < ans) {
				ans = dp + X / cnt;
			}
			else {
				break;
			}
		}
		cout << "Case #" << test << ": " << ans << endl;
	}
	return 0;
}

