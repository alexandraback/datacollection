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

inline ll abs(ll a) { return (a < 0) ? -a : a; }
inline ll pow(int a, int b) { ll res = 1; for (int i = 1; i <= b; ++i) res *= a; return res; }
template<typename T> inline vector<T> split(string const & str, string const & delim = "") { string s = str; for (size_t i = 0; i < delim.size(); ++i) replace(s.begin(), s.end(), delim[i], ' '); vector<T> res; istringstream iss(s); T t; while (iss >> t) res.push_back(t); return res; }
template<typename R, typename T> inline R cast(T const & t) { stringstream ss; ss << t; R r; ss >> r; return r; }

#define inf 2100000000
#define eps 1e-9

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
		vd t = split<double>(ts);
		
		double D = t[0];
		int n = (int)t[1], A = (int)t[2];

		vector<pair<double, double> > c;
		for (int i = 0; i < n; ++i)
		{
			getline(fin, ts);
			vd t = split<double>(ts);
			c.push_back(pair<double, double>(t[0], t[1]));
		}

		getline(fin, ts);
		vd a = split<double>(ts);
		assert(sz(a) == A);

		vd res(A);
		if (n == 1 && c[0].second >= D)
		{
			for (int i = 0; i < A; ++i)
				res[i] = sqrt(2 * D / a[i]);
		}
		else
		{
			double v = (c[1].second - c[0].second) / (c[1].first - c[0].first);
			double r = (D - c[0].second) / v + c[0].first;
			for (int i = 0; i < A; ++i)
				res[i] = max(sqrt(2 * D / a[i]), r);
		}

		fout << "Case #" << _n << ": " << endl;
		for (int i = 0; i < A; ++i)
			fout << fixed << setprecision(9) << res[i] << endl;
	}	

	return 0;
}
