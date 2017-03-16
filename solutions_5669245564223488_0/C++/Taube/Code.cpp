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

int m, t, y, l, g, q, q0, n, cnt, res, k, j, i, h, q1, q2;
char buf[110];
string s[101];
bool diff, b[26][4][101];
vector <int> v[4];

inline void solve()
{
	ll ans = 1LL;
	int e[101], cnt = 0;
	bool bb[101], bbb[101];
	memset(bb, 0, sizeof(bool) * (n + 1));
	memset(bbb, 0, sizeof(bool) * (n + 1));
	memset(e, 0, sizeof(int) * (n + 1));
	memset(b, 0, sizeof(b));
	for (i = 1; i <= n; i++)
	{
		diff = 0;
		for (h = 1; h < int(s[i].sz); h++)
		{
			if (s[i][h] != s[i][h - 1])
			{
				diff = 1;
				break;
			}
		}
		if (!diff)
		{
			b[s[i][0] - 'a'][0][i] = 1;
		}
		else
		{
			if (s[i][0] == s[i][int(s[i].sz) - 1])
			{
				printf ("Case #%d: %d\n", j, 0);
				return;
			}
			b[s[i][0] - 'a'][1][i] = 1;
			q1 = 0;
			while (q1 < int(s[i].sz - 1) && s[i][q1 + 1] == s[i][0])
			{
				q1++;
			}
			b[s[i][int(s[i].sz - 1)] - 'a'][2][i] = 1;
			q2 = int(s[i].sz - 1);
			while (q2 && s[i][q2 - 1] == s[i][q2])
			{
				q2--;
			}
			for (q = q1 + 1; q < q2; q++)
			{
				if (b[s[i][q] - 'a'][3][i] && s[i][q - 1] != s[i][q])
				{
					printf ("Case #%d: %d\n", j, 0);
					return;
				}
				b[s[i][q] - 'a'][3][i] = 1;
			}
		}
	}
	for (h = 0; h < 26; h++)
	{
		v[0].clear();
		v[1].clear();
		v[2].clear();
		v[3].clear();
		for (i = 1; i <= n; i++)
		{
			if (b[h][0][i])
			{
				v[0].pb(i);
			}
			if (b[h][1][i])
			{
				v[1].pb(i);
			}
			if (b[h][2][i])
			{
				v[2].pb(i);
			}
			if (b[h][3][i])
			{
				v[3].pb(i);
			}
		}
		if (!v[3].empty() && (!v[0].empty() || !v[1].empty() || !v[2].empty()))
		{
			ans = 0;
			printf ("Case #%d: %d\n", j, 0);
			return;
		}
		if (int(v[1].sz) > 1 || int(v[2].sz) > 1 || int(v[3].sz) > 1)
		{
			ans = 0;
			printf ("Case #%d: %d\n", j, 0);
			return;
		}
		if (!v[1].empty())
		{
			if (!v[2].empty())
			{
				if (!v[0].empty())
				{
					for (i = 1; i < int(v[0].sz); i++)
					{
						e[v[0][i - 1]] = v[0][i];
						ans *= ll(i + 1);
						ans %= mod;
					}
					e[v[2][0]] = v[0][0];
					e[v[0][int(v[0].sz) - 1]] = v[1][0];
				}
				else
				{
					e[v[2][0]] = v[1][0];
				}
			}
			else
			{
				if (!v[0].empty())
				{
					for (i = 1; i < int(v[0].sz); i++)
					{
						e[v[0][i - 1]] = v[0][i];
						ans *= ll(i + 1);
						ans %= mod;
					}
					e[v[0][int(v[0].sz) - 1]] = v[1][0];
				}
			}
		}
		else
		{
			if (!v[2].empty())
			{
				if (!v[0].empty())
				{
					for (i = 1; i < int(v[0].sz); i++)
					{
						e[v[0][i - 1]] = v[0][i];
						ans *= ll(i + 1);
						ans %= mod;
					}
					e[v[2][0]] = v[0][0];
				}
			}
			else
			{
				if (!v[0].empty())
				{
					for (i = 1; i < int(v[0].sz); i++)
					{
						e[v[0][i - 1]] = v[0][i];
						ans *= ll(i + 1);
						ans %= mod;
					}
				}
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (!bb[i])
		{
			q = i;
			cnt++;
			do
			{
				if (bb[q])
				{
					if (bbb[q])
					{
						cnt--;
						break;
					}
					else
					{
						printf ("Case #%d: %d\n", j, 0);
						return;
					}
				}
				bb[q] = 1;
				q = e[q];
			}
			while (q);
			for (h = 1; h <= n; h++)
			{
				if (bb[j])
				{
					bbb[j] = 1;
				}
			}
		}
	}
	for (i = 1; i <= cnt; i++)
	{
		ans *= ll(i);
		ans %= mod;
	}
	printf ("Case #%d: %lld\n", j, ans);
}

inline void init()
{
    scanf ("%d", &t);
	for (j = 1; j <= t; j++)
	{
		scanf ("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf ("%s", &buf);
			s[i] = buf;
		}
		solve();
	}
}

inline void answer()
{
    
}

int main()
{
    freopen ("B-small-attempt4.in","r",stdin); freopen ("output.txt","w",stdout);
    //freopen ("olympiad.in","r",stdin); freopen ("olympiad.out","w",stdout);
    init();
    answer();
    return 0;
}