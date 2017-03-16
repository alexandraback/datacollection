#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string.h>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

#define mp make_pair
#define pb push_back
#define problem "test"
typedef __int128 ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
const int z = 11111;
const double eps = 1e-9;
const int inf = int(1e9);
const ll llinf = ll(1e18);
using namespace std;

int s[z], best, ans[2];
string a, b;
inline bool match(int sz)
{
	for (int i = 0; i < sz; i++)
	{
		if (a[i] == '?')
			continue;
		if (a[i] - '0' != s[i])
			return 0;
	}
	for (int i = 0; i < sz; i++)
	{
		if (b[i] == '?')
			continue;
		if (b[i] - '0' != s[i + sz])
			return 0;
	}
	return 1;

}
inline void check()
{
	if (!match(a.size()))
		return;
//	cout << s[0] << s[1] << s[2] << " " << s[3] << s[4] << s[5] << "\t";
	int x, y;
	if (a.size() == 3) x = s[0] * 100 + s[1] * 10 + s[2], y = s[3] * 100 + s[4] * 10 + s[5];
	else if (a.size() == 2) x = s[0] * 10 + s[1], y = s[2] * 10 + s[3];
	else x = s[0], y = s[1];
//	cout << abs(y - x) << "\t" << best << "\n";
	if (abs(y - x) < best)
	{
//		cout << "UPD\n";
		best = abs(y - x);
		ans[0] = x, ans[1] = y;
	}
	else
	{
		if (abs(y - x) == best)
		{
			if (ans[0] > x)
			{
				x = ans[0], y = ans[1];
			}
			else
			{
				if (ans[0] == x)
				{
					if (ans[1] > y)
						y = ans[1];
				}
			}
		}
	}

}
void gen(int k)
{
	if (k == 2 * a.size())
	{
		check();
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		s[k] = i;
		gen(k + 1);
		s[k] = 0;
	}
}
inline void format(string x, int y)
{
	if (x.size() == 3 && y < 10)
	{
		cout << "00" << y;
		return;
	}
	if (x.size() == 3 && y < 100)
	{
		cout << "0" << y;
		return;
	}
	if (x.size() == 2 && y < 10)
	{
		cout << "0" << y;
		return;
	}
	cout << y;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen(problem".in", "r", stdin);
	freopen(problem".out", "w", stdout);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++)
	{
		cin >> a >> b;
		best = ans[0] = ans[1] = inf;
	   	gen(0);
	   	cout << "Case #" << test << ": ";
	   	format(a, ans[0]);
	   	cout << " ";
	   	format(b, ans[1]);
	   	cout << "\n";
		
	}	
	
	return 0;
}