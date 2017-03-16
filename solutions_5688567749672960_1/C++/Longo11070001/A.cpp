#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#define pb push_back
using namespace std;
typedef long long ll;
const ll inf = 10000000000000000LL;
ll steps[20],ten[20];
inline ll rev(ll x)
{
    ll ret=0,tmp;
    while(x)
    {
        tmp = x%10;
        ret = ret*10+tmp;
        x/=10;
    }
    return ret;
}
void init()
{
    ten[0] = 1LL;
    for(int i=1; i<=15; i++) ten[i] = 10LL*ten[i-1];
    steps[2] = 10;
    ll tens,target=10LL;
    for(int i=3; i<=15; i++)
    {
        tens = 1; target*=10LL;
        steps[i] = steps[i-1] + target - target/10LL;
        for(int j=1; j<i-1; j++)
        {
            tens *= 10LL;
            steps[i] = min(steps[i],steps[i-1]+tens+target-rev(target/10LL+tens-1));
        }
    }
    //for(int i=2; i<=15; i++) printf("%d %lld\n",i,steps[i]);
}
inline int getlen(ll x)
{
    int ret = 0;
    while(x)
    {
        ret++;
        x/=10;
    }
    return ret;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,cas,len;
    ll n,ans,r,cur;
    init();
    scanf("%d",&T);
    for(cas=1; cas<=T; cas++)
    {
        scanf("%lld",&n);
        printf("Case #%d: ",cas);
        if(n <= 20){
            printf("%lld\n",n);
            continue;
        }
        bool type = false;
        if(n%10 == 0) type=true, n--;
        len = getlen(n);
        cur = steps[len];
        r = rev(n);
        ans = cur + n-ten[len-1];
        for(int i=1; i<len; i++)
        {
            ans = min(ans,cur+(r%ten[i])+1+n-rev(ten[len-1]+(r%ten[i])));
        }
        if(type) ans++;
        printf("%lld\n",ans);
    }
    return 0;
}
