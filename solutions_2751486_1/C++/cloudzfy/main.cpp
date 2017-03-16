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

char name[1000010];
int main()
{
    int T,n;
    long long result;
    freopen("A-large.in.txt","r",stdin);
	freopen("A-large.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%s%d",name,&n);
        int v=0;
        long long tmp=0;
        result=0;
        for(int i=0;name[i]!=0;i++)
        {
            if(name[i]!='a'&&name[i]!='e'&&name[i]!='i'&&name[i]!='o'&&name[i]!='u')
            {
                v++;
                if(v>=n)
                {
                    tmp=i+1-n+1;
                    result+=tmp;
                }
                else
                {
                    result+=tmp;
                }
            }
            else
            {
                v=0;
                result+=tmp;
            }
        }
        printf("Case #%d: %lld\n",t,result);
    }
    return 0;
}