#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:134217728")
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <sstream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <utility>
#include <ctime>
#include <string>

using namespace std;

typedef long long ll;

#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))
#define mp make_pair
#define mt(a, b, c) mp(a, mp(b, c))

bool under_templ(int a, const string& s)
{
	int u = s.size();
	for (int i = 0; i < u; i++)
	{
		if (s[u - i - 1] != '?' && s[u - i - 1] - '0' != a % 10)
			return 0;
		a /= 10;
	}
	return 1;
}

pair<int, int> ans;
string s1, s2;

void relaxAns(int a, int b)
{
	if (!under_templ(a, s1) || !under_templ(b, s2)) return;
	if (abs(a - b) < abs(ans.first - ans.second))
	{
		ans = mp(a, b);
		return;
	}
	if (abs(a - b) > abs(ans.first - ans.second)) return;
	if (a < ans.first)
	{
		ans = mp(a, b);
		return;
	}
	if (a > ans.first) return;
	if (b < ans.second)
	{
		ans = mp(a, b);
		return;
	}
}

int main()
{
#ifdef XXX
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int te;
	cin >> te;
	for (int w = 0; w < te; w++)
	{
		cin >> s1 >> s2;

		ans.first = -1e9;
		ans.second = 1e9;

		if (s1.size() == 1)
		{
			for (int a = 0; a < 10; a++)
				for (int b = 0; b < 10; b++)
					relaxAns(a, b);
		}
		if (s1.size() == 2)
		{
			for (int a = 0; a < 100; a++)
				for (int b = 0; b < 100; b++)
					relaxAns(a, b);
		}
		if (s1.size() == 3)
		{
			for (int a = 0; a < 1000; a++)
				for (int b = 0; b < 1000; b++)
					relaxAns(a, b);
		}

		printf("Case #%d: ", w + 1);
		if (s1.size() == 1)
		{
			printf("%d %d\n", ans.first, ans.second);
		}
		if (s1.size() == 2)
		{
			printf("%02d %02d\n", ans.first, ans.second);
		}
		if (s1.size() == 3)
		{
			printf("%03d %03d\n", ans.first, ans.second);
		}

	}

	return 0;
}