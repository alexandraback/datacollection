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

};

void solve()
{
	int T;
	cin >> T;
	for (int q = 0; q < T; q++)
	{
		cerr << q << endl;
		int L, X;
		cin >> L >> X;
		LL n = L * X;
		string s;
		cin >> s;
		string s2;
		for (int i = 0; i < X; i++)
			s2 += s;

		vector <st> pref(n + 1);
		pref[0] = st(1);
		for (int i = 0; i < n; i++)
			pref[i + 1] = pref[i] * st(s2[i]);

		bool fl = false;
		for (int l = 0; l < n; l++)
			for (int r = l + 1; r < n; r++)
			{
				st v1 = pref[l + 1];
				st v2 = pref[r + 1] / pref[l + 1];
				st v3 = pref[n] / pref[r + 1];

				if (v1.x == st('i').x && v2.x == st('j').x && v3.x == st('k').x)
				{
					fl = 1;
					break;
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