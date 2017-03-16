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

#define inf 2100000000
#define eps 1e-9

pair<int, double> gen(int S, map<char, int> & dict, int n, string const & tar, string & cur)
{
	if (S == 0)
	{
		int r = 0;
		int p = 0;
		while (p != -1)
		{
			p = cur.find(tar, p);
			if (p != -1)
			{
				++r;
				++p;
			}
		}

		double exp = 1.0;
		for (int i = 0; i < sz(cur); ++i)
		{
			int ch = dict[cur[i]];
			exp *= ch * 1.0 / n;
		}
		return make_pair(r, r * exp);
	}

	int res = 0;
	double exp = 0;
	cur += '0';
	for (auto const & d : dict)
	{
		cur.back() = d.first;
		auto x = gen(S - 1, dict, n, tar, cur);
		res = max(res, x.first);
		exp += x.second;
	}
	cur.erase(sz(cur) - 1);
	return make_pair(res, exp);
}

int main()
{
	string _task = "B";
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
		vi t = split<int>(ts);

		int n = t[0], m = t[1], S = t[2];

		string a;
		getline(fin, a);
		assert(sz(a) == n);

		string tar;
		getline(fin, tar);
		assert(sz(tar) == m);

		map<char, int> dict;
		for (int i = 0; i < n; ++i)
		{
			++dict[a[i]];
		}

		string cur;
		auto x = gen(S, dict, n, tar, cur);


		double res = x.first - x.second;
		
		fout << "Case #" << _n << ": ";
		fout << setprecision(9) << fixed << res;
		fout << endl;
	}	

	return 0;
}
