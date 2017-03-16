#include <functional>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstdio>
#include <complex>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

#define int64 long long
#define mp make_pair

const int inf = 1e9;

#ifdef _DEBUG
    const int N = 3010;
#else
    const int N = 300010;
#endif

int T;
int64 n, x;
multiset <int> st;
string s;

pair<char, int> get(char x, int s1, char y, int s2)
{
	int s = s1 * s2;
	pair<char, int> res;
	if (x == '1' && y == '1') return res = mp('1', s);
	else if (x == '1') res = mp(y, s);
	else if (y == '1') res = mp(x, s);
	else if (x == y) res = mp('1', -s);
	else 
	{
		if (x == 'i' && y == 'k')
		{
			swap(x, y);
			s *= -1;
		}
		else if (x == 'j' && y == 'i')
		{
			swap(x, y);
			s *= -1;
		}
		else if (x == 'k' && y == 'j')
		{
			swap(x, y);
			s *= -1;
		}
		if (x == 'i' && y == 'j') res = mp('k', s);
		else if (x == 'j' && y == 'k') res = mp('i', s);
		else res = mp('j', s);
	}
	return res;
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++)
	{
		cin >> n >> x;
		cin >> s;
		int64 ind1 = -1, ind2 = -1;
		pair <char, int> cur = mp('1', 1);
		for (int i = 0; i < min(x, 4ll); i++)
		{
			for (int j = 0; j < n; j++) 
			{
				cur = get(cur.first, cur.second, s[j], 1);
				if (cur == mp('i', 1))
				{
					ind1 = n * i + j + 1;
					break;
				}
			}
			if (cur == mp('i', 1)) break;
		}
		cur = mp('1', 1);
		for (int i = 0; i < min(x, 4ll); i++)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				cur = get(s[j], 1, cur.first, cur.second);
				if (cur == mp('k', 1))
				{
					ind2 = n * x - n * i - (n - j) - 1;
					break;
				}
			}
			if (cur == mp('k', 1)) break;
		}
		bool f = false;
		if (ind1 != -1 && ind2 != -1 && ind1 <= ind2)
		{
			cur = mp('1', 1);
			for (int j = ind1; j <= ind2; j++) cur = get(cur.first, cur.second, s[j % n], 1);
			cur = mp('1', 1);
			int64 n1 = ind1 / n, n2 = ind2 / n;
			if (n1 != n2)
			{
				for (int j = ind1 % n; j < n; j++) cur = get(cur.first, cur.second, s[j], 1);
				for (int k = 0; k < (n2 - n1 - 1) % 4; k++)
					for (int j = 0; j < n; j++)  cur = get(cur.first, cur.second, s[j], 1);
				for (int j = 0; j <= ind2 % n; j++)
					cur = get(cur.first, cur.second, s[j], 1);
			}
			else
			{
				for (int j = ind1 % n; j <= ind2 % n; j++) cur = get(cur.first, cur.second, s[j], 1);
			}
			if (cur == mp('j', 1)) f = true;
		}
		if (f) printf("Case #%d: YES\n", ii);
		else printf("Case #%d: NO\n", ii);
	}
	return 0;
}