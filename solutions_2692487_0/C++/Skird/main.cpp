#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#define mp make_pair

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using namespace std;

typedef long long ll;
typedef double lf;

void initrand()
{
	ll seed;
	asm("rdtsc":"=A"(seed));
	srand(seed);
}

const int maxn = 110;

int x, n, data[maxn];

inline int solve()
{
	scanf("%d%d", &x, &n);
	for (int i = 0; i < n; i++) scanf("%d", &data[i]);
	sort(data, data + n);
	int ans = n;
	if (x == 1) return n;
	for (int k = 0; k <= n; k++)
	{
		int cursz = x, curans = k;
		for (int j = 0; j < n - k; j++)
		{
			while (cursz <= data[j]) cursz += cursz - 1, curans++;
			cursz += data[j];
		}
		ans = min(ans, curans);
	}
	return ans;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) printf("Case #%d: %d\n", i + 1, solve());
	return 0;
}

