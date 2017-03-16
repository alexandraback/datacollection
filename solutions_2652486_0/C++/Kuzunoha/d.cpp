#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t,r,n,m,k,c,d;
    vector<int> ans;
    int vmax,ttl;
    int a[105];
    scanf("%d%d%d%d%d",&t,&r,&n,&m,&k);
    printf("Case #1:\n");
    while(r--)
    {
        ans.clear();
        for(c=0;c<k;c++) scanf("%d",&a[c]);
        int p[3] = {3,5,4};
        for(d=0;d<3;d++)
        {
            vmax = 0;
            for(c=0;c<k;c++)
            {
                ttl = 0;
                while(a[c]%p[d]==0)
                {
                    a[c] /= p[d];
                    ttl++;
                }
                vmax = max(vmax,ttl);
            }
            while(vmax--) ans.push_back(p[d]);
        }
        for(;ans.size()<n;) ans.push_back(2);
        for(c=0;c<ans.size();c++) printf("%d",ans[c]);
        printf("\n");
    }
    return 0;
}
