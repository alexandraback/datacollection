#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define in_str(b) scanf("%s",(b))
#define in_int1(a) scanf("%d",&(a))
#define in_int2(a,b) scanf("%d%d",&(a),&(b))
#define in_int3(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
#define in_int4(a,b,c,d) scanf("%d%d%d%d",&(a),&(b),&(c),&(d))
#define so(a) sort((a).begin(), (a).end())
#define rso(a) sort((a).rbegin(), (a).rend())
#define mp(a,b) make_pair(a,b)
#define mset(a,n) memset(a,n,sizeof(a))
#define readints(mas,n) for (int _i=0;_i<(n);_i++) in_int1((mas)[_i])
#define readdoubles(mas,n) for (int _i=0;_i<(n);_i++) scanf("%lf", &(mas)[_i])
#define unq(src) src.erase(unique((src).begin(), (src).end()), (src).end())
#define MOD 1000000007
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

char mas[2][20];
char ans[2][20];
char bestans[2][20];
ll best, minc, minj;

void go(int i, bool first_bigger)
{
	for (; mas[0][i]; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (mas[j][i] != '?') ans[j][i] = mas[j][i];
			else if (j == 0)
			{
				if (first_bigger) ans[j][i] = '0';
				else ans[j][i] = '9';
			}
			else
			{
				if (first_bigger) ans[j][i] = '9';
				else ans[j][i] = '0';
			}
		}
	}

	ll c, j;
	sscanf(ans[0], "%lld", &c);
	sscanf(ans[1], "%lld", &j);

	ll diff = llabs(c - j);
	if (best == -1 || best > diff || (best == diff && (c < minc || (c == minc && j < minj))))
	{
		best = diff;
		minc = c;
		minj = j;
		strcpy(bestans[0], ans[0]);
		strcpy(bestans[1], ans[1]);
	}
}

void Solve()
{
	int i, j, k, m, n;

	int tests;
	in_int1(tests);
	for (int test = 1; test <= tests; test++)
	{
		in_str(mas[0]);
		in_str(mas[1]);
		mset(ans, 0);
		for (i = 0; mas[0][i]; i++)
		{
			if (mas[0][i] == '?')
			{
				if (mas[1][i] == '?')
				{
					ans[0][i] = ans[1][i] = '0';
				}
				else
				{
					ans[0][i] = ans[1][i] = mas[1][i];
				}
			}
			else if (mas[1][i] == '?') ans[0][i] = ans[1][i] = mas[0][i];
			else if (mas[0][i] == mas[1][i]) ans[0][i] = ans[1][i] = mas[0][i];
			else
			{
				ans[0][i] = mas[0][i];
				ans[1][i] = mas[1][i];
				break;
			}
		}

		best = -1;
		if (mas[0][i])
		{
			bool first_bigger = mas[0][i] > mas[1][i];
			go(i + 1, first_bigger);
			for (--i; i >= 0; i--)
			{
				if (first_bigger)
				{
					// reduce first
					if (mas[0][i] == '?' && mas[1][i] != '0')
					{
						if (mas[1][i] == '?')
						{
							ans[0][i] = '0';
							ans[1][i] = '1';
							go(i + 1, false);
						}
						else
						{
							ans[0][i] = mas[1][i]-1;
							ans[1][i] = mas[1][i];
							go(i + 1, false);
						}
					}
					else if (mas[1][i] == '?' && mas[0][i] != '9')
					{
						ans[0][i] = mas[0][i];
						ans[1][i] = mas[0][i] + 1;
						go(i + 1, false);
					}
				}
				else
				{
					// reduce second
					if (mas[1][i] == '?' && mas[0][i] != '0')
					{
						if (mas[0][i] == '?')
						{
							ans[1][i] = '0';
							ans[0][i] = '1';
							go(i + 1, true);
						}
						else
						{
							ans[1][i] = mas[0][i] - 1;
							ans[0][i] = mas[0][i];
							go(i + 1, true);
						}
					}
					else if (mas[0][i] == '?' && mas[1][i] != '9')
					{
						ans[1][i] = mas[1][i];
						ans[0][i] = mas[1][i] + 1;
						go(i + 1, true);
					}
				}
			}
		}
		else go(i, true);

		printf("Case #%d: %s %s", test, bestans[0], bestans[1]);
		printf("\n");
	}
}

int main()
{
#ifdef __LOCAL_RUN__
	FILE *res_output = freopen("output.txt", "wt", stdout);
	FILE *res_input = freopen("input.txt", "rt", stdin);
	Solve();
#else
	Solve();
#endif
	return 0;
}