/* ***************************
Author: Abhay Mangal (abhay26)
*************************** */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <numeric>
#include <utility>
#include <bitset>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
 #define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define maX(a,b) (a) > (b) ? (a) : (b)
#define pii pair< int, int >
#define pll pair< ll, ll >
#define pip pair< int, pii >
#define FOR(i,n) for(int i=0; i<(int)n ;i++)
#define REP(i,a,n) for(int i=a;i<(int)n;i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
//int dx[]= {-1,0,1,0};
//int dy[]= {0,1,0,-1};
map<pll, int> M;
ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}
set<ll> S;
int calc(ll a, ll b)
{
   // cout << a << " " << b << endl;
    if(M.find(pll(a,b)) != M.end())
        return M[pll(a,b)];
    int &ret = M[pll(a,b)];
    ret = 100000;
    if(a == 0)
        return ret;
    ll z = b/2;
    if(a >= z)
    {
        ret = 1;
        return ret;
    }
    for(ll i=0;i<=a;i++)
    {
        ll j = a - i;
        ret = min(ret, 1+calc(i,z));
        ret = min(ret, 1+calc(j,z));
    }
    return ret;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    ll x = 2;
    int c = 45;
    FOR(i,c)
    {
        S.insert(x);
        x = x << 1;
       // cout << x << endl;
    }
    int t;
    scanf("%d",&t);
    FOR(Z,t)
    {
        ll p,q;
        scanf("%lld/%lld",&p,&q);
        ll g = gcd(p,q);
        p /= g;
        q /= g;
        printf("Case #%d: ",Z+1);
        if(S.find(q) == S.end())
        {
            printf("impossible\n");
            continue;
        }
        int ans = 0;
        while(q > p)
        {
            ans++;
            q /= 2;
        }
        printf("%d\n",ans);
    }
return 0;
}
