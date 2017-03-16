#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;
long long p,q;
long long f[50];
long long gcd(long long a,long long b)
{
    //if (a<b) swap(a,b);
    if (a%b==0) return b;
    return gcd(b,a%b);
}

int main()
{
    int t;
    char c;
   freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    for (int o=1;o<=t;o++){
        cout<<"Case #"<<o<<": ";
       cin>>p>>c>>q;
       long  long y=gcd(q,p);
       p/=y;
       q/=y;
      int flag=0;
     long long k=1;
     for (int i=1;i<=41;i++)
     {
            f[i]=k;
            k*=2;
         }
        for (int i=1;i<=41;i++)
            if (f[i]==q) flag=1;

          if (!flag)
          {
            cout<<"impossible"<<endl;
            continue;
        }

        double x=1.0*p/q;
        int ans=0;
        while (x<1)
        {
           ans++;
           x*=2;
        }
       cout<<ans<<endl;
    }
    return 0;
}
