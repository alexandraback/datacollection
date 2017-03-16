#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<algorithm> 
#define ll long long
#define MAXN 105
using namespace std; 
ll a,b,p;
char c;
ll gcd(ll a,ll b)
{
       if (b==0) return a;
       return gcd(b,a%b);
}
ll doit(ll a,ll b)
{
       int i;  
       ll k=1;
       p=gcd(a,b);
       a/=p,b/=p;
       p=b;
       while (p%2==0) p/=2; 
       if (p!=1) return -1;
       for (i=0;i<64;i++)
       {
              if (a>=b) break;
              a*=2;
       }
       return i;
}
int main()
{
       int T,cases;
       ll ans;
       freopen("A-large.in","r",stdin);   freopen("output0.txt","w",stdout); 
       cin>>T;
       for (cases=1;cases<=T;cases++)
       { 
               cin>>a>>c>>b;
               printf("Case #%d: ",cases);
               ans=doit(a,b);
               if (ans<0) cout<<"impossible"<<endl;
                     else cout<<ans<<endl;
       }
       return 0;
}
