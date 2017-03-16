#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n,cnt[2555];

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int t,a;
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas)
    {
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for (int i=0;i<2*n-1;++i)
        {
            for (int j=0;j<n;++j)
            {
                scanf("%d",&a);
                ++cnt[a];
            }
        }
        vector<int> ans=vector<int>();
        for (int j=1;j<=2500;++j)
            if (cnt[j]%2)
                ans.push_back(j);
        sort(ans.begin(),ans.end());
        printf("Case #%d: ",cas);
        for (int i=0;i<n;++i) printf("%d%c",ans[i],i==n-1?'\n':' ');
    }
    return 0;
}
