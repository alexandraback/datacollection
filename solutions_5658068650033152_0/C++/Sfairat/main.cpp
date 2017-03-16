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

int ar(int start, int cnt)
{
	if (cnt <= 0)
		return 0;
	int res = (start + (cnt - 1)) * cnt;
	return res;
}

int board[22][22];
bool was[22][22];
bool gray[22][22];
bool cp[22][22];

int W, H;

bool canPlace(int a, int b)
{
	if (board[a][b])
		return true;
	if (was[a][b])
	{
		if (gray[a][b])
			return true;
		return cp[a][b];
	}
	was[a][b] = 1;
	gray[a][b] = 1;
	if (a == 0 || b == 0 || a == W - 1 || b == H - 1)
	{
		return board[a][b];
	}

	bool &res = cp[a][b];

	res &= canPlace(a - 1, b);
	res &= canPlace(a + 1, b);
	res &= canPlace(a, b + 1);
	res &= canPlace(a, b - 1);
	gray[a][b] = 0;
	return res;
}

int stupid(int n, int m, int k)
{
	int nm = n * m;

	int max2 = 1 << nm;
	int bestStones = k;
	W = n;
	H = m;
	rep(tp, 0, nm)
	{
		int curStones = 0;
		rep(i, 0, n)
		{
			rep(j, 0, m)
			{
				int cb = i * m + j;
				if ((tp >> cb) & 1)
				{
					board[i][j] = 1;
					curStones++;
				}
				else
					board[i][j] = 0;
				was[i][j] = 0;
				cp[i][j] = 0;
				gray[i][j] = 0;
			}
		}
		
		int canPick = 0;
		rep(i, 0, n)
		{
			rep(j, 0, m)
			{
				if (canPlace(i, j))
					canPick++;
			}
		}
		if (canPick >= k)
			bestStones = min(bestStones, curStones);
	}
	return bestStones;
}

void test(int ti)
{
	printf("Case #%d: ", ti);

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	//n++, m++;
	int minStones = stupid(n, m, k);
	printf("%d\n", minStones);
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