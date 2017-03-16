//
//  main.cpp
//  codejam
//
//  Created by cloudzfy on 5/12/13.
//  Copyright (c) 2013 cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;
#define PT 200
struct attack
{
    int w,e;
    int s;
    int d;
}att[1000];
int cmp(const void *a, const void *b)
{
    return ((struct attack*)a)->d-((struct attack*)b)->d;
}
int path[1000],tmp[1000];
int main()
{
    int T,N,NN,result;
    int d;
    int n;
    int w,e;
    int s;
    int delta_d;
    int delta_p;
    int delta_s;
    freopen("C-small-attempt1.in.txt","r",stdin);
	freopen("C-small-attempt1.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        NN=0;
        result=0;
        memset(path,0,sizeof(path));
        memset(tmp,0,sizeof(tmp));
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d%d%d%d%d%d%d%d",&d,&n,&w,&e,&s,&delta_d,&delta_p,&delta_s);
            for(int j=0;j<n;j++)
            {
                att[NN].d=d;
                d+=delta_d;
                att[NN].w=w;
                att[NN].e=e;
                w+=delta_p;
                e+=delta_p;
                att[NN].s=s;
                s+=delta_s;
                NN++;
            }
        }
        qsort(att,NN,sizeof(att[0]),cmp);
        for(int i=0;i<NN;i++)
        {
            if(i>0&&att[i].d!=att[i-1].d)
            {
                for(int j=0;j<1000;j++)
                {
                    path[j]=tmp[j];
                }
            }
            int success=0;
            for(int j=att[i].w;j<att[i].e;j++)
            {
                if(path[j+PT]<att[i].s)
                {
                    success=1;
                    if(tmp[j+PT]<att[i].s)
                    {
                        tmp[j+PT]=att[i].s;
                    }
                }
            }
            if(success)
            {
                result++;
            }
        }
        printf("Case #%d: %d\n",t,result);
    }
    return 0;
}