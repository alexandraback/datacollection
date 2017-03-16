#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>

#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define rtr(c, i) for (typeof((c).rbegin()) i = (c).rbegin(); i != (c).rend(); --i)
#define contains(c, x) ((c).find(x) != (c).end())
#define Contains(c, x) (find(all(c), x) != (c).end())
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) REP(i, 0, (n))
#define To_String to_string< char,std::char_traits<char>,std::allocator<char> >

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

double p[100010];
int main()
{
	ios_base::sync_with_stdio(0);
	int T; scanf("%d", &T);
	for (int test=1; test<=T; ++test) {
		int a, b;
		scanf("%d%d", &a, &b);
		rep(i, a) scanf("%lf", p+i);
		double res = b+2; // press enter right away
		double x = 1;
		rep(i, a) x *= p[i];
		double y = 1;
		res = min(res, (b-a+1)*x + (b-a+1+b+1)*(1-x)); // keep typing
		res = min(res, (a+b+1.0)); // type backspace A times
		// press backspace 1..A-1 tiems
		REP(i, 1, a+1) {
			x /= p[a-i];
			double t = (i+b-(a-i)+1)*x + (i+b-(a-i)+1+b+1)*(1-x);
			res = min(res, t);
		}
		printf("Case #%d: %.8f\n", test, res);
	}
	return 0;
}
