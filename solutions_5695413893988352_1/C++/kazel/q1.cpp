#include<cstdio>
#include<string>
#include<map>
#include<utility>
using namespace std;
using ll = long long;
map<pair<string, string>, pair<string, string>> cache;
char A[22], B[22];
ll stl(string a)
{
	ll ret = 0;
	for (int i = 0; i < a.length(); i++)
	{
		ret *= 10;
		ret += a[i] - '0';
	}
	return ret;
}
ll solve(int i, string& a, string& b, bool aa, bool ba)
{
	if (i == a.length())
	{
		return abs(stl(a) - stl(b));
	}
	if (aa)
	{
		if (a[i] == '?') a[i] = '0';
		if (b[i] == '?') b[i] = '9';
		return solve(i + 1, a, b, aa, ba);
	}
	if (ba)
	{
		if (a[i] == '?') a[i] = '9';
		if (b[i] == '?') b[i] = '0';
		return solve(i + 1, a, b, aa, ba);
	}
	if (cache.find({ a,b }) != cache.end())
	{
		auto val = cache[{a, b}];
		a = val.first;
		b = val.second;
		return abs(stl(a) - stl(b));
	}
	if (a[i] == '?' && b[i] == '?')
	{
		string ta = a, sa = a, tb = b, sb = b;
		ll td, sd;
		sa[i] = '0', sb[i] = '0';
		sd = solve(i + 1, sa, sb, aa, ba);
		ta[i] = '1', tb[i] = '0';
		td = solve(i + 1, ta, tb, true, false);
		if (td < sd)
		{
			sd = td;
			sa = ta;
			sb = tb;
		}
		else if (td == sd)
		{
			if (ta < sa || (ta == sa) && tb < sb)
			{
				sd = td;
				sa = ta;
				sb = tb;
			}
		}
		ta = a, tb = b;
		ta[i] = '0', tb[i] = '1';
		td = solve(i + 1, ta, tb, false, true);
		if (td < sd)
		{
			sd = td;
			sa = ta;
			sb = tb;
		}
		else if (td == sd)
		{
			if (ta < sa || (ta == sa) && tb < sb)
			{
				sd = td;
				sa = ta;
				sb = tb;
			}
		}
		cache.insert({ { a,b }, { sa,sb } });
		a = sa;
		b = sb;
		return sd;
	}
	else if (a[i] == '?')
	{
		string ta, sa = a, tb, sb = b;
		ll td, sd;
		sa[i] = sb[i];
		sd = solve(i + 1, sa, sb, aa, ba);
		if (b[i] < '9')
		{
			ta = a, tb = b;
			ta[i] = tb[i] + 1;
			td = solve(i + 1, ta, tb, true, false);
			if (td < sd)
			{
				sd = td;
				sa = ta;
				sb = tb;
			}
			else if (td == sd)
			{
				if (ta < sa || (ta == sa) && tb < sb)
				{
					sd = td;
					sa = ta;
					sb = tb;
				}
			}
		}
		if (b[i] > '0')
		{
			ta = a, tb = b;
			ta[i] = tb[i] - 1;
			td = solve(i + 1, ta, tb, false, true);
			if (td < sd)
			{
				sd = td;
				sa = ta;
				sb = tb;
			}
			else if (td == sd)
			{
				if (ta < sa || (ta == sa) && tb < sb)
				{
					sd = td;
					sa = ta;
					sb = tb;
				}
			}
		}
		cache.insert({ { a,b },{ sa,sb } });
		a = sa;
		b = sb;
		return sd;
	}
	else if (b[i] == '?')
	{
		string ta, sa = a, tb, sb = b;
		ll td, sd;
		sb[i] = sa[i];
		sd = solve(i + 1, sa, sb, aa, ba);
		if (a[i] < '9')
		{
			ta = a, tb = b;
			tb[i] = ta[i] + 1;
			td = solve(i + 1, ta, tb, false, true);
			if (td < sd)
			{
				sd = td;
				sa = ta;
				sb = tb;
			}
			else if (td == sd)
			{
				if (ta < sa || (ta == sa) && tb < sb)
				{
					sd = td;
					sa = ta;
					sb = tb;
				}
			}
		}
		if (a[i] > '0')
		{
			ta = a, tb = b;
			tb[i] = ta[i] - 1;
			td = solve(i + 1, ta, tb, true, false);
			if (td < sd)
			{
				sd = td;
				sa = ta;
				sb = tb;
			}
			else if (td == sd)
			{
				if (ta < sa || (ta == sa) && tb < sb)
				{
					sd = td;
					sa = ta;
					sb = tb;
				}
			}
		}
		cache.insert({ { a,b },{ sa,sb } });
		a = sa;
		b = sb;
		return sd;
	}
	else
	{
		if (a[i]>b[i]) return solve(i + 1, a, b, true, false);
		if (a[i]<b[i]) return solve(i + 1, a, b, false, true);
		return solve(i + 1, a, b, aa, ba);
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T, n;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%s%s", A, B);
		string a = A, b = B;
		solve(0, a, b, false, false);
		printf("Case #%d: %s %s\n", t, a.c_str(), b.c_str());
	}
}