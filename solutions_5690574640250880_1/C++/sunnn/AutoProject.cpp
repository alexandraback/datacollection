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
inline string dtos(ld num, int prec) { ostringstream oss; oss << setprecision(prec) << fixed << num; return oss.str(); }

#define inf 2100000000
#define eps 1e-9

vs transpose(vs const & b)
{
	if (b.empty() || sz(b) == sz(b[0]))
		return b;

	vs res(sz(b[0]), string(sz(b), '.'));
	for (int i = 0; i < sz(b); ++i)
		for (int j = 0; j < sz(b[0]); ++j)
			res[j][i] = b[i][j];

	return res;
}

void addMineColumns(vs & b, int n)
{
	for (auto & r : b)
		r.resize(r.size() + n, '*');
}

void checkAndPrintBoard(ofstream & fout, vs const & b, int n, int m, int x)
{
	assert(n == sz(b) && m == sz(b[0]));
	int c = 0;
	for (int i = 0; i < sz(b); ++i)
	{
		c += count(all(b[i]), '*');
		fout << b[i] << endl;
	}
	assert(c == x);
}

vs solve(int n, int m, int x)
{
	if (x == 0)
	{
		vs res(n, string(m, '.'));
		res[0][0] = 'c';
		return res;
	}
	else if (n == 1 || m == 1)
	{
		int p = max(n, m);
		vs res(1, string(p, '.'));
		res[0][p - 1] = 'c';
		for (int i = 0; i < x; ++i)
			res[0][i] = '*';
		reverse(all(res[0]));

		if (n == p)
			res = transpose(res);

		return res;
	}
	else if (x == n * m - 1)
	{
		vs res(n, string(m, '*'));
		res[0][0] = 'c';
		return res;
	}
	else if (x == n * m - 2 || x == n * m - 3)
	{
		return vs();
	}
	else if (n == 2 || m == 2)
	{
		if (x % 2 == 1)
			return vs();

		int p = max(n, m);

		vs res(2, string(p, '.'));
		res[0][p - 1] = 'c';
		for (int i = 0; i < x; ++i)
			res[i % 2][i / 2] = '*';

		reverse(all(res[0]));
		reverse(all(res[1]));

		if (n == p)
			res = transpose(res);

		return res;
	}
	else 
	{
		for (int dim = 3; dim <= 50; ++dim)
		{
			if (n != dim && m != dim)
				continue;

			int p = max(n, m);

			vs res(dim, string(p, '.'));

			if (x / dim != 0)
			{
				res = solve(dim, p - 1, x - dim);
				addMineColumns(res, 1);
			}
			else
			{
				res[0][0] = 'c';
				for (int k = dim - 1, mines = 0; k >= 2 && mines < x; --k, ++mines)
				{
					res[k][p - 1] = '*';
				}

				if (x == dim - 1)
				{
					if (p == 3)
						return vs();

					res[dim - 1][p - 2] = '*';
				}
			}

			if (n == p)
				res = transpose(res);

			return res;
		}
	}

	assert(false);
	return vs();
}

int main()
{
	string _task = "C";
	//string _in = _task + "-small.in", _out = _task + "-small.out";
	string _in = _task + "-large.in", _out = _task + "-large.out";
	ifstream fin(_in.c_str());
	ofstream fout(_out.c_str());

	string ts;
	getline(fin, ts);
	int _N = atoi(ts.c_str());

	for (int _n = 1; _n <= _N; ++_n)
	{
		getline(fin, ts);
		vi p = split<int>(ts);

		int n = p[0], m = p[1], x = p[2];

		fout << "Case #" << _n << ":\n";

		vs res = solve(n, m, x);
		if (res.empty())
			fout << "Impossible\n";
		else
			checkAndPrintBoard(fout, res, n, m, x);
	}	

	return 0;
}
