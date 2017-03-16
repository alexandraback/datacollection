#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ldouble;

int ans[210], all[210], sz = 0;
int us[210];
string s, t, tmp;

int C(int x, int y)
{
	int res = 1;
	for (int i = 1; i <= y; i++)
		res = (res / i) * (x - i + 1);
	return res;
}

bool check(const string &s)
{
	int ans = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != s[s.length() - 1 - i]) return false;
		ans += (int)(s[i] - '0') * (int)(s[i] - '0');
	}
	return (ans < 10);
}

int get(const string &s)
{
	int usz = 0;
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
		{
			int u = (all[i] >> 2) + (all[j] >> 2), v = (all[i] & 3) * (all[j] & 3);
			if (tmp[u] == '0') us[usz++] = u;
			tmp[u] += (char)v;
		}
	int res = (tmp <= s);
	for (int i = 0; i < usz; i++)
		tmp[us[i]] = '0';
	return res;
}

int solve(const string &s)
{
	int len = s.length();
	if (len == 1)
	{
		if (s[0] < '1') return 0;
		if (s[0] < '4') return 1;
		else if (s[0] < '9') return 2;
		else return 3;
	}
	int res = 0;
	for (int i = 1; 2 * i - 1 < len; i++) res += ans[i];
	if (len % 2 == 0) return res;
	int L = (len + 1) / 2;
	tmp = string(len, '0');
	all[0] = 2, all[1] = (L - 1) * 4 + 2; sz = 2; res += get(s);
	if (L % 2 == 1) all[2] = (L / 2) * 4 + 1, sz = 3, res += get(s);
	if (L % 2 == 1)
	{
		all[0] = 1, all[1] = (L - 1) * 4 + 1, all[2] = (L / 2) * 4 + 2; res += get(s);
		sz = 5;
		for (int i = 1; i < L / 2; i++)
			all[3] = i * 4 + 1, all[4] = (L - 1 - i) * 4 + 1, res += get(s);
	}
	sz = 2; all[0] = 1, all[1] = (L - 1) * 4 + 1; int bd = (L / 2) * 4 + 1;
	for (int i = 1; i < L / 2; i++)
	{
		sz += 2; all[2] = i * 4 + 1, all[3] = (L - 1 - i) * 4 + 1;
		for (int j = i + 1; j < L / 2; j++)
		{
			sz += 2; all[4] = j * 4 + 1, all[5] = (L - 1 - j) * 4 + 1;
			for (int k = j + 1; k < L / 2; k++)
			{
				sz += 2; all[6] = k * 4 + 1, all[7] = (L - 1 - k) * 4 + 1;
				if (L % 2 == 1) sz++, all[8] = bd, res += get(s), sz--;
				res += get(s); sz -= 2;
			}
			if (L % 2 == 1) sz++, all[6] = bd, res += get(s), sz--;
			res += get(s); sz -= 2;
		}
		if (L % 2 == 1) sz++, all[4] = bd, res += get(s), sz--;
		res += get(s); sz -= 2;
	}
	if (L % 2 == 1) sz++, all[2] = bd, res += get(s), sz--;
	res += get(s); sz -= 2;
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ans[1] = 3;
	for (int i = 2; i <= 100; i++)
		if (i % 2 == 1) ans[i] = 4 + i / 2 + 2 * (C(i / 2 - 1, 1) + C(i / 2 - 1, 2) + C(i / 2 - 1, 3));
		else ans[i] = 2 + C(i / 2 - 1, 1) + C(i / 2 - 1, 2) + C(i / 2 - 1, 3);
	
	int ts; scanf("%d\n", &ts); int Ans = 0;
	for (int tst = 0; tst < ts; tst++)
	{
		getline(cin, s);
		int cur = 0; while (s[cur] != ' ') cur++;
		t = s.substr(cur + 1, s.length() - cur - 1);
		s = s.substr(0, cur); cur = -1;
		for (int i = s.length() - 1; i >= 0; i--)
		{
			s[i] += (char)cur;
			if (s[i] < '0') s[i] += (char)10, cur = -1;
			else cur = 0;
		}
		if (s[0] == '0' && s.length() > 1) s = s.substr(1, s.length() - 1);
		Ans = solve(t) - solve(s);
		printf("Case #%d: %d\n", tst + 1, Ans);
	}
	return 0;
}