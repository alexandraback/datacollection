#include<bits/stdc++.h>
using namespace std;

char s[2000] ;
main()
{
    freopen("A.in","r",stdin) ;
    freopen("A.out","w",stdout) ;
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d%s",&n,s+1) ;
        int ans=0 ;
        for(int i=1,sum=0;i<=n;i++)
            sum+=s[i]-'0' , ans=max(ans,i-sum) ;
        printf("Case #%d: %d\n",++tc,ans) ;
    }
}
