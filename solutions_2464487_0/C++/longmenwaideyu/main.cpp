#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#define N 10000
#define INF 0x6f6f6f6f
#define debug(a) cout<<#a<<' '<<a<<endl;
typedef long long LL;
using namespace std;
inline LL sq(LL x)
{
    return x*x;
}
int main()
{
    #ifndef ONLINE_JUDGE
       // freopen("in.txt","r",stdin);
     //   freopen("out.txt","w",stdout);
    #endif

    int T,cas=1;
    LL r,t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld %lld",&r,&t);

        LL ans=0,tmp=r,x;
        while(t)
        {
            x=sq(tmp+1)-sq(tmp);
            if(t>=x)
            {
                ans++;
                t-=x;
            }else break;
            tmp+=2;
            //cout<<t<<endl;
        }
        printf("Case #%d: %lld\n",cas++,ans);
    }
	return 0;
}
