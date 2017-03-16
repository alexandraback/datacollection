// Author : Mahesh

/* 1. Did u interpret the qns correctly ?
 2. Is your i/o correct ?
 3. Int overflow, double precesion
 4. Array size correct ?
 5. Clearing/resetting vector, map etc.
 6. Stack ovrflow
 7. Global/local conflict
 8. Check for obvious typo(most imp)
 */

#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <memory.h>
#include <cassert>

using namespace std;

#define ford(i, a, b, c)        for(int i=(a); i<(b); i+=(c))
#define fori(i, a, b)           ford(i,a,b,1)
#define rep(i, n)               fori(i,0,n)
#define ifor(i, a, b)           for(int i=(a); i>=(b); i--)
#define iter(i, a)              for(typeof((a).begin()) i=(a).begin(); i!=(a).end(); i++)
#define si(x)                   ((int)x.size())
#define SS                      ({int x;scanf("%d",&x);x;})
#define pb                      push_back
#define mp                      make_pair
#define all(a)                  a.begin(),a.end()
#define fill(a, v)              memset(a, v, sizeof(a))
#define inf                     (int)1e9
#define linf                    (long long)1e18
#define V                       vector
#define S                       string
#define XX                      first
#define YY                      second
#define P(v)                    rep(i, si(v)) cout<<v[i]<<" "; puts("")

typedef V<int> vi;
typedef V<S> vs;
typedef long long ll;
typedef pair<int,int> pii;

/* Program Body starts here */

int N, R,E, dp[101][10];

int v[10];

int solve(int e, int x) {
    if (x == N) {
        return 0;
    }
    int& ans = dp[e][x];
    if (ans != -1) {
        return  ans;
    }
    ans = 0;
    rep(i, e+1) {
        ans = max(ans, v[x]*i + solve(min(e-i+R, E), x+1));
    }
    return ans;
}

int main() {
    int T = SS;
    fori(t, 1, T+1) {
        E = SS;
        R = SS;
        N = SS;
        fill(dp, -1);
        rep(i, N) {
            v[i] = SS;
        }
        int ans = solve(E, 0);
        printf("Case #%d: %d\n", t, ans);
    }
}
