#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    freopen("A-small-attempt1.in","r+",stdin);
    freopen("A-small-attempt1.out","w+",stdout);
    int t,k=0;
    cin>>t;
    while(t--)
    {
        long long p,q,count=1,check,temp=2;
        int flag=1;
        k++;
        scanf("%lld/%lld",&p,&q);
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
