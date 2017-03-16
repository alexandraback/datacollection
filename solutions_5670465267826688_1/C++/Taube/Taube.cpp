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

int n, m, j, i, h, l, k, q1, q2, t, q, ans, pos1, pos2, val, cur;
int matr[5][5] = {{}, {0, 1, 2, 3, 4}, {0, 2, -1, 4, -3}, {0, 3, -4, -1, 2}, {0, 4, 3, -2, -1}};
char buf[100500];
ll x;


int multi(int a, int b)
{
	int aa = abs(a), bb = abs(b);
	int res = matr[aa][bb];
	if (aa * bb != a * b)
	{
		res *= -1;
	}
	return res;
}

void solve()
{
	scanf ("%d", &t);
	for (h = 1; h <= t; h++)
	{
		scanf ("%d%lld\n%s", &l, &x, &buf);
		if (ll(l) * ll(x) < ll(l << 2))
		{
			n = l * x;
		}
		else
		{
			n = (l << 2);
		}
		pos1 = pos2 = -1;
		val = cur = 1;
		for (j = 0; j < l; j++)
		{
			switch (buf[j])
			{
			case 'i':
				q = 2;
				break;
			case 'j':
				q = 3;
				break;
			case 'k':
				q = 4;
				break;
			}
			val = multi(val, q);
		}
		for (j = 0, i = 0; j < n; j++, (i == l - 1) ? i = 0 : i++)
		{
			switch (buf[i])
			{
			case 'i':
				q = 2;
				break;
			case 'j':
				q = 3;
				break;
			case 'k':
				q = 4;
				break;
			}
			cur = multi(cur, q);
			if (cur == 2)
			{
				pos1 = j + 1;
				break;
			}
		}
		cur = 1;
		for (j = 0, i = l - 1; j < n; j++, (i) ? i-- : i = l - 1)
		{
			switch (buf[i])
			{
			case 'i':
				q = 2;
				break;
			case 'j':
				q = 3;
				break;
			case 'k':
				q = 4;
				break;
			}
			cur = multi(q, cur);
			if (cur == 4)
			{
				pos2 = j + 1;
				break;
			}
		}
		ans = 1;
		for (j = 0; j < (x & 3LL); j++)
		{
			ans = multi(ans, val);
		}
		if (pos1 > 0 && pos2 > 0 && multi(multi(2, 3), 4) == ans && pos1 + pos2 <= ll(l) * ll(x))
		{
			printf ("Case #%d: YES\n", h);
		}
		else
		{
			printf ("Case #%d: NO\n", h);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("C-large.in", "r", stdin); freopen("output.txt", "w", stdout);
	srand(333);
	solve();
	return 0;
}