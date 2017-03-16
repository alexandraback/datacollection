#include<bits/stdc++.h>
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define p(n) printf("%d\n",n)
#define mod 1000000007
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{
if(a%b==0)
return b;
else
return gcd(b,a%b);
}
int main()
{

    int t,k,i,f,j,len,ans;
    char ch;
    ll p,q,tmp,tmp1;
    ifstream f1("abc.txt");
    ofstream f2("output1.txt");
    f1>>t;

    for(k=1;k<=t;++k)
    {
        ans=0;

        f1>>p>>ch>>q;
        f2<<"Case #"<<k<<": ";

        tmp=gcd(q,p);
        p=p/tmp;
        q=q/tmp;
        tmp1=q&(q-1);
        if(tmp1!=0)
        f2<<"impossible\n";
        else
        {
           while(q>p)
           {
           q=q/2;
           ans++;
           }
          f2<<ans<<endl;
        }






            }
return 0;
}
