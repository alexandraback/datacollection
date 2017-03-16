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
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <vb> vvb;

const int INF = (1 << 30) - 1;
const ldb EPS = 1e-9;
const ldb PI = fabs(atan2(0.0, -1.0));

int A, n;
int motes[111];
void load()
{
	scanf("%d%d", &A, &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &motes[i]);
}

void solve(int test)
{
	sort(motes + 0, motes + n);
	if (A == 1)
	{
		printf("Case #%d: %d\n", test, n);
		return;
	}
	int result = INF;
	for (int toDelete = 0; toDelete <= n; toDelete++)
	{
		LL x = A;
		int current = toDelete;
		for (int i = 0; i < n - toDelete; i++)
		{
			while (x <= motes[i])
			{
				x += x - 1;
				current++;
			}
			x += motes[i];	
		}
		result = min(result, current);
	}
	printf("Case #%d: %d\n", test, result);
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
