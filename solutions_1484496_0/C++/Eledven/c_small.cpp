#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <iomanip>
#define nextLine() { for (int c = getchar(); c != '\n' && c != EOF; c = getchar()); }
#define sqr(a) ((a)*(a))
#define has(mask,i) (((mask) & (1<<(i))) == 0 ? false : true)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef long long LL;
typedef long double ldb;

const int INF = (1 << 30) - 1;
const ldb EPS = 1e-9;
const ldb PI = fabs(atan2(0.0, -1.0));

int n;
int a[25];

void load()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
}

int sum[(1 << 21) + 1];
void solve(int test)
{
	for (int i = 0; i < (1 << n); i++)
	{
		sum[i] = 0;
		for (int j = 0; j < n; j++)
			if (has(i, j)) sum[i] += a[j];
	}

	for (int mask1 = 1; mask1 < (1 << n); mask1++)
	{
		int diff = ((1 << n) - 1) ^ mask1;
		for (int mask2 = diff; mask2; mask2 = (mask2 - 1) & diff)
		{
			if (sum[mask1] == sum[mask2])
			{
				printf("Case #%d:\n", test);
				for (int i = 0; i < n; i++)
					if (has(mask1, i)) printf("%d ", a[i]);
				printf("\n");
				for (int i = 0; i < n; i++)
					if (has(mask2, i)) printf("%d ", a[i]);
				printf("\n");	
				return;
			}
		}
	}
	printf("Case #%d: Impossible\n", test);
}

int main()
{
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		load();
		solve(test);
	}	
	return 0;
}
