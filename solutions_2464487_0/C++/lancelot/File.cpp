//
//  File.cpp
//  gcj1a
//
//  Created by 宋 良骏 on 13-4-27.
//  Copyright (c) 2013年 宋 良骏. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
double PI=3.14159265359;
long long r,t;
long long min(long long a,long long b)
{
    return a<b?a:b;
}
unsigned long long func(long long n)
{//n+2rn+2n*(n-1)=t;
    unsigned long long res=n*(1+2*r+2*(n-1));
    //printf("%lld %lld\n",n,res);
    return res;
}
int main()
{
    int cas=0;
    scanf("%d",&cas);
    for(int C=1;C<=cas;C++)
    {
      
        scanf("%lld %lld",&r,&t);
        int times=0;
        long long low=1,high=min(t/r,7071067800);
        long long mid=(low+high)>>1;
        
        for(int i=0;i<=1000;i++)
        {
            long long  last=mid;
            if(func(mid)<=t)
            {
                low=(low+mid)/2;
                times=mid;
            }
            else
            {
                high=(mid-1+high)/2;
            }
            
            mid=(low+high)/2;
        }
        printf("Case #%d: %d\n",C,times);
    }
    
    return 0;
}