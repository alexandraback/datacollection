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

void solve(string s, string & res1, string & res2, int & diff)
{
	for (int i = 0; i < sz(s); ++i)
	{
		if (s[i] == '?')
		{
			for (int j = 0; j <= 9; ++j)
			{
				s[i] = j + '0';
				solve(s, res1, res2, diff);
				s[i] = '?';
			}
			return;
		}
	}

	vs ts = split<string>(s);

	vi t = split<int>(s);
	if (abs(t[0] - t[1]) < diff)
	{
		res1 = ts[0];
		res2 = ts[1];
		diff = abs(t[0] - t[1]);
	}
	else if (abs(t[0] - t[1]) == diff)
	{
		if (ts[0] < res1)
		{
			res1 = ts[0];
			res2 = ts[1];
		}
		else if (ts[0] == res1 && ts[1] < res2)
		{
			res2 = ts[1];
		}
	}
}

void fill(string & s, char c)
{
	replace(s.begin(), s.end(), '?', c);
}

inline bool LongNumberLess(string const & x, string const & y)
{
	return (sz(x) < sz(y)) ? true : ((sz(x) > sz(y)) ? false : x < y);
}

string dif(string s1, string s2)
{
	vi res(20, '0');
	if (LongNumberLess(s1, s2))
		swap(s1, s2);

	//string d = to_string(stoll(s1) - stoll(s2));
	//return string(20 - sz(d), '0') + d;

	vi a1(20), a2(20);
	reverse(all(s1));
	reverse(all(s2));

	for (int i = 0; i < sz(s1); ++i)
	{
		a1[i] = s1[i] - '0';
		a2[i] = s2[i] - '0';
	}

	int n = 20;
	for (int i = 0; i < n; ++i)
	{
		if (a1[i] < a2[i])
		{
			a1[i] += 10;
			a1[i + 1]--;
		}
		res[i] = a1[i] - a2[i];
	}

	string r(20, '0');
	for (int i = 0; i < n; ++i)
	{
		assert(res[i] <= 9 && res[i] >= 0);
		r[i] = res[i] + '0';
	}
	reverse(all(r));
	return r;
}

void solve1(string s1, string s2, string & res1, string & res2, string & diff)
{
	for (int i = 0; i < sz(s1); ++i)
	{
		if (s1[i] == '?' && s2[i] == '?')
		{
			s1[i] = '0';
			s2[i] = '0';
			solve1(s1, s2, res1, res2, diff);
			s1[i] = '0';
			s2[i] = '1';
			solve1(s1, s2, res1, res2, diff);
			s1[i] = '1';
			s2[i] = '0';
			solve1(s1, s2, res1, res2, diff);
			return;
		}
		else if (s1[i] == '?')
		{
			s1[i] = s2[i];
			solve1(s1, s2, res1, res2, diff);
			if (s2[i] > '0')
			{
				s1[i] = s2[i] - 1;
				solve1(s1, s2, res1, res2, diff);
			}
			if (s2[i] < '9')
			{
				s1[i] = s2[i] + 1;
				solve1(s1, s2, res1, res2, diff);
			}
			return;
		}
		else if (s2[i] == '?')
		{
			s2[i] = s1[i];
			solve1(s1, s2, res1, res2, diff);
			if (s1[i] > '0')
			{
				s2[i] = s1[i] - 1;
				solve1(s1, s2, res1, res2, diff);
			}
			if (s1[i] < '9')
			{
				s2[i] = s1[i] + 1;
				solve1(s1, s2, res1, res2, diff);
			}
			return;
		}
		else
		{
			if (s1[i] != s2[i])
			{
				if (s1[i] < s2[i])
				{
					fill(s1, '9');
					fill(s2, '0');
				}
				else
				{
					fill(s1, '0');
					fill(s2, '9');
				}
				string d = dif(s1, s2);
				if (LongNumberLess(d, diff))
				{
					res1 = s1;
					res2 = s2;
					diff = d;
				}
				else if (d == diff)
				{
					if (s1 < res1)
					{
						res1 = s1;
						res2 = s2;
					}
					else if (s1 == res1 && s2 < res2)
					{
						res2 = s2;
					}
				}
				return;
			}
		}
	}

	string d = dif(s1, s2);
	if (LongNumberLess(d, diff))
	{
		res1 = s1;
		res2 = s2;
		diff = d;
	}
	else if (d == diff)
	{
		if (s1 < res1)
		{
			res1 = s1;
			res2 = s2;
		}
		else if (s1 == res1 && s2 < res2)
		{
			res2 = s2;
		}
	}
}

int main()
{
	string _task = "B";
	//string _in = _task + "-small.in", _out = _task + "-small.out";
	string _in = _task + "-large.in", _out = _task + "-large.out";
	ifstream fin(_in.c_str());
	ofstream fout(_out.c_str());

	string ts;
	getline(fin, ts);
	int _N = atoi(ts.c_str());

	for (int _n = 1; _n <= _N; ++_n)
	{
		// don't forget to clear all global objects!

		//getline(fin, ts);
		//int n = atoi(ts.c_str());

		getline(fin, ts);
		vs s = split<string>(ts);

		string diff(20, '9');
		string res1, res2;
		solve1(s[0], s[1], res1, res2, diff);
		
		fout << "Case #" << _n << ": ";
		fout << res1 << ' ' << res2;
		fout << endl;
	}	

	return 0;
}
