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

inline bool btest(ll num, int bit) { return (num & (1LL << bit)) != 0; }
inline int bcount(ll num) { int res = 0; while (num != 0) { ++res; num &= num - 1; } return res; }
inline int bset(int num, int bit) { return num | (1 << bit); }
inline int breset(int num, int bit) { return num & ~(1 << bit); }
inline int bsubset(int num, int prev) { return (prev == 0) ? num & -num : ((prev | ~num) + 1) & num; }
inline ll bsetLL(ll num, int bit) { return num | (1LL << bit); }
inline ll bresetLL(ll num, int bit) { return num & ~(1LL << bit); }
inline ll bsubsetLL(ll num, ll prev) { return (prev == 0) ? num & -num : ((prev | ~num) + 1) & num; }

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
        assert(t[0] == sz(t) - 1);
        int n = t[0];
        t.erase(t.begin());

        bool ok = false;
        map<int, int> m;
        for (int i = 0; i < two(n); ++i)
        {
            int s1 = 0, s2 = 0;
            for (int j = 0; j < n; ++j)
                if (btest(i, j))
                    s1 += t[j];

            
            
            if (m.count(s1))
            {

                fout << "Case #" << _n << ": " << endl;

                string st1, st2;
                for (int j = 0; j < n; ++j) {
                    if (btest(m[s1], j))
                        st1 += cast<string>(t[j]) + ' ';
                    if (btest(i, j))
                        st2 += cast<string>(t[j]) + ' ';
                }
                fout << st1.substr(0, st1.size() - 1);
                fout << endl;
                fout << st2.substr(0, st2.size() - 1);
                fout << endl;
                ok = true;
                break;
            }
            m[s1] = i;
        }
    
        if (!ok) {
		fout << "Case #" << _n << ": ";
        fout << endl;		
		fout << "Impossible";

		fout << endl;
        }
	}	

	return 0;
}
