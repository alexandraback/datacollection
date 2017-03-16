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

int a[1010], b[1010];
int memo[1<<10][1<<10];
int func(int stars, int maska, int maskb, int n)
{
	if (maskb == (1<<n)-1) return 0;
	int& res = memo[maska][maskb];
	if (res > 0) return res;
	res = 100000000;
	rep(i, n) {
		if (!(maskb & (1<<i)) && stars >= b[i])
			res = min(res, 1+func(stars+2-!!(maska&(1<<i)), maska, maskb+(1<<i), n));
	}
	rep(i, n) {
		if (!(maska&(1<<i)) && stars>=a[i])
			res = min(res, 1+func(stars+1, maska+(1<<i), maskb, n));
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int T; scanf("%d",&T);
	REP(test, 1, T+1) {
		int n; scanf("%d", &n);
		rep(i, n) scanf("%d%d", a+i, b+i);

		memset(memo, 0, sizeof(memo));
		int res = func(0, 0, 0, n);
		if (res < 100000000)
			printf("Case #%d: %d\n", test, res);
		else
			printf("Case #%d: Too Bad\n", test);
	}

	return 0;
}
