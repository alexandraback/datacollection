#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>

using namespace std;

template<typename T> T mabs(const T &a){ return a<0 ? -a : a; }
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

ll gcd(ll a, ll b)
{
	while (a != 0)
	{
		b %= a;
		swap(a, b);
	}

	return b;
}

void test(int ti)
{
	printf("Case #%d: ", ti);

	ll p, q;
	scanf(" %lld / %lld", &p, &q);

	ll gc = gcd(p, q);
	p /= gc;
	q /= gc;

	ll tp = 1;
	int tpCnt = 0;
	bool has = 0;
	while (tp < 1e15)
	{
		if (tp == q)
		{
			has = 1;
			break;
		}
		tpCnt++;
		tp *= 2;
	}

	if (!has)
	{
		printf("impossible\n");
		return;
	}

	ll denom = 1;
	int gen = 0;
	rep(i, 0, 50)
	{
		ll mul = q / denom;
		if (mul <= p)
		{
			gen = i;
			break;
		}
		denom *= 2;
	}

	printf("%d\n", gen);
}

void run()
{
	int tc;
	scanf("%d", &tc);

	rep(i, 0, tc)
	{
		test(i + 1);
	}
}

//#define prob "fence"

int main()
{
#ifdef LOCAL_DEBUG
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	time_t st = clock();
#else 
#ifdef prob
	freopen(prob".in", "r", stdin);
	freopen(prob".out", "w", stdout);
#endif
#endif

	run();

#ifdef LOCAL_DEBUG
	fprintf(stderr, "\n=============\n");
	fprintf(stderr, "Time: %.2lf sec\n", (clock() - st) / double(CLOCKS_PER_SEC));
#endif

	return 0;
}