
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


int main() {
  freopen("/Users/mahesh/Desktop/in.in", "r", stdin);
    freopen("/Users/mahesh/Desktop/out.txt", "w", stdout);
    int t = SS;
    rep(_, t) {
        int n = SS, ans = 0;
        vs a = vs(n), b = vs(n);
        rep(i, n) {
            cin>>a[i]>>b[i];
        }
        ifor(i, (1<<n)-1, 0) {
            vs fakea = vs(), fakeb = vs(), reala = vs(), realb = vs();
            rep(j, n) {
                if (i&(1<<j)) {
                    fakea.pb(a[j]);
                    fakeb.pb(b[j]);
                } else {
                    reala.pb(a[j]);
                    realb.pb(b[j]);
                }
            }
            int possible = 1;
            rep(j, si(fakea)) {
                if (!count(all(reala), fakea[j]) || !count(all(realb), fakeb[j])) {
                    possible = 0;
                    break;
                }
            }
            if (possible) {
                ans = max(ans, __builtin_popcount(i));
            }
        }
        printf("Case #%d: %d\n",_+1, ans);
    }
}




