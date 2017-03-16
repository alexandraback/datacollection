#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <set>
#include <ctime>
#include <stack>
#include <cstring>
#include <sstream>
#include <ctype.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#pragma comment(linker, "/STACK:16777216")
template<typename T> T fac(T a){ return a ? a*fac(a-1) : 1; }
template<typename T> T power(T a, int p){ return !p?1:(p&1?a*power(a, p-1):power(a*a,p>>1)); }
template<typename T> T gcd(T a, T b){ return b ? gcd(b, a%b) : a; }
template<typename T> T lcm(T a, T b){ return b / gcd(a, b) * a; }
template<typename T> T next(){ T _; cin >> _; return _; }
template<> int next<int>(){int _; scanf("%d", &_); return _; }
template<> double next<double>(){ double _; scanf("%lf", &_); return _; }
template<> ll next<ll>(){ ll _; scanf("%I64d", &_); return _; }
template<typename E> vector<E> next(int n){ vector<E> res(n); for(int i = 0; i < n; i++) res[i] = next<E>(); return res;}
template<class C, class E> int count(const C &c, const E &e){return count(c.begin(), c.end(), e);}
template<class E> bool has(const vector<E> &c, const E &e){return find(c.begin(), c.end(), e) != c.end();}
template<class E> int find(const vector<E> &c, const E &e){return find(c.begin(), c.end(), e) - c.begin();}
template<class E> bool binary_has(const vector<E> &c, const E &e){return binary_search(c.begin(), c.end(), e);}
template<class E> int binary_find(const vector<E> &c, const E &e){return lower_bound(c.begin(), c.end(), e) - c.begin();}
template<typename T> T dist2(T i1, T j1, T i2, T j2){return (i1-i2)*(i1-i2) + (j1-j2)*(j1-j2);}
bool ok(int i, int j, int n, int m){return 0<=i&&i<n&&0<=j&&j<m;}
const double EPS = 1e-9;
bool LE(double a, double b){return b-a > -EPS;}
bool BE(double a, double b){return a-b > -EPS;}
bool EQ(double a, double b){return fabs(a-b) < EPS;}
bool LESS(double a, double b){return b-a > EPS;}
bool BIGG(double a, double b){return a-b > EPS;}
template <int N, typename T> class lug {public: T at[N];};

vector<vector<int> > v;
vector<int> used;
int solve(int a)
{
    if(a+1 == v.size())
        return 1;
    used[a] = 1;
    
    int res = 0;
    for(int i = 0; i < v[a].size(); i++)
        if(v[a][i])
            res += solve(i);
    
    used[a] = 0;
    
    return res;
}

int main()
{
    freopen("/Users/ibra/Desktop/in.txt", "r", stdin);
    freopen("/Users/ibra/Desktop/out.txt", "w", stdout);
    
    int t = next<int>();
    for(int test = 1; test <= t; test++)
    {
        int n = next<int>();
        int m = next<int>();
        int g = (n*n-n)/2;
        used = vector<int> (n);
        
        vector<pair<int, int> > ids;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                ids.push_back({i, j});
        
        vector<vector<int> > res;
        bool ok = false;
        for(int mask = 0; mask < (1<<g); mask++)
        {
            v = vector<vector<int> > (n, vector<int> (n));
            for(int i = 0; i < g; i++)
                if(mask&(1<<i))
                    v[ids[i].first][ids[i].second] = 1;
            if(solve(0) == m)
            {
                res = v;
                ok = true;
                break;
            }
        }
        
        cout << "Case #" << test << ":" ;
        if(ok)
        {
            cout << " POSSIBLE" << endl;
            for(int i = 0; i < res.size(); i++)
            {
                for(int j = 0; j < res[i].size(); j++)
                    cout << res[i][j];
                cout << endl;
            }
        }
        else
            cout << " IMPOSSIBLE" << endl;
    }
    
    return 0;
}



















