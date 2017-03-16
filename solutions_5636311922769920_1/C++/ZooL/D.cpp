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


LL binPow(LL a, LL k)
{
	if (k == 0)
		return 1;
	if (k % 2 == 0)
	{
		LL t = binPow(a, k / 2);
		return t * t;
	}
	else
	{
		LL t = binPow(a, k - 1);
		return t * a;
	}
}

void solve()
{
	int T;
	cin >> T;
	for (int q = 0; q < T; q++)
	{
		cerr << q << endl;
		LL K, C, S;
		cin >> K >> C >> S;

		cout << "Case #" << q + 1 << ": ";
	
		LL cnt = (K + C - 1) / C;

		if (cnt > S)
		{
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		for (int i = 0; i < cnt; i++)
		{
			LL p = i * C;
			LL ansP = binPow(K, (C - 1)) * p;
			for (int j = 1; j < min(C, K - p); j++)
			{
				LL v = binPow(K, (C - 1 - j));
				v *= j;

				ansP += v;
			}
			cout << ansP + 1 << " ";
		}
		cout << endl;
	}
}

int main()
{

	//START
	//freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
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