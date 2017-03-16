#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <iostream>
#include <cmath>
#include <sstream>
#include <complex>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:64000000")

typedef long long int64;
typedef unsigned long long uint64;

#define y1 _dsfkjdsfksdj
#define y0 _sfsdkfdop

typedef unsigned uint;
typedef vector<int64> vi64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int64,int64> pii64;
typedef pair<pii,int> piii;
typedef pair<pii,pii> piiii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;

int nt;
int n;

struct attack
{
	int day;
	int power;
	int left;
	int right;

	bool operator < (const attack &b) const
	{
		return day < b.day;
	}
};

int m;
const int MA = 10001;
attack ev[MA];
int h[200002];
const int SHIFT = 100000;

inline void init()
{
	m = 0;
	int d, k, w, e, s, dd, dp, ds;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d%d%d%d%d%d", &d, &k, &w, &e, &s, &dd, &dp, &ds);
		for (int j = 0; j < k; ++j)
		{
			attack tmp;
			tmp.day = d + j * dd;
			tmp.power = s + j * ds;
			tmp.left = w * 2 + j * dp * 2 + SHIFT;
			tmp.right = e * 2 + j * dp * 2 + SHIFT;
			ev[m++] = tmp;
		}
	}
	sort(ev, ev + m);
	memset(h, 0, sizeof h);
}

inline int get_min(int l, int r)
{
	int res = h[l];
	for (int i = l + 1; i <= r; ++i)
		res = min(res, h[i]);
	return res;
}

inline void update(int l, int r, int H)
{
	for (int i = l; i <= r; ++i)
		h[i] = max(h[i], H);
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	scanf("%d", &nt);
	for (int tn = 1; tn <= nt; ++tn)
	{
		init();
		int res = 0;
		int it = 0;
		while (it < m)
		{
			int next_it = it + 1;
			while (next_it < m && ev[next_it].day == ev[it].day) ++next_it;
			
			for (int i = it; i < next_it; ++i)
			{
				int cur_min = get_min(ev[i].left, ev[i].right);
				if (ev[i].power > cur_min) ++res;
			}

			for (int i = it; i < next_it; ++i)
			{
				update(ev[i].left, ev[i].right, ev[i].power);
			}
			
			it = next_it;
		}
		cout << "Case #" << tn << ": " << res << endl;
	}

    return 0;
}