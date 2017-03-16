#include<vector>
#include<iostream>
#include<stdio.h>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<climits>
#include<sstream>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<bitset>

#define ll long long
#define FL(i,a,b) for(ll i=a;i<b;i++)
#define FOR(i,n) for(ll i=0;i<n;i++)
#define SORTF(x) sort(x.begin(),x.end(),func);
#define SORT(x) sort(x.begin(),x.end())
#define pb(x) push_back(x)
#define SET(v, val) memset(v, val, sizeof(v)) ;
#define RSORT(v) { SORT(v) ; REVERSE(v) ; }
#define ALL(v) v.begin(),v.end()
#define REVERSE(v) { reverse(ALL(v)) ; }
#define UNIQUE(v) unique((v).begin(), (v).end())
#define RUNIQUE(v) { SORT(v) ; (v).resize(UNIQUE(v) - (v).begin()) ; }
#define fill(x,n) memset(x,n,sizeof(x))
#define sl(x) scanf("%d",&x)
using namespace std;

ll n;
ll c = 0;
ll rev(ll num)
{
    ll ans = 0;
    while(num!=0)
    {
        ans = ans*10;
        ans = ans + num%10;
        num/=10;
    }
    return ans;
}

ll func(ll num)
{ 
    if(num > n)
    {
        return 1000000000000000000;
    }
    if(num == n)
    {
        return 1;
    }

    ll x = func(num+1);
    ll re = rev(num);
    ll y = 1000000000000000000;
    if(re < n && re!=num && re > num)
    {
        y = func(re);
    }
    ll c = min(x,y) + 1;
  
    return c;
}
int main()
{
   
    ll t;
    cin >> t;
    ll ca = 1;
    while(t--)
    {
        cin >> n;
        ll ans = func(1);
        cout << "Case #" << ca << ": " << ans << endl;
        ca++;
    }


    return 0;
}