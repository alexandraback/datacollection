#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <ostream>
#include <queue>
#include <cmath>
#include <climits>
#include <utility>
#include <fstream>
#include <memory>
#include <sstream>
#include <set>
#include <iterator>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
#define FOR(a, b, n) for(int (a) = (b); (a) < (n); ++(a))
#define FORE(a, b, n) for(int (a) = (b); (a) <= (n); ++(a))
#define ITE(a, v) for(auto (a) = v.begin(); (a) != v.end(); ++(a))
#define LL long long
#define ALL(v) v.begin(),v.end()
#define ZERO(v) memset(v, 0, sizeof v)
#define NEG(v)  memset(v, -1, sizeof v)
#define F first
#define S second
#define LD double
#define pw(x) (1LL << (x))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define PI 3.141592653589793
#define PII pair<LL, LL>
#define INF 0x3f3f3f3f
#define FUL(x) memset(x, 0x3f, sizeof(x));
#define debug(args...) {cerr << #args << " = "; errDebug(args); cerr << endl;}
void errDebug() {}
template<typename T, typename... Args>
void errDebug(T a, Args... args) {
    cerr << a << ' ';
    errDebug(args...);
}
int n;
pair<string, string> a[1010];
int res;
void check(int val)
{
    set<string> f;
    set<string> s;
    int v = val;
    int cnt = 0;
    for(int i = 0; i < n; i++, v >>= 1)
    {
        if(v & 1)
        {
            cnt++;
            f.insert(a[i].F);
            s.insert(a[i].S);
        }
    }
    v = val;
    for(int i = 0; i < n; i++, v >>= 1)
    {
        if((v & 1) == 0)
        {
            if(f.count(a[i].F ) == 0 || s.count(a[i].S) == 0)
                return;
        }
    }
    res = max(res, n - cnt);
    
}
int solve()
{
    res = 0;
    FOR(i,0,pw(n))
    {
        check(i);
    }
    return res;
}
int main(){
    int T;
    cin >> T;
    FOR(h,0,T)
    {
        cin >> n;
        FOR(i,0,n)
        cin >> a[i].F >> a[i].S;
        cout << "Case #" << h + 1 << ": ";
        cout << solve() << endl;
    }
    return 0;
}