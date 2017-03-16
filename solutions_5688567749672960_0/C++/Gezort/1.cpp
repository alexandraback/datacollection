#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <map>
#include <math.h>
#include <vector>
#include <limits.h>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <time.h>
#define ll long long
#define mp make_pair
#define s second
#define f first
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector <pii>
#define pll pair<ll,ll>
#define vll vector <pll>
#define pb push_back
#define inf 2000000000
#define MOD 1000000007ll

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (ll i = (ll)(x), _n = (ll)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))

#define MAX 1500000
using namespace std;
ll q[MAX];
ll ans[MAX];
ll h,t;
ll reverse(ll x) {
   ll res = 0;
   while (x > 0) {
         res = 10 * res + (x % 10);
         x /= 10;
   }
   return res;
}  
int main()
{
    //ios_base::sync_with_stdio(0);
    //memset(memo,-1,sizeof(memo));
    //memset(di,0,sizeof(di));
    //memset(dj,0,sizeof(dj));
    //memset(h,0,sizeof(h));
    //memset(cnt,-1,sizeof(cnt));
    //memset(vis,0,sizeof(vis));
    freopen("A-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);    
    memset (ans,0,sizeof(ans));
    ans[1] = 1;
    h = 0;
    t = 1;
    q[0] = 1;
    while (h < t) {
          ll x = q[h++];
          ll y = reverse (x);
          if (y < MAX && ans[y] == 0) {
             ans[y] = ans[x] + 1;
             q[t++] = y;
          }
          y = x + 1;
          if (y < MAX && ans[y] == 0) {
             ans[y] = ans[x] + 1;
             q[t++] = y;
          }
    }
    int T;
    cin >> T;
    rep (u,T) {
        ll N;
        
        cin >> N;
        printf ("Case #%d: %d\n",u + 1, ans[N]);
    }
    //system("pause");
    return 0;
}

