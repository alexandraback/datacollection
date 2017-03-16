#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <set>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <stdint.h>
using namespace std;

int get_id(char ch)
{
	string u("1ijk");
	return (int)u.find(ch);
}

pair<char, bool> get_mul(pair<char, bool> a, pair<char, bool> b)
{
	pair<char, bool> res;
	pair<char, bool> arr[4][4] =
	{
		{
			{ '1', false },
			{ 'i', false },
			{ 'j', false },
			{ 'k', false },
		},
		{
			{ 'i', false },
			{ '1', true },
			{ 'k', false },
			{ 'j', true },
		},
		{
			{ 'j', false },
			{ 'k', true },
			{ '1', true },
			{ 'i', false },
		},
		{
			{ 'k', false },
			{ 'j', false },
			{ 'i', true },
			{ '1', true },
		}
	};
	res = arr[get_id(a.first)][get_id(b.first)];
	res.second = a.second ^ b.second ^ res.second;
	return res;
}

void solve(int test)
{
	int64_t l, x;
	cin >> l >> x;
	string str;
	cin >> str;
	string res;
	string u("ijk");
	int id = 0;
	for (int i = 0; i < x; ++i)
	{
		res += str;
	}
	pair<char, bool> cur = { '1', false };
	int q = -1;
	for (int i = 0; i < res.size(); ++i)
	{
		if (id < u.size() && cur.first == u[id] && cur.second == false)
		{
			++id;
			q = i;
			cur = { res[i], false };
		}
		else
		{
			cur = get_mul(cur, { res[i], false });
		}
	}
	if (id < u.size() && cur.first == u[id] && cur.second == false)
	{
		++id;
		cur = { '1', false };
	}
	string ans = "NO";
	if (id == u.size() && cur == make_pair('1', false))
		ans = "YES";
	cout << "Case #" << test << ": " << ans << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		solve(i+1);
	}
	return 0;
}