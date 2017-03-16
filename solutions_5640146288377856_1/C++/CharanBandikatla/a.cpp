#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int t,i,r,c,w;
    for(cin>>t,i=1; i<=t ;i++)
    {
        cin>>r>>c>>w;
        int sol=c/w;
        sol=sol*r;
        if(c%w!=0) sol++;
        sol+=w-1;
        printf("Case #%d: %d\n",i,sol);
    }
    return 0;
}
