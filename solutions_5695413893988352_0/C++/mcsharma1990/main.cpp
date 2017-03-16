
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

int N;
pii ans = mp(inf, 0);

int ff(vi a) {
    int x = 0;
    rep(i, N) {
        x = 10*x + a[i];
    }
    return x;
}

void solve(vi a, vi b) {
    if (count(all(a), -1) == 0 && count(all(b), -1) == 0) {
        int A = ff(a), B = ff(b);
        if (abs(A-B) < abs(ans.XX-ans.YY) || (abs(A-B) == abs(ans.XX - ans.YY) && A < ans.XX)) {
            ans = mp(A, B);
        }
    }
    rep(i, N) {
        if (a[i] == -1) {
            rep(d, 10) {
                a[i] = d;
                solve(a, b);
            }
            return;
        }
    }
    rep(i, N) {
        if (b[i] == -1) {
            rep(d, 10) {
                b[i] = d;
                solve(a, b);
            }
            return;
        }
    }
    
}

int di(int n) {
    if (n==0) return 1;
    int d = 0;
    while (n) {
        n/=10;
        d++;
    }
    return d;
}

int main() {
  freopen("/Users/mahesh/Desktop/in.in", "r", stdin);
    freopen("/Users/mahesh/Desktop/out.txt", "w", stdout);
    int t = SS;
    rep(_, t) {
        ans = mp(inf, 0);
        S s1, s2;
        cin>>s1>>s2;
        N = si(s1);
        vi a(N), b(N);
        rep(i, si(s1)) {
            a[i] = s1[i] == '?'  ? -1 : (s1[i] - '0');
        }
        rep(i, si(s2)) {
            b[i] = s2[i] == '?' ? -1 : (s2[i] - '0');
        }
        solve(a, b);
        S ss1(N - di(ans.XX), '0'), ss2(N - di(ans.YY), '0');
        printf("Case #%d: %s%d %s%d\n",_+1, ss1.c_str(), ans.XX, ss2.c_str(), ans.YY);
    
    }
}




