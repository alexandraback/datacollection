#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#include <unordered_map>
#include <unordered_set>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

int f, s, t;
int k;

void solve()
{
	scanf("%d%d%d%d", &f, &s, &t, &k);
	if (k >= s)
	{
		k = min(k, t);
		printf("%d\n", f * s * k);
		for (int i = 0; i < f; ++i)
			for (int j = 0; j < s; ++j)
				for (int q = 0; q < k; ++q)
					printf("%d %d %d\n", i + 1, j + 1, q + 1);
		return;
	}
	printf("%d\n", f * s * k);
	for (int i = 0; i < f; ++i)
		for (int j = 0; j < s; ++j)
			for (int q = 0; q < k; ++q)
				printf("%d %d %d\n", i + 1, j + 1, (j + q + i) % t + 1);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("chocolate.in", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}