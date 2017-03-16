
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

int nums[] = {0, 2, 4, 6, 8, 3, 5, 7, 9, 1};
S l[]= {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
map<int, int> m;
int main() {
  freopen("/Users/mahesh/Desktop/in.txt", "r", stdin);
    freopen("/Users/mahesh/Desktop/out.txt", "w", stdout);
    int t = SS;
    rep(_, t) {
        m.clear();
        S s;
        cin>>s;
        rep(i, si(s)) {
            m[s[i]-'A']++;
        }
        int ans[10]; // = {};
        ans[0] = int(count(all(s), 'Z'));
        ans[2] = int(count(all(s), 'W'));
        ans[4] = int(count(all(s), 'U'));
        ans[6] = int(count(all(s), 'X'));
        ans[8] = int(count(all(s), 'G'));
        ford(x, 0, 9, 2) {
            rep(i, si(l[x])) {
                m[l[x][i]-'A'] -= ans[x];
            }
        }
        S yo = "";
        iter(i, m) {
            rep(x, i->second) {
                yo += ('A' + (i->first));
            }
        }
        ans[3] = int(count(all(yo), 'R'));
        ans[5] = int(count(all(yo), 'F'));
        ans[7] = int(count(all(yo), 'S'));
        ans[1] = int(count(all(yo), 'O'));
        
            printf("Case #%d: ", _+1);
        int n = 0;
        rep(i, 9) {
            n += si(l[i]) * ans[i];
        }
        assert((si(s) - n ) % 4 == 0);
        ans[9] = (si(s) - n) / 4;
        rep(i, 10) {
            rep(j, ans[i]) {
                cout<<i;
            }
        }
        puts("");

    }
}




