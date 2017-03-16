#include<stdio.h>
#include<iostream>
using namespace std;
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    freopen("A-large.in","r+",stdin);
    freopen("A-large.out","w+",stdout);
    int t,k=0;
    cin>>t;
    while(t--)
    {
        long long p,q,count=1,check,temp=2,gcd1;
        int flag=1;
        k++;
        scanf("%lld/%lld",&p,&q);
        gcd1=gcd(p,q);
        p=p/gcd1;
        q=q/gcd1;
        check=q&(q-1);
        if(check!=0)
            flag=0;
        else
        {
               while(1)
               {


                if(p*temp<q)
                    {
                        count++;
                        temp=temp*2;
                    }
                else
                    break;
               }
        }
        if(flag==0)
            cout<<"Case #"<<k<<": impossible"<<endl;
        else
            cout<<"Case #"<<k<<": "<<count<<endl;
    }
}
