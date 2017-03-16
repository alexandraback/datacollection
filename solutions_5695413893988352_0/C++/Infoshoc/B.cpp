/*

A computer science student is studying under a tree and another pulls up on a flashy new bike. The first student asks, “Where’d you get that?”

The student on the bike replies, “While I was studying outside, a beautiful girl pulled up on her bike. She took off all her clothes and said, ‘You can have anything you want’.”

The first student responds, “Good choice! Her clothes probably wouldn’t have fit you.”

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define FOR(i,n) FORS(i,0,(n))
#define FI(n) FOR(i,(n))
#define MP(x,y) make_pair((x),(y))
#define PB(x) push_back((x))
#define SZ(c) int((c).size())
typedef vector<int> vi; typedef vector<vi> vvi; typedef pair<int, int> pii; typedef long long ll; typedef unsigned long long ull; typedef pair<ll, ll> pll; typedef list<pll> lpll; typedef list<ll> lll; typedef vector<ll> vll; typedef set < int > si;
#ifndef __GNUG__
int __builtin_popcount(unsigned int x) { int result = 0; while (x) { result += x & 1; x >>= 1; }return result; }
int __builtin_popcountll(unsigned long long x) { int result = 0; while (x) { result += x & 1; x >>= 1; }return result; }
#endif
#define popcount __builtin_popcountll
ll gcd(ll, ll, ll&, ll&); ll gcd(ll, ll); ll lcm(ll, ll);
template<class T>const T sqr(const T x);
template<class T> const T binpow(const T a, const ull, const T);

struct Solution
{
	string c, j;
	void read()
	{
		cin >> c >> j;
	}
	char pattern[100];
	void write()
	{
		static char cc_buffer[100];
		sprintf_s(cc_buffer, pattern, ccc);
		static char jj_buffer[100];
		sprintf_s(jj_buffer, pattern, jjj);
		printf("%s %s\n", cc_buffer, jj_buffer);
	}
	static bool match(const string &tested, const string &pattern)
	{
		assert(tested.size() == pattern.size());
		FI(SZ(pattern))
		{
			if (pattern[i] != tested[i] && pattern[i] != '?')
			{
				return false;
			}
		}
		return true;
	}
	int ccc, jjj;
	void solve()
	{
		ll _10 = 1;
		FI(c.size())
		{
			_10 *= 10;
		}
		ccc = jjj = -1;
		
		sprintf_s(pattern, "%%0%dd", (int)c.size());
		for (int cc = 0; cc < _10; ++cc)
		{
			static char cc_buffer[100];
			sprintf_s(cc_buffer, pattern, cc);
			if (!match(string(cc_buffer), c))
			{
				continue;
			}
			for (int jj = 0; jj < _10; ++jj)
			{
				static char jj_buffer[100];
				sprintf_s(jj_buffer, pattern, jj);
				if (!match(string(jj_buffer), j))
				{
					continue;
				}
				if (ccc == -1 ||
					abs(cc - jj) < abs(ccc - jjj) || abs(cc - jj) == abs(ccc - jjj) && cc < ccc || abs(cc - jj) == abs(ccc - jjj) && cc == ccc && jj < jjj)
				{
					ccc = cc;
					jjj = jj;
				}
			}
		}
	}
};

int main()
{
//#ifdef SMALL
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
//#endif
#ifdef LARGE
	freopen("A-large-attempt0.in", "r", stdin);
	freopen("A-large-attempt0.out", "w", stdout);
#endif
	int t;
	cin >> t;

	for (int testcase = 1; testcase <= t; ++testcase)
	{
		Solution solution;
		solution.read();
		solution.solve();
		printf("Case #%d: ", testcase);
		solution.write();
	}

	return 0;
}


ll gcd(ll a, ll b, ll & x, ll & y)
{
	if (a == 0)
	{
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

ll gcd(ll a, ll b) { return gcd(a, b, a, b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
template<class T>const T sqr(const T x) { return x*x; }
template<class T> const T binpow(const T a, const ull n, const T modulo) { return n == 0 ? 1 : sqr(binpow(a, n / 2, modulo)) % modulo * (n % 2 ? a : 1) % modulo; }
