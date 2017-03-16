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

int n;
int vo (char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c== 'u';
}
int cc(char c) {
    return !vo(c);
}

int solve(int x, vi s, vi e, int L) {
    int p = lower_bound(e.begin(), e.end(), x) - e.begin();
    if (p==si(e)) return 0;
    int end = e[p];
    int start = s[p];
    if (x<start) {
        return L-(start+n)+1;
    }
    if (x+n-1 <= end) {
        return L-(x+n)+1;
    }
    if (p+1 <si(e)) {
        return L-(s[p+1]+n-1);
    }
    return 0;
}

int main() {
    int T = SS;
    fori(t, 1, T+1) {
        S s;
        cin>>s;
        n = SS;
        int st;
        vi start = vi();
        vi end  = vi();
        rep(i, si(s)) {
            if (cc(s[i])) {
                if (i==0 || vo(s[i-1])) {
                    st = i;
                }
                if (i==si(s)-1 || vo(s[i+1])) {
                    if (i-st+1 >= n) {
                        start.pb(st);
                        end.pb(i);
                    }
                }
            }
        }
        ll ans = 0;
        rep(i, si(s)) {
            int temp = solve(i, start, end, si(s));
            ans+=temp;
        }
        printf("Case #%d: %lld\n", t, ans);
    }
}

