#include<iostream>
#include<stdio.h>
using namespace std;
#define lli long long int

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("outa.txt","w",stdout);
    lli t,j=1,r,c,w,u;
    cin>>t;
    while(t--)
    {
              cin>>r>>c>>w;
              
              u=(c/w);
              
              u*=r;
              
              u+=(w-1);
              
              if(c%w!=0)
              u+=1;
              
              cout<<"Case #"<<j<<": "<<u<<endl;
              j++;
    }
    
    return 0;
}
              
              
              
              
              
    


