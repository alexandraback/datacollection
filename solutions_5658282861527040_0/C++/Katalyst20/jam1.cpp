#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int a,b,k,i,j,test,t;
    long long int co=0;
    cin>>t;
    for(test=1;test<=t;test++)
    {
        co=0;
        cin>>a>>b>>k;
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                if((i&j)<k)
                    co++;
            }
        }
        cout<<"Case #"<<test<<": ";
            cout<<co<<endl;
    }
    return 0;
}
