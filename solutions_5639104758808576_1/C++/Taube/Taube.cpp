#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <complex>

using namespace std;

#define pb push_back
#define pii pair<int, int>
#define pdi pair<double, int>
#define pdii pair<pdi, int>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define psi pair<string, int>
#define vi vector<int>
#define inf 2000000000
#define mod 1000000007
#define y1 uhgeg
#define lim 31700
#define eps 1e-9
#define prime 3001

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> comp;

int n, m, j, i, h, l, k, q1, q2, t, q, a[200001], par[201], best;
ll cur, delta, ans;
char buf[100500];

void solve()
{
	scanf ("%d", &t);
	for (h = 1; h <= t; h++)
	{
		scanf ("%d\n%s\n", &n, &buf);
		cur = delta = ans = 0;
		for (j = 0; j <= n; j++)
		{
			delta = max(0LL, j - cur);
			ans += delta;
			cur += delta;
			cur += (buf[j] - '0');
		}
		printf ("Case #%d: %lld\n", h, ans);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	srand(333);
	solve();
	return 0;
}