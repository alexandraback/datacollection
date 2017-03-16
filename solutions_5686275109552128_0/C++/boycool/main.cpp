#include<bits/stdc++.h>
using namespace std;
const int INF = 1000*1000*1000;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
int  _pow(int base, int exp){return exp == 0 ? 1 : base * _pow(base, exp - 1);}
int prime(int p)
{
    int c=0;
    for(int i=1;i<=sqrt(p);i++)
    {
        if(p%i==0 and p!=1)
            c++;
    }
    if(c==1) return 1;
    return 0;
}
int solve()
{
    int d,p[100];
    cin>>d;
    int a=0;
    for(int i=0;i<d;i++)
    {
        cin>>p[i];
        if(a<p[i]) a=p[i];
    }

    for(int z=2;z<a;z++)
    {
        int sum=0;
        for(int i=0;i<d;i++)
            sum+=floor((p[i]-1)/z);
        a=min(a,sum+z);
    }
    cout<<a;
}
int main()
{
    freopen("input.txt","rt",stdin);
    freopen("b.txt","wt",stdout);
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        printf("Case #%d: ",c);
        int g=solve();

        cout<<endl;
    }
   return 0;
}




























