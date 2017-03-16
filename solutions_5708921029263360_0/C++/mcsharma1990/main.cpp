
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
#include <sstream>

using namespace std;

#define ford(i, a, b, c)        for(int i=(a); i<(b); i+=(c))
#define fori(i, a, b)           ford(i,a,b,1)
#define rep(i, n)               fori(i,0,n)
#define ifor(i, a, b)           for(int i=(a); i>=(b); i--)
#define iter(i, a)              for(typeof(a.begin()) i=(a).begin(); i!=(a).end(); i++)
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

int f[50][50], g[1][1];
int dp[50];
int B = 1;

int ff(int index) {
    int& ans = dp[index];
    if (ans != -1) return ans;
    ans = 0;
    rep(i, B) {
        if (g[index][i]) {
            ans += ff(i);
        }
    }
    return ans;
}

int solve() {
    rep(i, B) dp[i] = -1;
    dp[B-1] = 1;
    return ff(0);
}

int main() {
    freopen("/Users/mahesh/Desktop/codejam/codejam/in.txt", "r", stdin);
    freopen("/Users/mahesh/Desktop/codejam/codejam/out.txt", "w", stdout);
    int t = SS;
    rep(_, t) {
        int A = SS, B = SS, C = SS, K = SS;
        int M = A*B*C;
        int  c = 1;
        rep(i, A) rep(j, B) rep(k, C) {
            ca[c] = i;
            cb[c] = j;
            cc[c] = k;
            c++;
        }
        rep(i, 1<<M) {
            rep(j, M) {
                if (i&(1<<j)) {
                    
                }
            }
        }
    }
}






