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


void test(int testNum)
{
	printf("Case #%d: \n", testNum);
	int r, n, m, k;

	scanf("%d%d%d%d", &r, &n, &m, &k);

	rep(i, 0, r)
	{
		int arr[25];

		rep(i, 0, k)
			scanf("%d", arr + i);

		int r1 = 1, r2 = 2, r3 = 2;
		rep(t1, 2, m+1)
		{
			rep(t2, 2, m+1)
			{
				rep(t3, 2, m+1)
				{
					int prods[8];
					prods[0] = 1;
					prods[1] = t1;
					prods[2] = t2;
					prods[3] = t3;
					prods[4] = t1 * t2;
					prods[5] = t1 * t3;
					prods[6] = t2 * t3;
					prods[7] = t1 * t2 * t3;
					
					bool good = 1;
					rep(t, 0, k)
					{
						bool can = 0;
						rep(i, 0, 8)
						{
							if (prods[i] == arr[t])
							{
								can = 1;
								break;
							}
						}
						if (!can)
						{
							good = 0;
							break;
						}
					}
					if (good)
					{
						r1 = t1;
						r2 = t2;
						r3 = t3;
						break;
					}
				}
				if (r1 != 1)
					break;
			}
			if (r1 != 1)
				break;
		}

		if (r1 == 1)
			r1 = 2;
		printf("%d%d%d\n", r1, r2, r3);
	}
}