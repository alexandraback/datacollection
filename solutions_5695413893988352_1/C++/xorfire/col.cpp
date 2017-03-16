#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

string a, b, cur_a, cur_b, ret1, ret2;
int n, p, ans, diff, powa[20];

void go()
{
	if (p == n)
	{
		if (ans < 0 or abs(diff) < ans)
			ret1 = cur_a, ret2 = cur_b, ans = abs(diff);
		return;
	}

	set < pair <int, int> > check;

	if (a[p] != '?' and b[p] != '?')
		check.insert(make_pair(a[p] - '0', b[p] - '0'));
	else if (a[p] == '?' and b[p] == '?')
	{
		pair <int, int> fst, snd, trd;
		fst = snd = trd = make_pair(-1, -1);
		int minp = -1, minn = 1;
		for (int v = 0; v <= 9; v++)
		{
			int u = 0;
			{
				int now = diff + powa[n - p - 1] * (u - v);
				if (now > 0 and (minp < 0 or now < minp))
				{
					minp = now;
					fst = make_pair(u, v);
				}
				if (now < 0 and (minn > 0 or now > minn))
				{
					minn = now;
					snd = make_pair(u, v);
				}
				if (now == 0) trd = make_pair(u, v);
			}
			swap(u, v);
			{
				int now = diff + powa[n - p - 1] * (u - v);
				if (now > 0 and (minp < 0 or now < minp))
				{
					minp = now;
					fst = make_pair(u, v);
				}
				if (now < 0 and (minn > 0 or now > minn))
				{
					minn = now;
					snd = make_pair(u, v);
				}
				if (now == 0 and trd.first < 0) trd = make_pair(u, v);
			}
			swap(u, v);
		}
		if (fst.first >= 0) check.insert(fst);
		if (snd.first >= 0) check.insert(snd);
		if (trd.first >= 0) check.insert(trd);
	}
	else if (b[p] == '?')
	{
		pair <int, int> fst, snd, trd;
		fst = snd = trd = make_pair(-1, -1);
		int minp = -1, minn = 1;
		for (int v = 0; v <= 9; v++)
		{
			int u = a[p] - '0';
			int now = diff + powa[n - p - 1] * (u - v);
			if (now > 0 and (minp < 0 or now < minp))
			{
				minp = now;
				fst = make_pair(u, v);
			}
			if (now < 0 and (minn > 0 or now > minn))
			{
				minn = now;
				snd = make_pair(u, v);
			}
			if (now == 0) trd = make_pair(u, v);
		}
		if (fst.first >= 0) check.insert(fst);
		if (snd.first >= 0) check.insert(snd);
		if (trd.first >= 0) check.insert(trd);
	}
	else
	{
		pair <int, int> fst, snd, trd;
		fst = snd = trd = make_pair(-1, -1);
		int minp = -1, minn = 1;
		for (int u = 0; u <= 9; u++)
		{
			int v = b[p] - '0';
			int now = diff + powa[n - p - 1] * (u - v);
			if (now > 0 and (minp < 0 or now < minp))
			{
				minp = now;
				fst = make_pair(u, v);
			}
			if (now < 0 and (minn > 0 or now > minn))
			{
				minn = now;
				snd = make_pair(u, v);
			}
			if (now == 0) trd = make_pair(u, v);
		}
		if (fst.first >= 0) check.insert(fst);
		if (snd.first >= 0) check.insert(snd);
		if (trd.first >= 0) check.insert(trd);
	}

	for (pair <int, int> z : check)
	{
		int u = z.first, v = z.second;
		cur_a += '0' + u;
		cur_b += '0' + v;
		diff += powa[n - p - 1] * (u - v);
		p++;
		go();
		p--;
		diff -= powa[n - p - 1] * (u - v);
		cur_a.pop_back();
		cur_b.pop_back();
	}
}

#undef int
int main()
{
#define int long long
	powa[0] = 1;
	for (int i = 1; i < 20; i++) powa[i] = powa[i - 1] * 10;

	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cerr << "Executing Case #" << tt << "\n";
		cin >> a >> b;
		n = a.size(), p = 0, ans = -1, diff = 0, cur_a = "", cur_b = "";
		go();
		cout << "Case #" << tt << ": ";
		cout << ret1 << " " << ret2 << "\n";
	}
	return 0;
}