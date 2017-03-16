#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <string>
#include <ctime>

using namespace std;

#define rep(x, y, z) for(int x = (y), end##x = (z); x < end##x; x++)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL_DEBUG

#define DebugPrint(...) fprintf(stderr, __VA_ARGS__);

#else

#define DebugPrint(...)

#endif

typedef long long ll;
typedef pair<int, int> pii;

void test(int testNum);
void init();

int main()
{
	//
#ifdef LOCAL_DEBUG

	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

#else

	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);

#endif

	clock_t cl = clock();

	init();

	int tc;
	scanf("%d", &tc);

	rep(i, 0, tc)
		test(i+1);

#ifdef LOCAL_DEBUG

	fprintf(stderr, "\nTime used: %lf\n", (clock() - cl) / (double)CLOCKS_PER_SEC);

#endif

	return 0;
}

void init()
{

}

ll getVal(ll n, ll r)
{
	ll v1 = 2 * n * n;
	ll v2 = n * (2*r - 1);
	return v1 + v2;
}

void test(int testNum)
{
	printf("Case #%d: ", testNum);
	
	ll r, t;
	scanf("%lld%lld", &r, &t);
	double a = 2;
	double b = 2 * r - 1;
	double c = -t;
	double D = b*b - 4 * a * c;
	double res = (-b + sqrt(D)) / 2 / a;
	DebugPrint("%lf\n", res);

	ll n = res;
	while (getVal(n, r) <= t)
		n++;
	while (getVal(n, r) > t)
		n--;

	printf("%lld\n", n);
}