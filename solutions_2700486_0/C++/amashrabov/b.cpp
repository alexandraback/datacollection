#pragma comment(linker, "/STACK:10000000")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> T inline sqr(T x) {
    return x * x;
}
#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(v) (int)((v).size())
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

typedef vector<pii> vpii;
ld solve()
{
	int n;
	int x, y;
	map<vpii, ld> lastProb, curProb;
	cin >> n >> x >> y;
	lastProb[vpii(1, mp(0, 0))] = 1.0;
	for (int i1 = 0; i1 < n - 1; i1++)
	{
		for (auto it : lastProb)
		{
			vpii a = it.first;
			int mx = 0;
			for (int i = 0; i < a.size(); i++)
			if (a[i].first == 0)
			{
				mx = max(mx, a[i].second);
			}
			int left = -mx - 3, right = mx + 3;
			for (int i = 0; i < a.size(); i++)
			{
				if (abs(a[i].first) + a[i].second == mx + 2)
				{
					if (a[i].first < 0)
						left = max(left, a[i].first);
					if (a[i].first > 0)
						right = min(right, a[i].first);
				}
			}
			if (left == -1 && right == 1)
			{
				a.push_back(mp(0, mx + 2));
				curProb[a] += it.second;
			}
			if (left == -1 && right != 1)
			{
				a.push_back(mp(right - 1, mx + 2 - (right - 1)));
				curProb[a] += it.second;
			}
			if (left != -1 && right == 1)
			{
				a.push_back(mp(left + 1, mx + 2 + (left + 1)));
				curProb[a] += it.second;
			}
			if (left != -1 && right != 1)
			{
				vpii b = a;
				a.push_back(mp(left + 1, mx + 2 + (left + 1)));
				curProb[a] += it.second / 2.0;
				b.push_back(mp(right - 1, mx + 2 - (right - 1)));
				curProb[b] += it.second / 2.0;
			}
		}
		lastProb = curProb;
		curProb.clear();
	}
	ld ans = 0;
	for (auto it : lastProb)
	{
		vpii a = it.first;
		for (int i = 0; i < a.size(); i++)
			if (a[i] == mp(x, y))
			{
				ans += it.second;
			}
	}
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		ld ans = solve();
		cerr << i << endl;
		printf("Case #%d: %.8lf\n", i + 1, ans);
	}
	return 0;
}
