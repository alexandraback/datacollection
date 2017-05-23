#include<bits/stdc++.h>
using namespace std;

int n,m,x ;
int solve()
{
    if((n*m)%x) return 1 ;
    if(x>=7) return 1 ;
    if(n>=x) return 2 ;

    if(x<=2) return 2 ;
    if(x==3) return n==1 ? 1 : 2 ;
    if(x==4) return n==3 ? 2 : 1 ;
    if(x==5)
    {
        if(n<=2) return 1 ;
        return n==3 ? 1 : 2 ;
    }
    if(x==6)
    {
        if(n==5 || n==4) return 2 ;
        return 1 ;
    }
}

main()
{
    freopen("D.in","r",stdin) ;
    freopen("D.out","w",stdout) ;
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d%d",&x,&n,&m) ;
        if(n>m) swap(n,m) ;
        printf("Case #%d: %s\n",++tc,solve()==1 ? "RICHARD" : "GABRIEL") ;
    }
}
