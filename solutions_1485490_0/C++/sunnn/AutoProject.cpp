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
#define pii pair<ll, ll>
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

inline ll abs(ll a) { return (a < 0) ? -a : a; }
inline ll pow(int a, int b) { ll res = 1; for (int i = 1; i <= b; ++i) res *= a; return res; }
template<typename T> inline vector<T> split(string const & str, string const & delim = "") { string s = str; for (size_t i = 0; i < delim.size(); ++i) replace(s.begin(), s.end(), delim[i], ' '); vector<T> res; istringstream iss(s); T t; while (iss >> t) res.push_back(t); return res; }
template<typename R, typename T> inline R cast(T const & t) { stringstream ss; ss << t; R r; ss >> r; return r; }

#define inf 2100000000
#define eps 1e-9

ll solve(vp const & a, vp const & b, int ind1, ll x1, int ind2, ll x2, ll cur)
{
	int n = sz(a), m = sz(b);
	if (ind1 >= n || ind2 >= m)
		return cur;

	int i = ind2;
	while (i < m && a[ind1].second != b[i].second)
	{
		x2 = 0;
		++i;
	}

	if (i == m)
		return cur;

	if (a[ind1].first - x1 < b[i].first - x2)
	{
		ll r = cur + a[ind1].first - x1;
		return max(
			solve(a, b, ind1 + 1, 0, i, x2 + a[ind1].first - x1, r),
			solve(a, b, ind1 + 2, 0, i, x2 + a[ind1].first - x1, r)
			);
	}
	else if (a[ind1].first - x1 == b[i].first - x2)
	{
		return max(
			solve(a, b, ind1 + 1, 0, i + 1, 0, cur + a[ind1].first - x1),
			solve(a, b, ind1 + 2, 0, i + 1, 0, cur + a[ind1].first - x1)
			);
	}
	else
	{
		ll r = cur + b[i].first - x2;
		return max(
			solve(a, b, ind1, x1 + b[i].first - x2, i + 1, 0, r),
			max(
				solve(a, b, ind1 + 1, 0, i + 1, 0, r),
				solve(a, b, ind1 + 2, 0, i + 1, 0, r)
				)
			);
	}
}

int main()
{
	string _task = "C";
	string _in = _task + "-small.in", _out = _task + "-small.out";
	//string _in = _task + "-large.in", _out = _task + "-large.out";
	ifstream fin(_in.c_str());
	ofstream fout(_out.c_str());

	string ts;
	getline(fin, ts);
	int _N = atoi(ts.c_str());

	for (int _n = 1; _n <= _N; ++_n)
	{
		getline(fin, ts);
		vl t = split<ll>(ts);
		int n = (int)t[0], m = (int)t[1];
		
		vp a, b;
		getline(fin, ts);
		t = split<ll>(ts);
		for (int i = 0; i < n; ++i)
			a.push_back(pii(t[2 * i], t[2 * i + 1]));
		
		getline(fin, ts);
		t = split<ll>(ts);
		for (int i = 0; i < m; ++i)
			b.push_back(pii(t[2 * i], t[2 * i + 1]));

		fout << "Case #" << _n << ": ";
		
		ll res = 0;
		for (int i = 0; i < n; ++i)
		{
			ll r = solve(a, b, i, 0, 0, 0, 0);
			res = max(res, r);
		}
		fout << res;

		fout << endl;
	}	

	return 0;
}
