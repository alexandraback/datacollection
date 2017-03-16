#if 1
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> pii;

const LD eps = 1e-9;
const LD pi = acos(-1.0);
const LL inf = 1e+9;

#define mp make_pair
#define pb push_back
#define X first
#define Y second

#define dbg(x) { cerr << #x << " = " << x << endl; }

// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> istream & operator >> (istream &, vector<T> &);
template<typename T> ostream & operator << (ostream &, const vector<T> &);

#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;

#define NAME "basket"
const int n = 16;
const int J = 50;

LL getVal(int mask, int base, int mod)
{
	LL res = 0;
	LL p = 1;
	for (int i = 0; i < n; i++)
	{
		if (mask & (1 << i))
		{
			res += p;
			res %= mod; 
		}
		p *= base;
		p %= mod;
	}
	return res;
}

const int maxn = 10000000;
bool p[maxn];
vector <int> pr;

void solve()
{	
	for (int i = 2; i * i < maxn; i++)
		if (p[i] == 0)
			for (int j = i * i; j < maxn; j += i)
				p[j] = 1;

	for (int i = 2; i < maxn; i++)
		if (p[i] == 0)
			pr.pb(i);
	int cnt = 0;
	cout << "Case #1:" << endl;
	for (LL i = 0; i < (1LL << (n - 2)); i++)
	{
		LL mask = (1LL << (n - 1)) + (i << 1) + 1;
		vector <LL> ans(9);
		bool fl = 1;
		for (int base = 2; base <= 10; base++)
		{
			bool fl2 = 0;
			for (int j = 0; j < 100; j++)
			{
				if (pr[j] == mask)
					continue;

				LL v = getVal(mask, base, pr[j]);
				if (v == 0)
				{
					ans[base - 2] = pr[j];
					fl2 = 1;
					break;
				}
			}
			if (fl2 == 0)
			{
				fl = 0;
				break;
			}
		}

		if (fl)
		{
			dbg(cnt++);
			cout << bitset<n>(mask) << " ";
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i] << " ";
			cout << endl;

			if (cnt == J)
				break;
		}
	}
}

int main()
{

	//START
	//freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
	//freopen("input.txt", "r", stdin); //
	freopen("output.txt", "w", stdout);
	// ios_base::sync_with_stdio(false);
	solve();
	//END
	return 0;
}
/*******************************************
*******************************************/

template<typename T> istream & operator >> (istream &is, vector<T> &v)
{
	forn(i, v.size())
		is >> v[i];
	return is;
}
template<typename T> ostream & operator << (ostream &os, const vector<T> &v)
{
	forn(i, v.size())
		os << v[i];
	return os;
}
#endif