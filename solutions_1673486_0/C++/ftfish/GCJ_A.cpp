#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define debuging

#ifdef debuging
#define FIN  {freopen("new.in" , "r" , stdin) ;}
#define FOUT {freopen("new.out" , "w" , stdout) ;}
#define OUT(x)  {cout<< #x << "  : " << x <<endl ;}
#define ERR(x)  {cout<<"#error: "<< x ; while(1) ;}
#endif

#ifndef debuging
#define FIN  ;
#define FOUT ;
#define OUT(x)  ;
#define ERR(x)  ;
#endif

#define rep(i,a,b) for(int i=(a);i<(int)(b);i++)
#define REP(i,n) rep(i,0,(n))
#define SZ(x) (int)((x).size())
#define CLR(a) memset((a),0,sizeof (a))
#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define contains(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vint;
typedef set<int> sint;
typedef pair<int, int> pint;

const int maxint = -1u >> 2;
const double eps = 1e-8;
const double pi = acos(-1.0);

const int mn = 100005;
double a[mn], p[mn] = { 1 };

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int Tn;
	scanf("%d", &Tn);
	for (int Tc = 1; Tc <= Tn; ++Tc) {
		double ans = 0;
		int n, m;

		scanf("%d%d", &m, &n);
		int rest = n - m;
		for (int i = 1; i <= m; ++i) {
			scanf("%lf", a + i);
			p[i] = p[i - 1] * a[i];
		}

		ans = n + 2;
		for (int k = 0; k <= m; ++k) {
			double t = p[m - k] * (rest + 2 * k + 1)
					+ (1 - p[m - k]) * (rest + 2 * k + 2 + n);
//			printf("k = %d, e = %.8f\n", k, t);
			if (t < ans)
				ans = t;
		}

		printf("Case #%d: ", Tc);
		// output statement(s);
		printf("%.8f\n", ans);
	}

	return 0;
}
