#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <set>
#include <cmath>
#include <sstream>

using namespace std;
typedef long long int ll;
vector<ll>ans;
ll sq(ll x)
{
    return x*x;
}
bool ispalin(ll n)
{
    ll r=0;
    ll k=n;
    while(n!=0)
    {
        r=r*10+(n%10);
        n/=10;
    }
    return r==k;
}

int main()
{
    ll i,a,b;
    for(i=1;i<=10000010;i++)
    {
        if(i%10 !=0 && ispalin(i) && ispalin(sq(i)))
        {
            ans.push_back(sq(i));
        }
    }
    int t;
    cin>>t;
    for(int ch=1;ch<=t;ch++)
    {
        scanf("%lld%lld",&a,&b);
        ll aa=int(lower_bound(ans.begin(),ans.end(),a)-ans.begin());
        ll bb=int(lower_bound(ans.begin(),ans.end(),b)-ans.begin());
        if(bb==ans.size() || ans[bb]>b)bb--;
        printf("Case #%d: %lld\n",ch,bb-aa+1);
    }
return 0;
}
