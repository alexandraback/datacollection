#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=10000+10 ;

int F[5][5]={
    {},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}
} ;
int f(int x,int y) /// i,j,k : 2,3,4
{
    int ret=1 ;
    if(x<0) ret*=-1 , x=-x ;
    if(y<0) ret*=-1 , y=-y ;
    return ret*F[x][y] ;
}
int power(int x,LL m)
{
    if(m<=1) return m==1 ? x : 1 ;
    int tmp=power(x,m/2) ;
    if(m&1) return f(f(tmp,tmp),x) ;
    else return f(tmp,tmp) ;
}

int n ;
char s[maxn] ;
bool check(LL x)
{
    int p=1 ;
    for(int i=0;i<n;i++) p=f(p,s[i]-'g') ;
    if(power(p,x)!=-1) return 0 ;
    int i,j ;
    for(i=0,p=1;p!=2 && i<=4*n;i++) p=f(p,s[i%n]-'g') ;
    if(i==4*n+1) return 0 ;
    for(j=i,p=1;p!=3 && j<=i+4*n;j++) p=f(p,s[j%n]-'g') ;
    if(j==4*n+i+1) return 0 ;
    return j<n*x ;
}

main()
{
    freopen("C.in","r",stdin) ;
    freopen("C.out","w",stdout) ;
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        LL x ;
        scanf("%d%I64d%s",&n,&x,s) ;
        if(check(x)) printf("Case #%d: YES\n",++tc) ;
        else printf("Case #%d: NO\n",++tc) ;
    }
}
