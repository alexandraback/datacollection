#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;
int a[maxn] ;
main()
{
    freopen("B.in","r",stdin) ;
    freopen("B.out","w",stdout) ;
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        int n,ma=0 ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]) , ma=max(ma,a[i]) ;
        int ans=ma ;
        for(int i=1;i<ma;i++)
        {
            int val=0 ;
            for(int j=1;j<=n;j++) val+=(a[j]-1)/i ;
            ans=min(ans,val+i) ;
        }
        printf("Case #%d: %d\n",++tc,ans) ;
    }
}
