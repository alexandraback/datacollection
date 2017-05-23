#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"/STACK:64000000")
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>
#include <memory.h>
#include <limits.h>
#include <queue>

using namespace std;

void prepare(string s)
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	if (s.size() != 0)
	{
		freopen((s + ".in").c_str(), "r", stdin);
		freopen((s + ".out").c_str(), "w", stdout);
	}
#endif
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
}

long double c, f, x;

long double fun(int n)
{
	long double k = 2.0;
	long double sec = 0;
	for (size_t i = 0; i < n; i++)
	{
		sec += c / k;
		k += f;
	}
	sec += x / k;
	return sec;
}

int main()
{
	prepare("");
	int t;
	cin >> t;
	for (size_t test = 1; test <= t; test++)
	{
		cout << "Case #" << test << ": ";
		cin >> c >> f >> x; // строим дом, дает дом, сколько нужно печенек

		int l = 0, r = 1000000, EPS = 3;
		while (r - l > EPS)
		{
			int m1 = l + (r - l) / 3,
				m2 = r - (r - l) / 3;
			if (fun(m1) > fun(m2))
			{
				l = m1;
			}
			else
				r = m2;
		}

		int left = l - 1;
		if (left < 0)
		{
			left = 0;
		}

		int right = r + 1;
		
		long double MIN = 1000000;
		for (size_t i = left; i <= right; i++)
		{
			MIN = min(MIN, fun(i));
		}
		cout << fixed << setprecision(7) << MIN << endl;
	}
	return 0;
}
