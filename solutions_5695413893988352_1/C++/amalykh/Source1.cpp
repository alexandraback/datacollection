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

vector<pair<string, string>> v;
string s1, s2;

string get_prefix(int len, bool& can)
{
	string res = "";
	for (int i = 0; i < len; i++)
	{
		if (s1[i] == '?' && s2[i] == '?')
		{
			res.push_back('0');
			continue;
		}
		if (s1[i] == '?')
		{
			res.push_back(s2[i]);
			continue;
		}
		if (s2[i] == '?')
		{
			res.push_back(s1[i]);
			continue;
		}
		if (s1[i] != s2[i])
		{
			can = 0;
			return "";
		}
		res.push_back(s1[i]);
	}
	return res;
}

string minimal(string cur, string s)
{
	while (cur.size() < s.size())
	{
		int t = cur.size();
		if (s[t] == '?')
			cur += '0';
		else
			cur += s[t];
	}
	return cur;
}

string maximal(string cur, string s)
{
	while (cur.size() < s.size())
	{
		int t = cur.size();
		if (s[t] == '?')
			cur += '9';
		else
			cur += s[t];
	}
	return cur;
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
		v.clear();
		cin >> s1 >> s2;
		for (int i = 0; i <= s1.size(); i++)
		{
			bool can = 1;
			string common = get_prefix(i, can);
			if (!can) break;

			string ans1 = common;
			string ans2 = common;
			if (i == s1.size())
			{
				v.push_back(mp(ans1, ans2));
				break;
			}

			if (s1[i] == '?' && s2[i] == '?')
			{
				string u1 = ans1;
				string u2 = ans2;
				u1 += '1';
				u2 += '0';
				u1 = minimal(u1, s1);
				u2 = maximal(u2, s2);
				v.push_back(mp(u1, u2));

				u1 = ans1;
				u2 = ans2;
				u1 += '0';
				u2 += '1';
				u1 = maximal(u1, s1);
				u2 = minimal(u2, s2);
				v.push_back(mp(u1, u2));
				continue;
			}
			if (s1[i] == '?')
			{
				string u1 = ans1;
				string u2 = ans2;
				if (s2[i] != '9')
				{
					u1 += (char)(s2[i] + 1);
					u2 += s2[i];
					u1 = minimal(u1, s1);
					u2 = maximal(u2, s2);
					v.push_back(mp(u1, u2));
				}

				if (s2[i] != '0')
				{
					u1 = ans1;
					u2 = ans2;
					u1 += (char)(s2[i] - 1);
					u2 += s2[i];
					u1 = maximal(u1, s1);
					u2 = minimal(u2, s2);
					v.push_back(mp(u1, u2));
				}
				continue;
			}
			if (s2[i] == '?')
			{
				string u1 = ans1;
				string u2 = ans2;
				if (s1[i] != '0')
				{
					u1 += s1[i];
					u2 += (char)(s1[i] - 1);
					u1 = minimal(u1, s1);
					u2 = maximal(u2, s2);
					v.push_back(mp(u1, u2));
				}

				if (s1[i] != '9')
				{
					u1 = ans1;
					u2 = ans2;
					u1 += s1[i];
					u2 += (char)(s1[i] + 1);
					u1 = maximal(u1, s1);
					u2 = minimal(u2, s2);
					v.push_back(mp(u1, u2));
				}
				continue;
			}
			if (s1[i] == s2[i]) continue;
			if (s1[i] > s2[i])
			{
				string u1 = ans1;
				string u2 = ans2;
				u1 += s1[i];
				u2 += s2[i];
				u1 = minimal(u1, s1);
				u2 = maximal(u2, s2);
				v.push_back(mp(u1, u2));
			}
			else
			{
				string u1 = ans1;
				string u2 = ans2;
				u1 += s1[i];
				u2 += s2[i];
				u1 = maximal(u1, s1);
				u2 = minimal(u2, s2);
				v.push_back(mp(u1, u2));
			}
		}

		pair<ll, ll> ans = mp(-2e18, 2e18);

		for (int i = 0; i < v.size(); i++)
		{
			ll a, b;
			sscanf(v[i].first.c_str(), "%lld", &a);
			sscanf(v[i].second.c_str(), "%lld", &b);
			if (abs(ans.first - ans.second) > abs(a - b))
			{
				ans = mp(a, b); continue;
			}
			if (abs(ans.first - ans.second) < abs(a - b)) continue;
			if (a < ans.first)
			{
				ans = mp(a, b);
				continue;
			}
			if (a > ans.first) continue;
			if (b < ans.second)
				ans = mp(a, b);
		}

		stringstream ss;
		ss << ans.first << " " << ans.second;
		string ans1;
		ss >> ans1;
		while (ans1.size() < s1.size()) ans1 = string() + "0" + ans1;
		string ans2;
		ss >> ans2;
		while (ans2.size() < s1.size()) ans2 = string() + "0" + ans2;

		printf("Case #%d: %s %s\n", w + 1, ans1.c_str(), ans2.c_str());

	}

	return 0;
}