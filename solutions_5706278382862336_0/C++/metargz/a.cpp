#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define VAR(a,b)        __typeof(b) a=(b)
#define REP(i,n)        for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b)      for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b)     for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c)   for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c)          (c).begin(),(c).end()
#define TRACE(x)        cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x)        cerr << #x << " = " << x << endl;
#define eprintf(...)    fprintf(stderr, __VA_ARGS__)

typedef long long               ll;
typedef long double             ld;
typedef unsigned long           ulong;
typedef unsigned long long      ull;
typedef vector<int>             VI;
typedef vector<char>            VC;

int main() {
    //freopen("input",  "r", stdin);
    //freopen("output", "w", stdout);
    int TN;
    string s;
    scanf("%d", &TN);
    FOR(TI,1,TN) {
        cin >> s;
        ll p = 0, q = 0, x;
        for (x = 0; s[x] != '/'; ++x)
            p = 10*p + s[x] - '0';
        ++x;
        for (; x < s.size(); ++x)
            q = 10*q + s[x] - '0';
        p = (1LL<<40)*p;
        if (p%q) {
            printf("Case #%d: impossible\n", TI);
            continue;
        }
        p /= q;
        for (x = 40; p >= 2; p /= 2, --x);
        printf("Case #%d: %lld\n", TI, x);
    } // next test
    return 0;
}
