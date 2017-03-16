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

inline bool isvowel(char ch) { ch = (char)tolower(ch); return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; }
inline bool iscons(char ch) { return isalpha(ch) && !isvowel(ch); }

struct attack
{
	int w, e, s;
	int day;

	attack(int w, int e, int s, int day) : w(w), e(e), s(s), day(day) {}

	bool operator < (attack const & a) const
	{
		return day < a.day;
	}
};



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
		int N = cast<int>(ts);

		vector<attack> at;
		for (int i = 0; i < N; ++i)
		{
			getline(fin, ts);
			vi t = split<int>(ts);
			int day = t[0];
			int n = t[1];
			int w = 2 * t[2], e = 2 * t[3], s = t[4], delDay = t[5], delP = 2 * t[6], delS = t[7];
			
			for (int j = 0; j < n; ++j)
			{
				at.push_back(attack(w, e, s, day));
				w += delP, e += delP;
				s += delS;
				day += delDay;
			}
		}
		
		sort(all(at));
		map<int, int> wall;
		map<int, int> gr;

		int day = 0;
		int res = 0;
		int i = 0;
		while (day <= 676080)
		{
			gr.clear();
			bool ok = false;
			while (i < sz(at) && at[i].day == day)
			{
				ok = true;
				bool succeed = false;
				for (int j = at[i].w; j <= at[i].e; ++j)
				{
					if (at[i].s > wall[j])
					{
						succeed = true;
						gr[j] = max(gr[j], at[i].s);
					}
				}
				if (succeed)
					++res;
				++i;
			}
			if (!ok)
			{
				++day;
				continue;
			}

			for (auto it = gr.begin(); it != gr.end(); ++it)
			{
				wall[it->first] = it->second;
			}
			++day;
		}
		
		fout << "Case #" << _n << ": ";
		fout << res;
		fout << endl;
	}	

	return 0;
}
