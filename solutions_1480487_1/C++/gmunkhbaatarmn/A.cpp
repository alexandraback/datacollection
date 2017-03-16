// created on: 2012-05-06
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>

using namespace std;

// For vim: auto break case char const continue default do double else enum extern float for goto if int long register return short signed sizeof static struct switch typedef union unsigned void volatile while

#define ALL(c) c.begin(), c.end()
#define SZ(a) (int)(a).size()
#define FOR(i,a,b) for (int i=(a); i<=(int)(b); ++i)
#define FOREACH(X,C) for(typeof(C.begin()) X=C.begin();X!=C.end();++X)
#define PB push_back
#define SS stringstream
#define EPS (1e-9)
#define INF (1<<30)
#define SQR(x) ((x)*(x))
#define ABS(x) ((x<0)?(-(x)):(x))
#define EQUAL(a,b) (ABS((a)-(b))<eps)
#define px first
#define py second

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FORX(i,a,b,x) for (int i=(a); i<=(int)(b); i+=x)
#define FORD(i,a,b) for (int i=a; i>=b; --i)

#define REV(c) reverse(c.begin(), c.end())
#define SORT(c) sort(c.begin(), c.end())

typedef vector<int> VI; typedef vector<VI> VVI;
typedef vector<string> VS; typedef vector<VS> VVS;
typedef vector<long long> VLL;
typedef signed long long LL; typedef unsigned long long ULL;
typedef pair<int,int> PII;

typedef map<int,int> MII;
typedef map<char,int> MCI;
typedef map<string,int> MSI;

LL tonum(string s){ stringstream in(s); LL x; in>>x; return x; }
string tostr(LL n){ stringstream in; in << n; string x; in>>x; return x; }
LL gcd(LL a, LL b) { return __gcd(a, b); }

/* end of pre-code */

int main() {
	freopen ("input.txt", "rb", stdin);
	freopen ("output.txt", "w", stdout);

	int T; cin >> T;
	int t_case = 0;
	VI nn(300);

	while (T--) {
		int N; cin >> N;
		REP(i, N) cin >> nn[i];

		double sum = 0, optimal;
		REP(i, N) sum += nn[i];

		int mn = 0, mx = 0;
		int cnt = N;
		while (1) {
			cnt = 0;
			double sub = 0.0;
			mn = 290; nn[mn] = 99999;
			mx = 291; nn[mx] = -1;

			REP(i, N) {
				if (nn[i] < 0) continue;
				/* printf("nn[i] = %d\n", nn[i]); */

				if (nn[mn] >= nn[i]) mn = i;
				if (nn[mx] <= nn[i]) mx = i;
				sub += nn[i];
				cnt++;
			}

			optimal = (sum + sub) / double(cnt);
			/* printf("sum = %lf, cnt = %d, optimal = %lf, mx = %d\n", sum, cnt, optimal, mx); */

			if (optimal >= nn[mx]) {
				break;
			}
			nn[mx] = -1;
		}
		/* printf("cnt = %d, sum = %lf, optimal = %lf\n", cnt, sum, optimal); */

		printf("Case #%d:", ++t_case);
		REP(i, N) {
			double ret = 0;
			if (nn[i] < 0) {
				ret = 0.0;
			} else {
				ret = 100.0 * double(optimal - nn[i]) / double(sum);
			}
			printf(" %.6lf", ret);
		}
		printf("\n");
	}

	return 0;
}
