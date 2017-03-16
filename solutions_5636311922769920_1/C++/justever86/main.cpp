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
#include <algorithm>
#include <cstring>

using namespace std;

#define LOCAL_TEST 0

#define rep(i,a,b) for(int i = a;i < b;i++)
#define REP(i,n) rep(i,0,n)
#define per(i,a,b) for(int i = b - 1;i >= a;i--)
#define PER(i,n) per(i,0,n)
#define CLR(v) memset(v,0,sizeof(v))

int f(string s)
{
	int n = s.length();

	int res = 0;
	int x = n - 1;
	while (x >= 0)
	{
		if (s[x] == '+')
		{
			x--;
		}
		else
		{
			if (s[0] == '+')
			{
				int y = 0;
				while (s[y] == '+')
				{
					s[y] = '-';
					y++;
				}
				res++;
			}
			for (int i = 0; i <= x / 2; i++)
			{
				char c = s[i];
				s[i] = s[x - i];
				s[x - i] = c;
			}
			for (int i = 0; i <= x; i++)
			{
				if (s[i] == '+')
				{
					s[i] = '-';
				}
				else
				{
					s[i] = '+';
				}
			}
			res++;
		}
	}

	return res;
}

int g(string s)
{
	int n = s.length();
	int res = 0;
	REP(i, n)
	{
		if (i == 0 || s[i] != s[i - 1])
		{
			res++;
		}
	}
	if (s[n - 1] == '+')
	{
		res--;
	}
	return res;
}

int main()
{
#if !LOCAL_TEST
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	rep(CASE, 1, T + 1)
	{
		int k, c, s;
		scanf("%d %d %d", &k, &c, &s);
		
		if (c * s < k)
		{
			printf("Case #%d: ", CASE);
			puts("IMPOSSIBLE");
		}
		else
		{
			vector<long long> v;
			for (int i = 0; i < k;)
			{
				long long temp = 0;
				for (int j = 0; j < c && i < k; j++, i++)
				{
					temp *= k;
					temp += i;
				}
				v.push_back(temp + 1);
			}

			printf("Case #%d:", CASE);
			for (int i = 0; i < v.size(); i++)
			{
				printf(" %I64d", v[i]);
			}
			printf("\n");
		}

	}
}