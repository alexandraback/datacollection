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

int mat[4][4] = {{1, 2, 3, 4},
				 {2, -1, 4, -3},
				 {3, -4, -1, 2},
				 {4, 3, -2, -1}};

struct st
{
	st() {}
	st(char ch)
	{
		switch (ch)
		{
			case 'i' : {x = 2; break;}
			case 'j' : {x = 3; break;}
			case 'k' : {x = 4; break;}
		}
	}
	st(int x): x(x)
	{
	}
	int x;
	friend st operator* (const st &a, const st &b)
	{
		int sg1 = a.x < 0 ? -1 : 1;
		int sg2 = b.x < 0 ? -1 : 1;
		int v1 = abs(a.x);
		int v2 = abs(b.x);
		return sg1 * sg2 * mat[v1 - 1][v2 - 1];
	}

	friend st operator/ (const st &a, const st &b)
	{
		for (int i = 1; i < 5; i++)
		{
			for (int sgn = -1; sgn < 2; sgn += 2)
			{
				if ((b * st(i * sgn)).x == a.x)
				{
					return st(i * sgn);
				}
			}
		}
	}
	friend bool operator== (const st &a, const st &b)
	{
		return a.x == b.x;
	}
};

st binPow(st a, LL k)
{
	if (k == 0)
		return st(1);
	if (k % 2 == 0)
	{
		st tmp = binPow(a, k / 2);
		return tmp * tmp;
	}
	else
	{
		st tmp = binPow(a, k - 1);
		return tmp * a;
	}
}

void solve()
{
	int T;
	cin >> T;
	for (int q = 0; q < T; q++)
	{
		cerr << q << endl;
		LL L, X;
		cin >> L >> X;
		string s;
		cin >> s;

		vector <st> pref(L + 1);
		pref[0] = st(1);
		for (int i = 0; i < L; i++)
			pref[i + 1] = pref[i] * st(s[i]);

		st mul = binPow(pref[L], X);
		bool fl = false;
		if (!(mul == st('i') * st('j') * st('k')))
			fl = false;
		else
		{
			st cur(1);
			LL lim = min(1000000000LL, L * X);
			LL pos1 = -1;
			for (int i = 0; i < lim; i++)
			{
				cur = cur * st(s[i % L]);
				if (cur == st('i'))
				{
					pos1 = i;
					break;
				}
			}

			LL pos2 = -1;
			cur = st(1);
			for (int i = 0; i < lim; i++)
			{
				cur = st(s[((L - 1 - i) % L + L) % L]) * cur;
				if (cur == st('k'))
				{
					pos2 = X * L - 1 - i;
					break;
				}
			}

			if (pos1 != -1 && pos2 != -1 && pos1 < pos2 - 1)
			{
				fl = true;
			}
		}

		cout << "Case #" <<q + 1 << ": ";
		if (fl)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

int main()
{

	//START
    //freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);
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
        os << v[i] << " ";
    return os;
}
#endif