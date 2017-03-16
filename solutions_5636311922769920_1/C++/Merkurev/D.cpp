#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;



void solve()
{
	int k, c, s;
	scanf("%d%d%d", &k, &c, &s);
/*
   k - initial length
   c - complexity (iteration)
   s - count of students
*/
	long long l = 0;
	int cnt = k;
	for (int i = 1; i < c; i++)
	{
		l *= k;
		if (cnt > 1)
		{
			l++;
			cnt--;
		}
	}
	if (cnt > s)
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	l -= s - cnt;
	l = max(l, 0LL);
	for (int i = 0; i < s; i++)
		printf("%lld ", l + i + 1);
	printf("\n");
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Case #%d: ", i);
		eprintf("Case #%d .. %d\n", i, n);
		solve();
	}


}

int main(int argc, char **)
{
	if (argc == 1)
		multitest();
	else
		solve();

	return 0;
}


