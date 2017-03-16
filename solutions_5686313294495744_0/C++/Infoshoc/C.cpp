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
	vector < string > topics[2];
	void read()
	{
		int n;
		cin >> n;
		topics[0].resize(n);
		topics[1].resize(n);
		FI(n)
		{
			cin >> topics[0][i] >> topics[1][i];
		}
	}
	int answer = 0;
	void write()
	{
		printf("%d\n", answer);
	}
	void solve()
	{
		for (unsigned mask = 0; mask < (1 << SZ(topics[0])); ++mask)
		{
			if (popcount(mask) <= answer)
			{
				continue;
			}
			set < string > original[2];
			FI(SZ(topics[0]))
			{
				if (((mask >> i) & 1) == 0)
				{
					original[0].insert(topics[0][i]);
					original[1].insert(topics[1][i]);
				}
			}
			bool possible = true;
			FI(SZ(topics[0]))
			{
				possible &= original[0].count(topics[0][i]) && original[1].count(topics[1][i]);
				if (!possible) break;
			}
			answer = possible ? popcount(mask) : answer;
		}
	}
};

int main()
{
//#ifdef SMALL
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
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

	fclose(stdout);
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
