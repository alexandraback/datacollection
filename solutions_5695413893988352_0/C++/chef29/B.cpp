#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
//#include <regex>

/* g++ -g -std=c++0x */
/* g++ -g -std=c++11 */

using namespace std;

// std::ios::sync_with_stdio(false);

// freopen("input.txt", "rt", stdin);
// freopen("output.txt", "wt", stdout);

#define ALL(c)          (c).begin(), (c).end()
#define ALLR(c)         (c).rbegin(), (c).rend()
#define FOR(i,a,b)      for (__typeof(a) i=(a); i < (b); ++i)
#define FORR(i,a,b)     for (__typeof(a) i=(a); i > (b); --i)
#define FOR_ALL(i,c)    for (__typeof((c).begin()) i=(c).begin();   \
                             i != (c).end(); ++i)
#define FOR_ALLR(i,c)   for (__typeof((c).rbegin()) i=(c).rbegin(); \
                             i != (c).rend(); ++i)
#define SZ(array)       (sizeof(array)/sizeof(array[0]))
#define lc(x)           (x<<1)     /* 2*x */
#define rc(x)           (x<<1 | 1) /* 2*x+1 */
#define lowbit(x)       (x & (-x)) /* 0b10100 -> 0b100 */

typedef long long       LL;
typedef map<int,int>    MII;
typedef pair<int,int>   PII;
typedef pair<LL,LL>     PLL;
typedef set<int>        SI;
typedef vector<bool>    VB;
typedef vector<double>  VD;
typedef vector<int>     VI;
typedef vector<string>  VS;

/* check if a key is in container C */
template <class C>
inline bool in_(const typename C::key_type& k, const C& A)
{ return A.find(k) != A.end(); }

/* gcj 2016 */

inline LL str2i(const string& s)
{ LL i; stringstream(s) >> i; return i; }

PLL ans;

void dfs(const int i, string& C, string& J)
{
    const int n = C.size();
    if (i == n) {
        const LL a = str2i(C);
        const LL b = str2i(J);
        if (ans.first == -1)
            ans = PLL(a,b);
        else if (abs(ans.first-ans.second) > abs(a-b))
            ans = PLL(a,b);
        else if (abs(ans.first-ans.second) == abs(a-b) && ans > PLL(a,b))
            ans = PLL(a,b);
        return;
    }
    if (C[i] == '?' && J[i] == '?') {
        FOR(x,0,10) FOR(y,0,10) {
            C[i] = x+'0'; J[i] = y+'0';
            dfs(i+1,C,J);
            C[i] = '?'; J[i] = '?';
        }
    }
    else if (C[i] == '?') {
        FOR(x,0,10) {
            C[i] = x+'0';
            dfs(i+1,C,J);
            C[i] = '?';
        }
    }
    else if (J[i] == '?') {
        FOR(x,0,10) {
            J[i] = x+'0';
            dfs(i+1,C,J);
            J[i] = '?';
        }
    }
    else {
        dfs(i+1,C,J);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("foo", "rt", stdin);
#endif
    int t=0,T; cin >> T;
    while (T--) {
        ans = PLL(-1,-1);
        string C,J; cin >> C >> J;
        dfs(0,C,J);
        const int n = C.size();
        char a[256],b[256];
        sprintf(a,"%0*d",n,ans.first);
        sprintf(b,"%0*d",n,ans.second);
        printf("Case #%d: %s %s\n",++t,a,b);
    }
    return 0;
    /* printf("Case #%d: %s\n",++t,ans); */
}
