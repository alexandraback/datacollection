#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#define _CRT_NO_DEPRECEATE
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <memory.h>
#include <sstream>
#include <cassert>
#include <ctime>
#include <complex>

#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define sq(x) ((x)*(x))
#define tmin(x,y,z) (min(min((x),(y)),(z)))
#define _MOD 1000000009LL
#define MOD(x) (((x) + 2LL * (_MOD)) % (_MOD))
#define INF ((int)(1e9))
#define LINF ((long long)(1e16))
#define EPS (1e-8)
#define PI (3.1415926535897932384626433832795)
#define y1 asdf_1
#define y0 asdf_2
#define j0 jj0
typedef unsigned long long ull;
typedef long double ldd;

using namespace std;

int ks, l, n;
string kbd, txt;
double f[110];
double p[110][110];
double prr[110];
double mf[110];

int calc_mf()
{
	int pr = l;
	for (int i = 1; i < l; i++)
	{
		int ti = i;
		for (int j = 0; j < l && ti < l; j++)
		{
			if (txt[j] != txt[ti])
				break;
			ti++;
		}
		if (ti == l)
		{
			pr = i;
			break;
		}
	}
	return (n - l) / pr + 1;
}

bool check()
{
	for (int i = 0; i < l; i++)
	{
		bool was = false;
		for (int j = 0; j < ks; j++)
		{
			if (txt[i] == kbd[j])
				was = 1;
		}
		if (!was)
			return 1;
	}
	return 0;
}

double solve()
{
	for (int i = 0; i < 110; i++)
		for (int j = 0; j < 110; j++)
		{
			p[i][j] = 0;
			f[i] = 0;
			mf[i] = 0;
		}
	p[0][0] = 1;
	f[0] = 0;
	mf[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < ks; j++)
		{
			char c = kbd[j];
			double prob = p[i - 1][0];
			memset(prr, 0, sizeof prr);
			for (int k = min(l, i - 1); k >= 1; k--)
			{
				prob += p[i - 1][k] - prr[txt[k - 1] - 'A'];
				prr[txt[k - 1] - 'A'] = p[i - 1][k];
			}
			if (c != txt[0])
			{
				p[i][0] += prob / double(ks);
			}
			//double prob2 = 0;
			for (int k = 1; k <= min(l, i); k++)
			{
				if (c == txt[k - 1])
				{
					if (k == 1)
					{
						p[i][k] += (prob) / double(ks);
						//prob2 += (prob - prob2) / double(ks);
					}
					else
					{
						p[i][k] += (p[i - 1][k - 1]) / double(ks);
						//prob2 += (p[i - 1][k - 1] - prob2) / double(ks);
					}
				}
			}
		}
		mf[i] = mf[i - 1];
		if (p[i][l] > 0)
			mf[i]++;

		memset(prr, 0, sizeof prr);
		f[i] += p[i][0] * f[i - 1];
		for (int j = min(l, i); j >= 1; j--)
		{
			f[i] += (p[i][j] - prr[txt[j - 1] - 'A']) * (f[i - 1] + (j == l));
			prr[txt[j - 1] - 'A'] = p[i][j];
		}
	}
	if (check())
		return 0;
	double res = calc_mf() - f[n];
	return res;
}

int main()
{
	//freopen("input.txt", "w", stdout); testgen(5, 60, 120); return 0;
	//freopen("output.txt", "w", stdout);   precalc(); /*for (int i = 20; i < 21; i++)*/ stresstest(5, 25, 120000, 1291);   return 0;

	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int ts;
	cin >> ts;
	cout.precision(8);
	cout << fixed;
	for (int tt = 0; tt < ts; tt++)
	{
		cin >> ks >> l >> n >> kbd >> txt;
		cout << "Case #" << tt + 1 << ": " << solve() << endl;
	}

	return 0;
}