#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstring>
#include <cctype>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define FOREQ(i,a,b) for(int i = a; i <= (int)b; i++)
#define FOREACH(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALL(c) (c).begin(), (c).end()
#define SZ(c) (c).size()
template <class T> void pp(T v) { FOREACH(it, v) cout << *it << ' '; cout << endl ; }
template <class T> void pp(T v, int n) { REP(i,n) cout<<v[i]<< ' '; cout << endl; }
template <class T> inline void chmax(T &a, const T b) { a = max(a, b); }
template <class T> inline void chmin(T &a, const T b) { a = min(a, b); }
typedef vector<int> vint;
typedef pair<int, int> pint;
typedef complex<double> P;
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef unsigned uint;
const int INF = 1<<28;
const double EPS = 1.0e-9;
static const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
#undef MOD_CALC
#ifdef MOD_CALC
const ll MOD = 10000 * 10000 + 7 ;
inline void chadd(ll &a, const ll b) { a = (a + b) % MOD;}
inline ll add(const ll a, const ll b){ return (a + b) %  MOD;}
inline void chsub(ll &a, const ll b) { a = (a - b + MOD) % MOD;}
inline ll sub(const ll a, const ll b){ return (a - b + MOD) % MOD; }
inline void chmul(ll &a, const ll b) { a = (a * b) %  MOD;}
inline ll mul(const ll a, const ll b){ return (a * b) %  MOD;}
#endif
void solve(const string line)
{
    //////////////////////abcdefghijklmnopqrstuvwxyz
    const string trans = "yhesocvxduiglbkrztnwjpfmaq";
#ifdef DEBUG
    int cnt[26] = {0};
    REP(i,trans.size()) {
        cnt[trans[i]-'a']++;
    }
    REP(i,26) cout << (char)('a' + i) << " " << cnt[i] << endl;
#endif
    REP(i,line.size()) {
        char c = line[i];
        if(islower(c)) {
            cout << trans[c-'a'];
        } else cout << c;
    }
    cout << endl;
}
int main(void)
{
    string line; getline(cin, line);
    //cout << line << endl;
    int N; sscanf(line.c_str(), "%d", &N);
    for(int n = 1; n <= N; n++) {
        cout << "Case #" << n << ": ";
        //cout << endl;
        getline(cin, line);
        solve(line);
    }
    return 0;
}
