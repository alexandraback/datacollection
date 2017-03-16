#include<cstdio>
#include<algorithm>
using namespace std;

long long v[10000005], p[10000005], e[10000005];

int main()
{
    int T,tc,n,c;
    long long r,max,ttl;
    scanf("%d",&T);
    for(tc=1;tc<=T;tc++)
    {
        scanf("%lld%lld%d",&e[0],&r,&n);
        if(r>e[0]) r = e[0];
        for(c=0;c<n;c++) scanf("%lld",&v[c]);
        max = e[0];
        for(c=0;c<n;c++)
        {
            if(c==n-1) p[c] = e[c];
            else if(e[c]==max)
            {
                e[c+1] = r;
                p[c] = max;
            }
            else if(e[c]+r>max)
            {
                e[c+1] = max;
                p[c] = e[c]+r-max;
            }
            else
            {
                e[c+1] = e[c] + r;
                p[c] = 0;
            }
        }
        sort(p,p+n);
        sort(v,v+n);
        ttl = 0LL;
        //for(c=0;c<n;c++) printf("%lld:%lld\n",p[c],v[c]);
        for(c=0;c<n;c++) ttl += v[c]*p[c];
        printf("Case #%d: %lld\n",tc,ttl);
    }
    return 0;
}
