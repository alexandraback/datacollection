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

template<typename T> inline bool btest(T num, int bit) { return (num & ((T)1 << bit)) != 0; }

inline ll getDivisor(ll num)
{
	for (ll i = 2; i * i <= num; ++i)
		if (num % i == 0)
			return i;

	return 0;
}

template<typename T>
inline string binary(T num, int len)
{
	string res;
	do
	{
		res += char('0' + num % 2);
		num /= 2;
	} while (num != 0);

	while (sz(res) < len)
		res += '0';
	return rev(res);
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
		// don't forget to clear all global objects!

		getline(fin, ts);
		vi t = split<int>(ts);

		int n = t[0], J = t[1];

		fout << "Case #" << _n << ":" << endl;

		vector<ll> div;
		for (int m = 0; m < two(n - 2) && J > 0; ++m)
		{
			div.clear();
			for (int b = 2; b <= 10; ++b)
			{
				ll x = 1;

				ll p = b;
				for (int j = 0; j < n - 2; ++j, p *= b)
					if (btest(m, j))
						x += p;

				x += p;

				ll y = getDivisor(x);
				if (y == 0)
					break;

				div.emplace_back(y);
			}
			if (div.size() != 9)
				continue;

			fout << '1' << binary(m, n - 2) << "1 ";
			for (auto d : div)
				fout << d << ' ';
			fout << endl;

			--J;
		}
	}	

	return 0;
}
