#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t,r,n,m,k,c,d;
    vector<long long> ans;
    int vmax,ttl;
    long long a[105];
    scanf("%d%d%d%d%d",&t,&r,&n,&m,&k);
    printf("Case #1:\n");
    while(r--)
    {
        ans.clear();
        for(c=0;c<k;c++) scanf("%lld",&a[c]);
        long long p[6] = {8LL,7LL,4LL,5LL,6LL,3LL};
        for(d=0;d<6;d++)
        {
            vmax = 0;
            for(c=0;c<k;c++)
            {
                ttl = 0;
                while(a[c]%p[d]==0LL)
                {
                    a[c] /= p[d];
                    ttl++;
                }
                vmax = max(vmax,ttl);
            }
            while(vmax--) ans.push_back(p[d]);
        }
        for(;ans.size()<n;) ans.push_back(2LL);
        for(c=0;c<n;c++) printf("%lld",ans[c]);
        printf("\n");
    }
    return 0;
}
