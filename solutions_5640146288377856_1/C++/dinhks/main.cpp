#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,c,r,t,w;
    cin>>t;
    for(i=1;i<=t;++i)
    {
        cin>>r>>c>>w;
        if(c%w==0)
            cout<<"Case #"<<i<<": "<<r*c/w+w-1<<endl;
        else{
            cout<<"Case #"<<i<<": "<<r*(c/w)+w<<endl;
        }
    }
    return 0;
}
