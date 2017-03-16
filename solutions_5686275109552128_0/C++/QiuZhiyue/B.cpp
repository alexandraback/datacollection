#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
int a[1005];
main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int d;scanf("%d",&d);
        for(int i=1;i<=d;i++)
        scanf("%d",&a[i]);
        int ans=1000000000;
        for(int i=1;i<=1000;i++)
        {
            int tp=0;
            for(int j=1;j<=d;j++)
            {
                int q;
                if(a[j]%i) q=a[j]/i+1;
                else q=a[j]/i;
                tp+=q-1;
            }
            tp+=i;
            ans=min(ans,tp);
        }
        printf("Case #%d: %d\n",cas,ans);
    }
}
