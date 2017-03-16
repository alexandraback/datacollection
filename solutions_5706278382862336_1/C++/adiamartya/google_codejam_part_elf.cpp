#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<vector>
#include<map>
#include<algorithm>
#include<limits.h>
#include<set>
#include<math.h>
 
using namespace std;
#define lli long long int
#define ulli unsigned long long int
#define in(t) scanf("%d",&t)
#define inlf(t) scanf("%lf",&t)
#define inl(t) scanf("%ld",&t)
#define inll(t) scanf("%lld",&t)
#define inlu(t) scanf("%llu",&t)
#define MOD 1000000007

lli gcd(lli u,lli v) {return v?gcd(v,u%v):u;}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("A-large (1).in","r",stdin);
    freopen("A-large (1).out","w",stdout);
    #endif
    
    lli t,cases,p,q,ans,temp,div;
    inll(t);
    for(cases=1;cases<=t;cases++)
    {
    ans=temp=div=0;
    scanf("%lld/%lld",&p,&q);
    
    div=gcd(p,q);
    p/=div;
    q/=div;
    //cout<<q<<"\n";
    temp=q;
    while(temp!=0)
    {
    if(temp%2 && temp!=1)
    break;
    else
    temp/=2;
    }
    if(temp!=0)
    printf("Case #%lld: impossible\n",cases);
    
    else
    {
    while(p<q)
    {
    q/=2;
    ans++;
    }
    printf("Case #%lld: %lld\n",cases,ans);
    }
    }
    return 0;
}
