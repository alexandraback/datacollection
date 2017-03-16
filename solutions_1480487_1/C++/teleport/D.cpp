#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int t,n,p;double a[1000],b[1000],s,f,k;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>t;
    for (int j=1;j<=t;j++){
        cin>>n;s=0;p=n;k=0;
        for (int i=1;i<=n;i++){cin>>a[i];s+=a[i];}
        cout<<"Case #"<<j<<": ";
        for (int i=1;i<=n;i++){
          f=((2*s/double(n))-a[i])/s;f=f*100;
          if (f<0){k+=abs(f);p--;b[i]=f;}
          else b[i]=f;}
        for (int i=1;i<=n;i++){
            if (b[i]<0)cout<<"0.000000 ";
            else printf("%.6lf ",b[i]-k/double(p));}
        cout<<endl;}
    return 0;
}
