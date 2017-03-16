#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<list>
#include<bitset>
#include<sstream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define eps 1e-6
#define PI acos(-1)
typedef unsigned long long ll;
const int unsigned inf=0x3f3f3f3f;
//const ll linf=ceil(pow(2.0,62));
//const double dinf=pow(2.0,62);
const int maxn=5000;

int T;
ll R,t;

ll bs(ll l,ll r)
{
    ll ans=0LL;
    while(l<=r)
    {
        ll m=(l+r)/2LL;
        ll tmp=(1LL+2LL*R+2LL*m);
        if(tmp<=t/(m+1LL))
        {
            ans=m;
            l=m+1LL;
        }
        else r=m-1LL;
    }
    return ans;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out2.out","w",stdout);
    scanf("%d",&T);
    int ncase=0;
    while(T--)
    {
        ncase++;
        scanf("%llu%llu",&R,&t);
        ll ans=bs(0,t)+1LL;
        printf("Case #%d: %llu\n",ncase,ans);
    }
    return 0;
}
