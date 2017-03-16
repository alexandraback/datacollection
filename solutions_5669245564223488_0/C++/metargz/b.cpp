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

const ll MOD = 7 + 1e9;

ll d[26][26];
ll dp[26][26];
/*
ll rec(int i, int k) {
    ll ans = 0;
    for (int k = i+1; k < j; ++k) {
        ll dp1 = rec(i, k)
    }
}*/

ll solve() {
    string s[100], str;
    int N;
    cin >> N;
    REP(i,N) {
        cin >> str;
        s[i].push_back(str[0]);
        FOR(j,1,str.size()-1)
            if (s[i][s[i].size()-1] == str[j])
                continue;
            else
                s[i].push_back(str[j]);
    }
    int p[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ll ans = 0;
    char was[26];
    do {
        memset(was, 0, sizeof(was));
        int inc = 1;
        char lc, cc = '\0';
        REP(i,N) {
            REP(j,s[p[i]].size()) {
                cc = s[p[i]][j];
                if (was[cc-'a'])
                    if (cc == lc)
                        continue;
                    else {
                        inc = 0;
                        goto lbl;
                    }
                else
                    was[cc-'a'] = true;
                lc = cc;
            }
        }
        lbl:
        ans += inc;
    } while (next_permutation(p, p+N));
    return ans % MOD;
}

int main() {
    //freopen("input",  "r", stdin);
    //freopen("output", "w", stdout);
    int TN;
    scanf("%d", &TN);
    FOR(TI,1,TN) {        
        printf("Case #%d: %lld\n", TI, solve());
    } // next test
    return 0;
}
