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

int maxn = 26;
int cnt[256];
int ans[10];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("foo", "rt", stdin);
#endif
    int t=0,T; cin >> T;
    while (T--) {
        memset(ans,0,sizeof(ans));
        memset(cnt,0,sizeof(cnt));
        string S; cin >> S;
        FOR_ALL(c,S) {
            cnt[*c]++;
        }
        while (1) {
            if (cnt['Z']) {
                ans[0]++;
                cnt['Z']--;
                cnt['E']--;
                cnt['R']--;
                cnt['O']--;
            }
            else if (cnt['X']) {
                ans[6]++;
                cnt['S']--;
                cnt['I']--;
                cnt['X']--;
            }
            else if (cnt['W']) {
                ans[2]++;
                cnt['T']--;
                cnt['W']--;
                cnt['O']--;
            }
            else if (cnt['U']) {
                ans[4]++;
                cnt['F']--;
                cnt['O']--;
                cnt['U']--;
                cnt['R']--;
            }
            else if (cnt['G']) {
                ans[8]++;
                cnt['E']--;
                cnt['I']--;
                cnt['G']--;
                cnt['H']--;
                cnt['T']--;
            }
            else if (cnt['O']) {
                ans[1]++;
                cnt['O']--;
                cnt['N']--;
                cnt['E']--;
            }
            else if (cnt['T']) {
                ans[3]++;
                cnt['T']--;
                cnt['H']--;
                cnt['R']--;
                cnt['E']--;
                cnt['E']--;
            }
            else if (cnt['F']) {
                ans[5]++;
                cnt['F']--;
                cnt['I']--;
                cnt['V']--;
                cnt['E']--;
            }
            else if (cnt['S']) {
                ans[7]++;
                cnt['S']--;
                cnt['E']--;
                cnt['V']--;
                cnt['E']--;
                cnt['N']--;
            }
            else if (cnt['N']) {
                ans[9]++;
                cnt['N']--;
                cnt['I']--;
                cnt['N']--;
                cnt['E']--;
            }
            bool good = true;
            FOR(i,0,256) {
                assert(cnt[i] >= 0);
                good &= cnt[i]==0;
            }
            if (good)
                break;
        }
        string ans_;
        FOR(i,0,10) FOR(_,0,ans[i]) {
            ans_ += string(1,i+'0');
        }
        printf("Case #%d: %s\n",++t,ans_.c_str());
    }
    return 0;

}
