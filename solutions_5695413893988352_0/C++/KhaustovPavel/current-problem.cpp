#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <memory.h>
#include <ctime>
 
using namespace std;
 
#pragma comment(linker, "/STACK:128000000")
 
typedef pair<int, int> pii;
typedef long long int64;
typedef pair<int64, int64> pii64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<int,pii> piii;
typedef pair<int64,pii> piii64;
typedef pair<pii,pii> piiii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
 
#define y1 dsjfksdj_fks
#define y2 alksaad_sa
#define y0 _sdkfsjfs__
 
#define tm _dskfjskdfjksdf

inline string int64_to_string(int64 x)
{
	string res = "";
	while (x)
	{
		res = static_cast<char>(x % 10 + '0') + res;
		x /= 10;
	}
	return res;
}

inline string addz(int64 x, int t)
{
	string res = int64_to_string(x);
	while (static_cast<int>(res.length()) < t)
		res = '0' + res;
	return res;
}

inline int64 abs64(int64 x)
{
	return x < 0 ? -x : x;
}

struct elem
{
	int64 x;
	int64 y;

	elem()
	{
		x = y = -1LL;
	}

	elem(int64 xx, int64 yy)
	{
		x = xx;
		y = yy;
	}

	bool operator < (const elem &B) const
	{
		if (x == -2) return false;
		if (B.x == -2) return true;
		if (abs64(x - y) < abs64(B.x - B.y)) return true;
		if (abs64(x - y) > abs64(B.x - B.y)) return false;
		return pii64(x, y) < pii64(B.x, B.y);
	};
};

int nt;
int n;
string s1, s2;
vi a, b;
int64 p10[19];

inline elem check(int pf)
{
	elem res(-2LL, -2LL);
	if (a[pf] == b[pf] && a[pf] != -1) return res;
	int st1 = 0, fn1 = 9;
	if (a[pf] != -1)
		st1 = fn1 = a[pf];
	int st2 = 0, fn2 = 9;
	if (b[pf] != -1)
		st2 = fn2 = b[pf];
	for (int d1 = st1; d1 <= fn1; ++d1)
		for (int d2 = st2; d2 <= fn2; ++d2)
		{
			if (d1 == d2) continue;
			elem cur(p10[n - pf - 1] * d1, p10[n - pf - 1] * d2);
			if (d1 < d2)
			{
				for (int i = pf + 1; i < n; ++i)
				{
					cur.x += p10[n - i - 1] * (a[i] == -1 ? 9 : a[i]);
					cur.y += p10[n - i - 1] * (b[i] == -1 ? 0 : b[i]);
				}
			} else {
				for (int i = pf + 1; i < n; ++i)
				{
					cur.x += p10[n - i - 1] * (a[i] == -1 ? 0 : a[i]);
					cur.y += p10[n - i - 1] * (b[i] == -1 ? 9 : b[i]);
				}
			}
			if (cur < res)
				res = cur;
		}
	return res;
}

inline elem solve()
{
	elem res(-2LL, -2LL);
	a.clear();
	b.clear();
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; ++i)
	{
		a[i] = (s1[i] == '?') ? -1 : static_cast<int>(s1[i] - '0');
		b[i] = (s2[i] == '?') ? -1 : static_cast<int>(s2[i] - '0');
	}
	int ok = 1;
	elem prefans(0LL, 0LL);
	for (int pf = 0; pf < n; ++pf)
	{
		elem cur = check(pf);
		if (cur.x != -2LL)
		{
			cur.x += prefans.x;
			cur.y += prefans.y;
			if (cur < res)
				res = cur;
		}
		if (a[pf] != -1 || b[pf] != -1)
		{
			if (a[pf] != -1 && b[pf] != -1 && a[pf] != b[pf])
			{
				ok = 0;
				break;
			}
			int64 dig = static_cast<int64>(max(a[pf], b[pf]));
			int64 mdig = p10[n - pf - 1] * dig;
			prefans.x += mdig;
			prefans.y += mdig;
		}
	}
	if (ok)
		return prefans;
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	p10[0] = 1LL;
	for (int i = 1; i < 19; ++i)
		p10[i] = p10[i - 1] * 10LL;
	
	cin >> nt;
	for (int tn = 1; tn <= nt; ++tn)
	{
		cin >> s1 >> s2;
		n = static_cast<int>(s1.length());
		elem res = solve();
		printf("Case #%d: ", tn);
		cout << addz(res.x, n) << " " << addz(res.y, n) << endl;
	}

    return 0;
}  