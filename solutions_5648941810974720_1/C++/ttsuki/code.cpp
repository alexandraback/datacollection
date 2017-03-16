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

void solve()
{
	READ(int, testcases);
	REP(testcase, testcases)
	{
		printf("Case #%d: ", testcase + 1);

		READ(string, S);
		vector<int> tbl = vector<int>(256);
		REP(i, S.size()) { tbl[S[i]]++; }

		// Z0W2X6G8T3S7V5I9N1R4
		vector<int> ret = vector<int>(10);
		while (tbl['Z']) { tbl['Z']--; tbl['E']--; tbl['R']--; tbl['O']--; ret[0]++; }
		while (tbl['W']) { tbl['T']--; tbl['W']--; tbl['O']--; ret[2]++; }
		while (tbl['X']) { tbl['S']--; tbl['I']--; tbl['X']--; ret[6]++; }
		while (tbl['G']) { tbl['E']--; tbl['I']--; tbl['G']--; tbl['H']--; tbl['T']--; ret[8]++; }
		while (tbl['T']) { tbl['T']--; tbl['H']--; tbl['R']--; tbl['E']--; tbl['E']--; ret[3]++; }
		while (tbl['S']) { tbl['S']--; tbl['E']--; tbl['V']--; tbl['E']--; tbl['N']--; ret[7]++; }
		while (tbl['V']) { tbl['F']--; tbl['I']--; tbl['V']--; tbl['E']--; ret[5]++; }
		while (tbl['I']) { tbl['N']--; tbl['I']--; tbl['N']--; tbl['E']--;  ret[9]++; }
		while (tbl['N']) { tbl['O']--; tbl['N']--; tbl['E']--; ret[1]++; }
		while (tbl['R']) { tbl['F']--; tbl['O']--; tbl['U']--; tbl['R']--; ret[4]++; }

		REP(i, 10) REP(j, ret[i]) { printf("%d", i); }
		printf("\n");
	}


}
