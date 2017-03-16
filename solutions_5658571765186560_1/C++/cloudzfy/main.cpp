//
//  main.cpp
//  codejam
//
//  Created by Cloudzfy on 3/11/15.
//  Copyright (c) 2015 Cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main(int argc, const char * argv[]) {
    int T;
    int X,R,C;
    freopen("D-large.in.txt","r",stdin);
    freopen("D-large.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d%d",&X,&R,&C);
        int tmp;
        if(R>C)
        {
            tmp=R;
            R=C;
            C=tmp;
        }
        if(R*C%X!=0)printf("Case #%d: RICHARD\n",t);
        else
        {
            if(X==1 && R>=1 && C>=1) printf("Case #%d: GABRIEL\n",t);
            else if(X==2 && R>=1 && C>=2) printf("Case #%d: GABRIEL\n",t);
            else if(X==3 && R>=2 && C>=3) printf("Case #%d: GABRIEL\n",t);
            else if(X==4 && R>=3 && C>=4) printf("Case #%d: GABRIEL\n",t);
            else if(X==5 && R>=4 && C>=5) printf("Case #%d: GABRIEL\n",t);
            else if(X==6 && R>=4 && C>=6) printf("Case #%d: GABRIEL\n",t);
            else printf("Case #%d: RICHARD\n",t);
        }
    }
    return 0;
}
