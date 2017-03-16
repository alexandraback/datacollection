#include <vector>
#include <string>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define vs vector<string>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define vd vector<double>
#define vvd vector<vd>
#define vp vector<pii>
#define vvp vector<vp>
#define msi map<string, int>
#define mii map<int, int>

#define sqr(a) ((a) * (a))
#define two(n) (1 << (n))
#define twoLL(n) (1LL << (n))
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()

inline ll pow(int a, int b) { ll res = 1; for (int i = 1; i <= b; ++i) res *= a; return res; }
template<typename T> inline vector<T> split(string const & str, string const & delim = "") { string s = str; for (size_t i = 0; i < delim.size(); ++i) replace(s.begin(), s.end(), delim[i], ' '); vector<T> res; istringstream iss(s); T t; while (iss >> t) res.push_back(t); return res; }
template<typename R, typename T> inline R cast(T const & t) { stringstream ss; ss << t; R r; ss >> r; return r; }
template<typename TContainer> inline TContainer rev(TContainer const & c) { TContainer cont = c; reverse(all(cont)); return cont; }

#define inf 2100000000
#define eps 1e-9

ll mmin(ll x, ll y)
{
	if (x < y)
		return x;
	else
		return y;
}

string toString(ll x)
{
	string r;
	while (x)
	{
		r += x % 10 + '0';
		x /= 10;
	}

	if (r.empty())
		r = "0";

	return rev(r);
}

ll toLL(string const & x)
{
	string s = rev(x);
	ll res = 0;
	ll dec = 1;
	for (int i = 0; i < sz(s); ++i, dec *= 10)
	{
		res += (s[i] - '0') * dec;
	}
	return res;
}

map<ll, ll> memo;

ll solve1(ll n)
{
	ll & res = memo[n];

	if (res != 0)
		return res;

	if (n <= 10)
		return res = n;

	res = n;
	for (ll i = 0; i < n; ++i)
	{
		if (i > res)
			break;

		ll x = n - i;
		string rs = rev(toString(x));
		if (rs[0] == '0')
			continue;

		ll y = toLL(rs);
		
		if (y < x)
			res = mmin(res, i + 1 + solve1(y));
	}

	return res;
}

ll solve(ll n)
{
	if (n <= 10)
		return n;

	string s = toString(n);

	int x = sz(s) / 2;
	string s1 = s.substr(0, x) + string((sz(s) + 1) / 2, '0');

	if (s == s1)
		return 1 + solve(n - 1);

	ll m = toLL(s1) + 1;

	string t = rev(toString(m));

	ll o = toLL(t);

	string s2 = string(sz(s) - 1, '9');
	ll p = toLL(s2);

	if (o == m)
		return n - p + solve(p);

	return n - m + 1 + o - p + solve(p);
}

int main()
{
	string _task = "A";
	string _in = _task + "-small.in", _out = _task + "-small.out";
	//string _in = _task + "-large.in", _out = _task + "-large.out";
	ifstream fin(_in.c_str());
	ofstream fout(_out.c_str());

	string ts;
	getline(fin, ts);
	int _N = atoi(ts.c_str());

	for (int _n = 1; _n <= _N; ++_n)
	{
		// don't forget to clear all global objects!

		getline(fin, ts);
		ll n = cast<ll>(ts);

		//ll res = (n < 1000) ? solve1(n) : 0;
		ll res = solve(n);
		
		fout << "Case #" << _n << ": ";
		fout << res;
		fout << endl;
	}	

	return 0;
}
