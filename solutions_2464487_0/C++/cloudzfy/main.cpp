//
//  main.cpp
//  codejam
//
//  Created by cloudzfy on 4/27/13.
//  Copyright (c) 2013 cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int main()
{
    int T;
    long long r,t;
    freopen("A-small-attempt0.in.txt","r",stdin);
	freopen("A-small-attempt0.out.txt","w",stdout);
    
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%lld%lld",&r,&t);
        long long left, right, mid;
        left=0;
        right=sqrt(t);
        while(right-left>1) {
            mid=(right+left)/2;
            if(2*mid*mid+(2*r-1)*mid<t){
                left = mid;
            }
            else {
                right = mid;
            }
        }
        while(2*mid*mid+(2*r-1)*mid>t)
        {
            mid--;
        }
        while(2*mid*mid+(2*r-1)*mid<=t)
        {
            mid++;
        }
        mid--;
        printf("Case #%d: %lld\n",i,mid);
    }
    return 0;
}

