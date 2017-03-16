#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<algorithm> 
#define ll long long
#define MAXN 105
using namespace std; 
ll a,b;
char c;
ll doit(ll a,ll b)
{
       int i;  
       ll k=1;
       for (i=0;i<64;i++)
       {
              if (k==b) break;
              k*=2;
       } 
       if (i==64) return -1; 
       for (i=0;i<32;i++)
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
       freopen("A-small-attempt0.in","r",stdin);
       freopen("output.txt","w",stdout); 
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
