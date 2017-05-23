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
	string _task = "A";
	string _in = _task + "-small.in", _out = _task + "-small.out";
	//string _in = _task + "-large.in", _out = _task + "-large.out";
	ifstream fin(_in.c_str());
	ofstream fout(_out.c_str());

	map<char, char> tr;
	tr['a'] = 'y';
	tr['o'] = 'e';
	tr['z'] = 'q';
	vs s, q;
	s.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
	q.push_back("our language is impossible to understand");
	s.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
	q.push_back("there are twenty six factorial possibilities");
	s.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");
	q.push_back("so it is okay if you want to just give up");
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < sz(s[i]); ++j)
			tr[s[i][j]] = q[i][j];

	tr['q'] = 'z';
	string ts;
	getline(fin, ts);
	int _N = atoi(ts.c_str());

	for (int _n = 1; _n <= _N; ++_n)
	{	
		string s;
		getline(fin, s);

		string res;
		for (int i = 0; i < sz(s); ++i)
			res.push_back(tr[s[i]]);

		fout << "Case #" << _n << ": ";
		fout << res;
		fout << endl;
	}	

	return 0;
}