//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back

typedef long long int ll;
using namespace std;
struct T{
int a;
};
ll bigmod(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        ll hh=bigmod(a,b/2,mod);
        return (hh*hh)%mod;
    }
    else
    {
       return (a*bigmod(a,b-1,mod))%mod;
    }
}
int rec(int n,int r)
{
    if(n<r)
        return 1;
    else return 2*(rec(n/2,r));
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
     sn("%d",&t);
     while(t--)
     {
         sn("%d %d %d",&m,&n,&k);
         u=n/k;
         if(n%k==0)
            u=(u*m)+k-1;
         else u=(u*m)+k;
         pf("Case #%d: %d\n",cs++,u);
        // pf("Case #%d: %d\n",cs++,rec(n,k));
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
