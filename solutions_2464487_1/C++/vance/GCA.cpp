#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int main()
{

    freopen("al.in","r",stdin);
    freopen("al.out","w",stdout);
    int t;
    LL s,tt;
    scanf("%d",&t);
    //getchar();
    for(int cnt = 1;cnt<=t;cnt++)
    {
        scanf("%lld %lld",&s,&tt);
        LL l = 1,r = min(1000000000ll,tt/s);
        while(l<r)
        {
            LL m = (l+r+1)/2;
            LL d = m*(2*m+2*s-1);
            //LL c = (m+1)*(2*(m+1)+2*s-1);
            if(d<=tt)
                l = m;
            else
                r = m-1;
            //printf("%lld %lld %lld %lld\n",l,r,m,d);
        }
        printf("Case #%d: %lld\n",cnt,l);
    }
    return 0;
}
