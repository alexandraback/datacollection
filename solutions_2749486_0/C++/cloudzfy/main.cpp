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

int main()
{
    int T,X,Y;
    freopen("B-small-attempt0.in.txt","r",stdin);
	freopen("B-small-attempt0.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d",&X,&Y);
        printf("Case #%d: ",t);
        if(X>0)
        {
            for(int i=0;i<abs(X);i++)
            {
                printf("WE");
            }
        }
        else if(X<0)
        {
            for(int i=0;i<abs(X);i++)
            {
                printf("EW");
            }
        }
        if(Y>0)
        {
            for(int i=0;i<abs(Y);i++)
            {
                printf("SN");
            }
        }
        else if(Y<0)
        {
            for(int i=0;i<abs(Y);i++)
            {
                printf("NS");
            }
        }
        printf("\n");
    }
    return 0;
}