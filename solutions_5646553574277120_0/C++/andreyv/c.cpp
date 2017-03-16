//#define PROB ""        //{{{ Preamble
#define IN   (*PROB ? PROB ".in"  : "input.txt" )
#define OUT  (*PROB ? PROB ".out" : "output.txt")
#ifndef LOCAL_PC
#define NDEBUG
#define LOG(...) static_cast<void>(0)
#else
#include <local>
#endif
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)
#include <forward_list>
#include <future>
#include <regex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std; typedef long long ll; typedef unsigned long long ull;
const double pi=3.14159265358979323846; const double E=2.7182818284590452354;
const struct __ { ios_base::Init i; int s; __() : s(ios_base::xalloc()) {
    srand(time(NULL)); ios_base::sync_with_stdio(false); cin.tie(NULL); } } _;
#if defined(PROB) && !defined(LOCAL_PC)
const struct $ { filebuf a,b; ~$(){ cin.rdbuf(NULL); cout.rdbuf(NULL); }
    $(){ cin.rdbuf(a.open(IN,ios::in)); cout.rdbuf(b.open(OUT,ios::out)); } }$;
#endif
inline ostream& operator<<(ostream&o,const __&){o.iword(_.s)=0;return o<<'\n';}
#define endl _
template<class T> inline ostream& operator,(ostream&o, const T& x) {
    if (o.iword(_.s)) o << ' '; else o.iword(_.s)=1; return o << x; }
template<> inline ostream& operator,<__>(ostream&o, const __&){return o<<endl;}
template<class I> inline void in(I A, I B) { while (A!=B) { cin >> *A; ++A; } }
template<class I> inline void out(I A, I B, char D=' ') { if (A!=B) {
    cout << *A; while (++A!=B) { cout << D << *A; } } cout << endl; }
template<class T> inline T sq(const T& X) { return X*X; }
template<class T> inline T power(T X, int Y) { assert(Y>=0 && !(X==0 && Y==0));
    T R=(Y&1)?X:1; while (Y >>= 1) { X *= X; if (Y&1) R *= X; } return R; }
#define pb(...)      push_back(__VA_ARGS__)
#define eb(...)      emplace_back(__VA_ARGS__)
#define sz(v)        static_cast<int>((v).size())
#define X            first
#define Y            second
#define FOREACH(i,c) for(__typeof__((c).begin())i=(c).begin();i!=(c).end();++i)
#define mp(x, y)     make_pair((x), (y))
#define mt(...)      make_tuple(__VA_ARGS__)
#define ass(e)       assert(e)
//}}}//////////////////////////////////////////////////////////////////////////

int main()
{
    int T; cin >> T;

    vector<int> nums;

    for (int t = 1; t <= T; t++)
    {
        int c, d, v; cin >> c >> d >> v;
        nums.resize(d);
        in(nums.begin(), nums.end());

        int res = 0;
        while (true)
        {
            bool arr[35] = { false };

            for (int m = 1; m < 1<<sz(nums); m++)
            {
                int z = 0;
                for (int i = 0; i < sz(nums); i++)
                {
                    if (m&(1<<i))
                    {
                        z += nums[i];
                    }
                }
                if (z <= v)
                {
                    arr[z] = true;
                }
            }

            int ok = true;
            for (int i = 1; i <= v; i++)
            {
                if (!arr[i])
                {
                    nums.pb(i);
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                break;
            }
            res++;
        }
        cout << "Case #" << t << ": " << res << endl;
    }
}
