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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


int rev(int x)
{
	int ans = 0;
	while (x)
	{
		ans *= 10;
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

const int maxn = (int) 1e7;
int d[maxn];
int qu[maxn];


void init()
{
	int l = 0, r = 0;
	d[1] = 1;
	qu[r++] = 1;
	while (r > l)
	{
		int cur = qu[l++];
		int a = cur + 1;
		if (a < maxn && d[a] == 0)
		{
			d[a] = d[cur] + 1;
			qu[r++] = a;
		}
		int b = rev(cur);
		if (b < maxn && d[b] == 0)
		{
			d[b] = d[cur] + 1;
			qu[r++] = b;
		}
	}
}
void solve()
{
	int x;
	scanf("%d", &x);
	printf("%d\n", d[x] );
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("answer.txt", "w", stdout);
#endif

	init();

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		printf("Case #%d: ", i + 1);
		solve();	
	}

	return 0;
}
