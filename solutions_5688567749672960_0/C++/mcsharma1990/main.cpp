
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

ll ff(int c) {
    if (c==1) return 0;
    ll k = 1;
    ll ans = 9;
    rep(i, c-2) {
        k*=10;
        ans += k+9;
    }
    return ans;
    
}
bool yo(ll n) {
    int c = 0, c2 = 0;
    ll save = n;
    while (n) {
        c++;
        n/=10;
    }
    while(save % 10 ==0) {
        c2++;
        save/=10;
    }
    return c2 >= (c+1)/2;
}

int rev(int x) {
    int ans = 0;
    while (x) {
        ans = 10*ans+x%10;
        x/=10;
    }
    return ans;
}

int ans[1000001];
int main () {
    freopen("/Users/mahesh/Desktop/Codejam/Codejam/test.txt", "r", stdin);
    freopen("/Users/mahesh/Desktop/Codejam/Codejam/out.txt", "w", stdout);
    int T = SS;
    rep(t, T) {
        int N = SS;
        if (N<10) {
            printf("Case #%d: %d\n", t+1, N);
            continue;
        }
        ans[N] = 0;
        ifor(i, N-1, 1) {
            int r = rev(i);
            if (r > i && r <= N) ans[i] = 1+min(ans[i+1], ans[r]);
            else ans[i] = 1+ans[i+1];
        }
        printf("Case #%d: %d\n", t+1, ans[1]+1);
    }
}
