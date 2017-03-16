#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <utility>
#include <ctime>
#include <memory.h>
#include <cctype>
#include <cstdlib>

using namespace std;

#pragma comment (linker, "/STACK:64000000")

#define y0 qwe
#define y1 asd
#define sz size()
#define pb push_back
#define fors(w,s) for(map <int, int> :: iterator w = s.begin(); w != s.end(); w++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ull unsigned long long
#define vi vector <int>
#define vvi vector <vi>
#define inf 2000000000
#define mod 1000000007
#define ll long long
#define maxint 2139062143 //2147483647
#define maxll 9223372036854775807
#define fi first
#define se second
#define eps 1e-9
#define doubleinf 1000000000000000.0

int m, t, y, l, g, q, q0, n, cnt, res, k, j, i, h;
ll st[60], q1, q2;

inline ll gcd(ll a, ll b)
{
	while (b)
	{
		a %= b;
		swap (a, b);
	}
	return a;
}

inline void solve()
{
	ll q = gcd(q1, q2);
	q1 /= q;
	q2 /= q;
	int num = 0, ans = 0;
	st[0] = 1LL;
	for (i = 1; st[i - 1] <= 1000000000000LL; i++)
	{
		st[i] = st[i - 1] << 1;
	}
	for (i = 1; st[i]; i++)
	{
		if (q2 == st[i])
		{
			num = i;
		}
	}
	if (!num)
	{
		printf ("Case #%d: impossible\n", j);
		return;
	}
	else
	{
		for(;;)
		{
			ans++;
			if ((q1 << 1) < q2)
			{
				q2 >>= 1;
			}
			else
			{
				printf ("Case #%d: %d\n", j, ans);
				break;
			}
		}
	}
}

inline void init()
{
    scanf ("%d", &t);
	for (j = 1; j <= t; j++)
	{
		scanf ("%lld/%lld\n", &q1, &q2);
		solve();
	}
}

inline void answer()
{
    
}

int main()
{
    freopen ("A-large.in","r",stdin); freopen ("output.txt","w",stdout);
    //freopen ("olympiad.in","r",stdin); freopen ("olympiad.out","w",stdout);
    init();
    answer();
    return 0;
}