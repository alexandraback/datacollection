#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<numeric>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<cmath>
#include<bitset>
#include<cassert>
#include<queue>
#include<stack>
#include<deque>
#include<cassert>
using namespace std;
typedef long long ll;
typedef long double ld;
char a[107], b[107];
bool check(char a, int b)
{
	return (a == b + '0') || (a == '?');
}
bool check(char x[], int a, int len)
{
	for (int i = len - 1; i >= 0; i--)
	{
		if (!check(x[i], a % 10)) return false;
		a /= 10;
	}
	return a == 0;
}
void go(char* x, int a, int len)
{
	for (int i = len - 1; i >= 0; i--)
	{
		x[i] = a % 10 + '0';
		a /= 10;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%s %s\n", a, b);
		int n = strlen(a);
		int state = 0; // 0 - eq, 1 - a, -1 - b
		/*for (int i = 0; i < n; i++)
		{
			if (a[i] == '?' && b[i] == '?')
			{
				if (state == 0)
				{
					a[i] = '0';
					b[i] = '0';
				}
				else if (state == 1)
				{
					a[i] = '0';
					b[i] = '9';
				}
				else if (state == -1)
				{
					a[i] = '9';
					b[i] = '0';
				}
			}
			else if (a[i] == '?')
			{
				if (state == 0)
				{
					a[i] = b[i];
				}
				else if (state == 1)
				{
					a[i] = '0';
				}
				else if (state == -1)
				{
					a[i] = '9';
				}
			}
			else if (b[i] == '?')
			{
				if (state == 0)
				{
					b[i] = a[i];
				}
				else if (state == 1)
				{
					b[i] = '9';
				}
				else if (state == -1)
				{
					b[i] = '0';
				}
			}
			else
			{
				if (state == 0)
				{
					if (a[i] > b[i])
					{
						state = 1;
					}
					else if (a[i] < b[i])
					{
						state = -1;
					}
				}
			}
		} */
		int ans = (int)1e9 + 7, ansx = -1, ansy = -1;
		for (int aa = 0; aa <= 999; aa++)
		{
			for (int bb = 0; bb <= 999; bb++)
			{
				if (check(a, aa, n) && check(b, bb, n))
				{
					int diff = abs(aa - bb);
					if (diff < ans || (diff == ans && make_pair(aa, bb) < make_pair(ansx, ansy)))
					{
						ans = diff;
						ansx = aa;
						ansy = bb;
					}
				}
			}
		}
		go(a, ansx, n);
		go(b, ansy, n);
		printf("Case #%d: %s %s\n", tt, a, b);
	}
}
