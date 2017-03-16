//
//  main.cpp
//  codejam
//
//  Created by Cloudzfy on 3/11/15.
//  Copyright (c) 2015 Cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int P[1000];
int main(int argc, const char * argv[]) {
    int T,D;
    freopen("B-small-attempt0.in.txt","r",stdin);
    freopen("B-small-attempt0.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&D);
        int max=0;
        for(int i=0;i<D;i++)
        {
            scanf("%d",&P[i]);
            if(max<P[i]) max=P[i];
        }
        int ans=1000;
        for(int i=max;i>=1;i--)
        {
            int anst=0;
            for(int j=0;j<D;j++)
            {
                int tmp=P[j];
                while(tmp>i)
                {
                    tmp-=i;
                    anst++;
                }
            }
            if(ans>anst+i)ans=anst+i;
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
