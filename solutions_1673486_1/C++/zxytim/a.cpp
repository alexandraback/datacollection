#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define For(i, n) for (int i = 0; i < n; i ++)
#define Ford(i, n) for (int i = n - 1; i >= 0; i --)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

template<typename T> void checkmax(T &a, T b) { if (b > a) a = b; }
template<typename T> void checkmin(T &a, T b) { if (b < a) a = b; }

typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int N = 1000002;
double p[N], s[N];

void solve()
{
	int n, m;
	scanf("%d%d", &m, &n);
	s[0] = 1;
	for (int i = 1; i <= m; i ++)
		scanf("%lf", &p[i]), s[i] = p[i] * s[i - 1];
	
	double ans = 1 + n + 1;
	for (int i = 0; i <= m; i ++)
	{
		checkmin(ans, s[i] * (m - i + n - i + 1) + (1 - s[i]) * (m - i + n - i + 1 + n + 1));
	}
	printf("%.6lf\n", ans); 
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	for (int id = 1; id <= ncase; id ++)
	{
		printf("Case #%d: ", id);
		solve();
	}
	return 0;
}

