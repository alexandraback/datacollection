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
	void write()
	{
		cout << answer_c << ' ' << answer_j << endl;
	}
	
	string answer_c = "", answer_j;
	void suggest(const string &c, const string &j)
	{
		if (answer_c == "")
		{
			answer_c = c;
			answer_j = j;
		}
		ll answer_cc = strtoll(answer_c.c_str(), NULL, 10);
		ll answer_jj= strtoll(answer_j.c_str(), NULL, 10);
		ll cc = strtoll(c.c_str(), NULL, 10);
		ll jj = strtoll(j.c_str(), NULL, 10);
		if (abs(answer_cc - answer_jj) > abs(cc - jj) || abs(answer_cc - answer_jj) == abs(cc - jj) && answer_cc > cc || abs(answer_cc - answer_jj) == abs(cc - jj) && answer_cc == cc && answer_jj > jj)
		{
			answer_c = c;
			answer_j = j;
		}
	}

	void solve()
	{
		FI(SZ(c)+1)
		{
			string cc = c;
			string jj = j;
			FOR(j, i)
			{
				if (cc[j] == jj[j])
				{
					if (cc[j] == '?')
					{
						cc[j] = jj[j] = '0';
					}
				}
				else if (cc[j] == '?')
				{
					cc[j] = jj[j];
				}
				else if (jj[j] == '?')
				{
					jj[j] = cc[j];
				}
			}
			if (i == SZ(c))
			{
				suggest(cc, jj);
				continue;
			}
			FOR(p, 2) {
				if (c[i] == '?' && j[i] == '?')
				{
					cc[i] = '0';
					jj[i] = '1';
				}
				else if (c[i] == '?' && j[i] > '0')
				{
					cc[i] = jj[i] - 1;
				}
				else if (c[i] < '9' && j[i] == '?')
				{
					jj[i] = cc[i] + 1;
				}
				else if (c[i] > j[i] || c[i] == '?' || j[i] == '?')
				{
					swap(cc, jj);
					swap(c, j);
					continue;
				}
				FORS(k, i + 1, SZ(c))
				{
					if (c[k] == '?')
					{
						cc[k] = '9';
					}
					if (j[k] == '?')
					{
						jj[k] = '0';
					}
				}
				if (p == 0)
					suggest(cc, jj);
				else
					suggest(jj, cc);
				swap(cc, jj);
				swap(c, j);
			}
		}
	}
};

int main()
{
#ifdef SMALL
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
#endif
#ifdef LARGE
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
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
