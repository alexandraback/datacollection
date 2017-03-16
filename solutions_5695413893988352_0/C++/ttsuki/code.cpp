////////////////////////////////////////
///  tu3 pro-con template            ///
////////////////////////////////////////
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <complex>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <regex>
#include <cctype>
using namespace std;

//// MACRO ////
#define countof(a) (sizeof(a)/sizeof(a[0]))

#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i,n) for (int i = (n)-1; i >= 0; i--)
#define FOR(i,s,n) for (int i = (s); i < (n); i++)
#define RFOR(i,s,n) for (int i = (n)-1; i >= (s); i--)
#define pos(c,i) c.being() + (i)
#define allof(c) c.begin(), c.end()
#define aallof(a) a, a + countof(a)
#define partof(c,i,n) c.begin() + (i), c.begin() + (i) + (n)
#define apartof(a,i,n) a + (i), a + (i) + (n)
#define long long long

#define EPS 1e-9
#define INF (1L << 30)
#define LINF (1LL << 60)

#define PREDICATE(t,a,exp) [&](const t & a) -> bool { return exp; }
#define COMPARISON_T(t) bool(*)(const t &, const t &)
#define COMPARISON(t,a,b,exp) [&](const t & a, const t & b) -> bool { return exp; }
#define CONVERTER(TSrc,t,TDest,exp) [&](const TSrc &t)->TDest { return exp; }

template <class T> struct vevector : public vector < vector<T> > { vevector(int n = 0, int m = 0, const T &initial = T()) : vector<vector<T>>(n, vector<T>(m, initial)) { } };

//// i/o helper ////

template <class T1, class T2> inline istream & operator >> (istream & in, pair<T1, T2> &p) { in >> p.first >> p.second; return in; }
template <class T1, class T2> inline ostream & operator << (ostream &out, pair<T1, T2> &p) { out << p.first << p.second; return out; }

template <class T> T read() { T t; cin >> t; return t; }
template <class T> vector<T> read(int n) { vector<T> v; REP(i, n) { v.push_back(read<T>()); } return v; }
template <class T> vevector<T> read(int n, int m) { vevector<T> v; REP(i, n) v.push_back(read<T>(m)); return v; }
template <class T> vector<T> readjag() { return read<T>(read<int>()); }
template <class T> vevector<T> readjag(int n) { vevector<T> v; REP(i, n) v.push_back(readjag<T>()); return v; }

template <class T> inline ostream & operator << (ostream &out, const vector<T> &v)
{
	ostringstream ss;
	for (auto x : v) ss << x << ' ';
	auto s = ss.str();
	out << s.substr(0, s.length() - 1);
	return out;
}

struct _Reader { template <class T> _Reader operator ,(T &rhs) { cin >> rhs; return *this; } };
struct _Writer { bool f; _Writer() : f(false) { } template <class T> _Writer operator ,(const T &rhs) { cout << (f ? " " : "") << rhs; f = true; return *this; } };
#define READ(t,...) t __VA_ARGS__; _Reader(), __VA_ARGS__
#define WRITE(...) _Writer(), __VA_ARGS__; cout << endl
#ifdef _DEBUG
#define DEBUG WRITE
#endif
//// start up ////
void solve();
int main()
{
	solve();
	return 0;
}

bool match(const string &s, int x)
{
	REP(i, s.size())
	{
		if (s[s.size() - (i + 1)] != '?' && s[s.size() - (i + 1)] - '0' != x % 10) { return false; }
		x = x / 10;
	}
	return true;
}

void serch(const char *fmt, string C, string J, int mv)
{
	int mx = 0; int my = 0; int dif = INF;
	REP(x, mv)
	{
		if (!match(C, x))
		{
			continue;
		}
		REP(y, mv)
		{
			if (!match(J, y)) {
				continue;
			}

			if (abs(x - y) < dif)
			{
				dif = abs(x - y);
				mx = x;
				my = y;
			}
		}
	}
	printf(fmt, mx, my);
}


void solve()
{
	READ(int, testcases);
	REP(testcase, testcases)
	{
		printf("Case #%d: ", testcase + 1);

		int rx = 0, ry = 0;
		READ(string, C, J);
		switch (C.size())
		{
		case 1: serch("%01d %01d\n", C, J, 10); break;
		case 2: serch("%02d %02d\n", C, J, 100); break;
		case 3: serch("%03d %03d\n", C, J, 1000); break;
		}
	}


}
