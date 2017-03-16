#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,r,c,w;
    scanf("%d",&t);
    for(int ci=1;ci<=t;ci++)
    {
        scanf("%d%d%d",&r,&c,&w);
        int temp=0;
        int ans;
        for(int j=w;j<=c;j+=w)
        {
            temp++;
        }
        if(c%w==0)
        {
            ans=temp*r-1;
        }
        else
        {
            ans=temp*r;
        }
        ans+=w;
        printf("Case #%d: %d\n",ci,ans);
    }
    return 0;
}
