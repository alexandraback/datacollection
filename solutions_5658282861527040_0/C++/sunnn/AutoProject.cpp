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

template<typename T> inline bool btest(T num, int bit) { return (num & ((T)1 << bit)) != 0; }
template<typename T> inline int bcount(T num) { int res = 0; while (num != 0) { ++res; num &= num - 1; } return res; }
template<typename T> inline T bset(T num, int bit) { return num | ((T)1 << bit); }
template<typename T> inline T breset(T num, int bit) { return num & ~((T)1 << bit); }

#define inf 2100000000
#define eps 1e-9

string & flip(string & s, int mask)
{
	for (int i = 0; i < sz(s); ++i)
	{
		if (btest(mask, i))
		{
			if (s[i] == '0')
				s[i] = '1';
			else
				s[i] = '0';
		}
	}
	return s;
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
		int A = t[0], B = t[1], K = t[2];

		vi res;
		for (int a = 0; a < A; ++a)
			for (int b = 0; b < B; ++b)
			{
				res.push_back(a & b);
			}

		int r = 0;
		for (int i = 0; i < sz(res); ++i)
			if (res[i] < K)
				++r;

		fout << "Case #" << _n << ": ";
		fout << r;
		fout << endl;
	}	

	return 0;
}
