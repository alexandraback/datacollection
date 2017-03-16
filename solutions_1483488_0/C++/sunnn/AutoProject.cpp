#include <vector>
#include <string>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <hash_set>
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
using namespace stdext;

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
		vi t = split<int>(ts);
		int a = t[0], b = t[1];
		
		int res = 0;
		vi dig;
		dig.reserve(7);
		for (int x = a; x <= b; ++x)
		{
			dig.clear();
			int z = x;
			while (z != 0)
			{
				dig.push_back(z % 10);
				z /= 10;
			}
			reverse(all(dig));
			set<int> was;
			for (int i = 0; i < sz(dig) - 1; ++i)
			{
				rotate(dig.begin(), dig.begin() + 1, dig.end());
				if (dig[0] == 0)
					continue;

				int y = 0;
				int ten = 10;
				for (int j = 0; j < sz(dig); ++j)
					y = y * ten + dig[j];
				if (was.count(y) != 0)
					continue;
				if (x < y && y >= a && y <= b)
					++res, was.insert(y);
			}
		}

		fout << "Case #" << _n << ": ";
		fout << res;
		fout << endl;
	}	

	return 0;
}
