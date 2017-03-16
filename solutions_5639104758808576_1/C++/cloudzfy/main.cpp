//
//  main.cpp
//  codejam
//
//  Created by Cloudzfy on 3/11/15.
//  Copyright (c) 2015 Cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
char data[2000];
int main(int argc, const char * argv[]) {
    int T,N;
    freopen("A-large.in.txt","r",stdin);
    freopen("A-large.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        int result = 0;
        scanf("%d %s",&N, data);
        int s=0;
        for(int i=0;i<=N;i++)
        {
            data[i]=data[i]-'0';
            if(s<i)
            {
                result+=i-s;
                s=i;
            }
            s+=data[i];
        }
        printf("Case #%d: %d\n",t,result);
        
    }
    return 0;
}
