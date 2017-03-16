#pragma	comment(linker, "/STACK:100000000")
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

typedef long long ll;
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-9

string a, b;

int mycmp(ll x, ll y)
{
	if(x < y)
		return -1;
	if(x == y)
		return 0;
	return 1;
}

pair <ll, ll> solve(ll x, ll y, int pos, int cmp)
{
	if(pos == a.size())
		return make_pair(x, y);
	if(cmp == 1)
	{
		if(a[pos] == '?')
			x = x * 10 + 0;
		else
			x = x * 10 + a[pos] - '0';
		if(b[pos] == '?')
			y = y * 10 + 9;
		else
			y = y * 10 + b[pos] - '0';
		return solve(x, y, pos + 1, cmp);
	}
	if(cmp == -1)
	{
		if(a[pos] == '?')
			x = x * 10 + 9;
		else
			x = x * 10 + a[pos] - '0';
		if(b[pos] == '?')
			y = y * 10 + 0;
		else
			y = y * 10 + b[pos] - '0';
		return solve(x, y, pos + 1, cmp);
	}
	if(cmp == 0)
	{
		if(a[pos] != '?' && b[pos] != '?')
		{
			x = x * 10 + a[pos] - '0';
			y = y * 10 + b[pos] - '0';
			return solve(x, y, pos + 1, mycmp(x, y));
		}
		if(a[pos] == '?' && b[pos] != '?')
		{
			int d = b[pos] - '0';
			pair <ll, ll> res = make_pair(-1LL, -1LL);
			for(int i = -1; i <= 1; i++)
			{
				if(0 <= d + i && d + i <= 9)
				{
					pair <ll, ll> tmp = solve(x * 10 + d + i, y * 10 + d, pos + 1, i);
					if(res.first == -1 || 
						abs(tmp.first - tmp.second) < abs(res.first - res.second) ||
						(abs(tmp.first - tmp.second) == abs(res.first - res.second) && tmp.first < res.first) ||
						(abs(tmp.first - tmp.second) == abs(res.first - res.second) && tmp.first == res.first && tmp.second < res.second))
						res = tmp;
				}
			}
			return res;
		}
		if(a[pos] != '?' && b[pos] == '?')
		{
			int d = a[pos] - '0';
			pair <ll, ll> res = make_pair(-1LL, -1LL);
			for(int i = -1; i <= 1; i++)
			{
				if(0 <= d + i && d + i <= 9)
				{
					pair <ll, ll> tmp = solve(x * 10 + d, y * 10 + d + i, pos + 1, -i);
					if(res.first == -1 || 
						abs(tmp.first - tmp.second) < abs(res.first - res.second) ||
						(abs(tmp.first - tmp.second) == abs(res.first - res.second) && tmp.first < res.first) ||
						(abs(tmp.first - tmp.second) == abs(res.first - res.second) && tmp.first == res.first && tmp.second < res.second))
						res = tmp;
				}
			}
			return res;
		}
		if(a[pos] == '?' && b[pos] == '?')
		{
			pair <ll, ll> res = make_pair(-1LL, -1LL);
			for(int i = 0; i <= 1; i++)
				for(int j = 0; j <= 1; j++)
				{
					pair <ll, ll> tmp = solve(x * 10 + i, y * 10 + j, pos + 1, mycmp(i, j));
					if(res.first == -1 || 
						abs(tmp.first - tmp.second) < abs(res.first - res.second) ||
						(abs(tmp.first - tmp.second) == abs(res.first - res.second) && tmp.first < res.first) ||
						(abs(tmp.first - tmp.second) == abs(res.first - res.second) && tmp.first == res.first && tmp.second < res.second))
						res = tmp;
				}
			return res;
		}
	}
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		cin >> a >> b;
		pair <ll, ll>  res = solve(0, 0, 0, 0);
		string s1 = to_string(res.first);
		string s2 = to_string(res.second);
		while(s1.size() < a.size())
			s1 = "0" + s1;
		while(s2.size() < a.size())
			s2 = "0" + s2;
		printf("Case #%d: %s %s\n", t, s1.c_str(), s2.c_str());
		cerr << t << endl;
	}
	return 0;
}
