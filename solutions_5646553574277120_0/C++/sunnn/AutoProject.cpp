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

template<typename T> inline bool btest(T num, int bit) { return (num & ((T)1 << bit)) != 0; }
template<typename T> inline int bcount(T num) { int res = 0; while (num != 0) { ++res; num &= num - 1; } return res; }
template<typename T> inline T bset(T num, int bit) { return num | ((T)1 << bit); }
template<typename T> inline T breset(T num, int bit) { return num & ~((T)1 << bit); }
template<typename T> inline T blower(T num) { return num & -num; }
template<typename T> inline T bsubset(T num, T prev) { return (prev - 1) & num; } // initial prev = num
template<typename T> inline T bsubset_up(T num, T prev) { return (prev == 0) ? blower(num) : ((prev | ~num) + 1) & num; } // initial prev = 0

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

		int C = t[0], D = t[1], V = t[2];

		getline(fin, ts);
		vi a = split<int>(ts);
		assert(sz(a) == D);

		//vi b(V + 1, 0);

		//for (int i = 0; i < sz(a); ++i)
		//{
		//	vi c = b;
		//	c[a[i]] = 1;
		//	for (int j = 1; j + a[i] <= V; ++j)
		//	{
		//		if (b[j] == 1)
		//			c[j + a[i]] = 1;
		//	}
		//	b = c;
		//}


		int stMask = 0;
		for (int i = 0; i < sz(a); ++i)
			stMask = bset(stMask, a[i] - 1);

		int res = inf;
		for (int m = 0; m < two(V); ++m)
		{
			if ((m & stMask) != stMask)
				continue;

			if (bcount(m) > D + res)
				continue;

			int chMask = 0;
			for (int i = 0; i < V; ++i)
			{
				if (!btest(m, i))
					continue;

				int x = i + 1;
				int nextMask = chMask;
				nextMask = bset(nextMask, i);
				for (int j = 1; j + x <= V; ++j)
				{
					if (btest(chMask, j - 1))
						nextMask = bset(nextMask, j + x - 1);
				}
				chMask = nextMask;
			}

			if (bcount(chMask) == V)
				res = min(res, bcount(m) - D);
		}
		
		fout << "Case #" << _n << ": ";
		fout << res;
		fout << endl;
	}	

	return 0;
}
