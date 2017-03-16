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

	int tc;
	scanf("%d", &tc);

	rep(i, 0, tc)
		test(i+1);

#ifdef LOCAL_DEBUG

	fprintf(stderr, "\nTime used: %lf\n", (clock() - cl) / (double)CLOCKS_PER_SEC);

#endif

	return 0;
}

bool checkPalindrome(ll num)
{
	//char buf[20];

	//sprintf(buf, "%lld", num);

	//int len = strlen(buf);
	//bool bad = 0;
	//rep(i, 0, len/2)
	//{
	//	if (buf[i] != buf[len - i - 1])
	//	{
	//		bad = 1;
	//		break;
	//	}
	//}

	int buf[20];

	int len = 0;
	while (num > 0)
	{
		int cur = num % 10;
		buf[len++] = cur;
		num /= 10;
	}

	bool bad = 0;
	rep(i, 0, len/2)
	{
		if (buf[i] != buf[len - i - 1])
		{
			bad = 1;
			break;
		}
	}

	return !bad;
}

const int MMAX = 10000005;
//const int MMAX = 10005;

int dyn[MMAX];

void fillDyn()
{
	static bool wasHere = 0;
	if (wasHere)
		return;

	wasHere = 1;

	dyn[0] = 0;
	rep(i, 1, MMAX)
	{
		dyn[i] = dyn[i-1];
		ll mul = i * (ll)i;
		if (checkPalindrome(mul) && checkPalindrome(i))
		{
			dyn[i]++;
			fprintf(stderr, "%d %lld\n", i, mul);
		}
	}
}

void test(int testNum)
{
	printf("Case #%d: ", testNum);
	
	fillDyn();

	ll a, b;
	scanf("%lld%lld", &a, &b);

	ll lowBnd = sqrt((double)a);
	ll uppBnd = sqrt((double)b);

	while (lowBnd * lowBnd > a && lowBnd > 0)
		lowBnd--;
	while (lowBnd * lowBnd < a)
		lowBnd++;

	while (uppBnd * uppBnd < b)
		uppBnd++;
	while (uppBnd * uppBnd > b)
		uppBnd--;

	printf("%d\n", dyn[uppBnd] - dyn[lowBnd-1]);
}