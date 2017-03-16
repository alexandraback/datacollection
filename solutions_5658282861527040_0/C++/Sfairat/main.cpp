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

ll ones(int cnt)
{
	ll res = 0;
	rep(i, 0, cnt)
		res |= 1LL << i;
	return res;
}

const int lib = 40;

ll getCnt(ll num, ll pref, int sufLen)
{
	if (num < pref)
		return 0;
	ll po = pref | ones(sufLen);
	return (num & po) - pref + 1;
	//ll on = ones(sufLen);
	//if (num > (pref | on))
	//	return (pref | on) - pref + 1;
	//return num - pref + 1;
}

ll getMaxCnt(int sufLen)
{
	return 1LL << sufLen;
}

ll getSpace(ll num, ll pref, int sufLen)
{
	ll res = 0;
	for (int i = lib; i >= sufLen; i--)
	{
		ll cb = 1LL << i;
		if (num & cb)
		{
			if ((pref & cb) == 0)
				res |= cb;
		}
	}
	return res;
}

ll makeCurB(ll b, int pos)
{
	ll cb = 1LL << pos;
	if (b & cb)
		return b;
	return (b - cb) | ones(pos + 1);
}

ll tt(ll a, ll b, ll k)
{
	ll sA = a, sB = b;
	ll res = (a + 1) * (b + 1);

	ll pref = 0;

	for (int pos = lib; pos >= 0; pos--)
	{
		ll cb = 1LL << pos;
		if ((k & cb) == 0)
		{
			pref ^= cb;
			a = makeCurB(sA, pos), b = makeCurB(sB, pos);
			if (a < 0 || b < 0)
			{
				pref ^= cb;
				continue;
			}
			ll cA = getCnt(a, pref, pos);
			ll cB = getCnt(b, pref, pos);

			ll spaceA = getSpace(a, pref, pos + 1);
			ll spaceB = getSpace(b, pref, pos + 1);

			ll spaceAnd = spaceA & spaceB;
			ll spaceOr = spaceA | spaceB;
			ll maxCnt = getMaxCnt(pos);

			{
				ll cMul = 1;

				for (int i = lib; i > pos; i--)
				{
					ll cb = 1LL << i;
					if (spaceAnd & cb)
						cMul *= 3;
					else if ((spaceA & cb) || (spaceB & cb))
						cMul *= 2;
				}

				res -= maxCnt * maxCnt * cMul;
			}

			{
				ll cMul = 1;

				for (int i = lib; i > pos; i--)
				{
					ll cb = 1LL << i;
					if (spaceA & cb)
						continue;
					if (spaceB & cb)
						cMul *= 2;
				}

				res += maxCnt * (maxCnt - cB) * cMul;
			}

			{
				ll cMul = 1;

				for (int i = lib; i > pos; i--)
				{
					ll cb = 1LL << i;
					if (spaceB & cb)
						continue;
					if (spaceA & cb)
						cMul *= 2;
				}

				res += maxCnt * (maxCnt - cA) * cMul;
			}

			if (spaceAnd == 0)
			{
				ll cMul = 1;

				ll maxCnt = getMaxCnt(pos);

				res -= (maxCnt - cA) * (maxCnt - cB);
			}

			pref ^= cb;
		}
		else
		{
			pref |= cb;
		}
	}
	return res;
}

ll stupid(ll a, ll b, ll k)
{
	ll res = 0;
	rep(i, 0, a+1)
		rep(j, 0, b + 1)
	{
			if ((i & j) <= k)
				res++;
	}
	return res;
}

void test(int testNum)
{
	printf("Case #%d: ", testNum);

	ll a, b, k;

	scanf("%lld%lld%lld", &a, &b, &k);
	k--;
	a--, b--;

	/*ll res = tt(a, b, k);*/
	ll res = stupid(a, b, k);

	printf("%lld\n", res);
}

void run()
{
	int TC;
	scanf("%d", &TC);
	rep(i, 0, TC)
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