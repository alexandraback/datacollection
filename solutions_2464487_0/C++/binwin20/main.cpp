#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#define LL long long
#define DB double

using namespace std;
LL r,t;
LL solve()
{
    int ret = 0;
    for(LL i=r;t>0;i+=2)
    {
        t-=((i+1)*(i+1)-i*i);
        if(t>=0)
        {
            ret++;
        }
    }
    return ret;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w+",stdout);
    #endif
    int cas,T=1;scanf("%d",&cas);

    while(cas--)
    {
        cin>>r>>t;
        LL ans = solve();
        cout<<"Case #"<<(T++)<<": "<<ans<<endl;
    }
    return 0;
}
