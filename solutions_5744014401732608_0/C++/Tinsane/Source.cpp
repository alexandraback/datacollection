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

const int B = 51;
int b;
int graph[B][B];
ll m;

void solve()
{
	scanf("%d%I64d", &b, &m);
	for (int i = 0; i < b; ++i)
		for (int j = 0; j < b; ++j)
			graph[i][j] = 0;
	if ((1LL << (b - 2)) < m)
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	printf("POSSIBLE\n");
	if (m == (1LL << (b - 2)))
	{
		--m;
		graph[0][b - 1] = 1;
	}
	for (int i = 0; i < b - 1; ++i)	
		for (int j = i + 1; j < b - 1; ++j)
			graph[i][j] = 1;
	for (int i = 1; i < b - 1; ++i)
		if (m & (1LL << (i - 1)))
			graph[i][b - 1] = 1;
	for (int i = 0; i < b; ++i, printf("\n"))
		for (int j = 0; j < b; ++j)
			printf("%d", graph[i][j]);
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

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}