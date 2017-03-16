#include<iostream>
#include<cmath>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{
    long long int p,q,r=0,t,j;
    long long int ans,i,g;
    long double inte;
    char ch;
cin>>t;
for(j=0;j<t;j++){
        r=0;
    cin>>p>>ch>>q;
    g=gcd(p,q);
    p=p/g;
    q=q/g;
    for(i=1;i<=40;i++)
    {
        if(pow(2,i)==q)
        {
            r=1;
            break;
        }
    }
    if(!r)
        cout<<"Case #"<<j+1<<": impossible\n";
    else
    {inte=(long double)q/p;
    for(i=0;i<=40;i++)
    {
        if(pow(2,i)>=inte)
        {ans=i;
        break;
        }
    }
 
        cout<<"Case #"<<j+1<<": "<<ans<<"\n";
    }
}
 
        return 0;
}
