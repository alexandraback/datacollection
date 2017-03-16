//
//  main.cpp
//  codejam
//
//  Created by Cloudzfy on 3/11/15.
//  Copyright (c) 2015 Cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int one[4][4]={
    {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1},
};
int two[4][4]={
    {0,1,0,1},
    {1,1,1,1},
    {0,1,0,1},
    {1,1,1,1},
};
int three[4][4]={
    {0,0,0,0},
    {0,0,1,0},
    {0,1,1,1},
    {0,0,1,0},
};
int four[4][4]={
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,1},
    {0,0,1,1},
};
int main(int argc, const char * argv[]) {
    int T;
    int X,R,C;
    freopen("D-small-attempt0.in.txt","r",stdin);
    freopen("D-small-attempt0.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d%d",&X,&R,&C);
        if(X==1)
        {
            if(one[R-1][C-1])printf("Case #%d: GABRIEL\n",t);
            else printf("Case #%d: RICHARD\n",t);
        }
        if(X==2)
        {
            if(two[R-1][C-1])printf("Case #%d: GABRIEL\n",t);
            else printf("Case #%d: RICHARD\n",t);
        }
        if(X==3)
        {
            if(three[R-1][C-1])printf("Case #%d: GABRIEL\n",t);
            else printf("Case #%d: RICHARD\n",t);
        }
        if(X==4)
        {
            if(four[R-1][C-1])printf("Case #%d: GABRIEL\n",t);
            else printf("Case #%d: RICHARD\n",t);
        }
    }
    return 0;
}
