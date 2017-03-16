//
//  main.cpp
//  codejam
//
//  Created by cloudzfy on 4/27/13.
//  Copyright (c) 2013 cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long long v[10000];
int cmp(const void *a, const void *b)
{
    if(*((long long*)a)>*((long long*)b))
    {
        return -1;
    }
    else if(*((long long*)a)<*((long long*)b))
    {
        return 1;
    }
    else return 0;
}
int main()
{
    int T;
    long long N,E,R,result;
    freopen("B-small-attempt1.in.txt","r",stdin);
	freopen("B-small-attempt1.out.txt","w",stdout);
    
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%lld%lld%lld",&E,&R,&N);
        for(int i=0;i<N;i++)
        {
            scanf("%lld",&v[i]);
        }
        qsort(v,N,sizeof(v[0]),cmp);
        result=v[0]*E;
        long long x,a,b,tmp;
        if(E%R!=0) {
            tmp=E/R+1;
            x = (N-1)/(tmp);
            a=tmp*R-E;
            b=(N-1-tmp*x)*R;
        } else {
            tmp=E/R;
            x = (N-1)/tmp;
            a=0;
            b=(N-1-tmp*x)*R;
        }
        for(long long i=1;i<=x;i++)
        {
            result+=v[i]*E;
        }
        if(a>b){
            result+=v[x+1]*a;
            for(long long i=x+2;i<x+2+x;i++){
                result+=v[i]*b;
            }
        }
        else {
            for(long long i=x+1;i<x+1+x;i++){
                result+=v[i]*b;
            }
            result+=v[x+1+x]*a;
        }
        printf("Case #%d: %lld\n",t,result);
    }
    return 0;
}

