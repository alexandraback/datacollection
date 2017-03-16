//
//  main.cpp
//  codejam
//
//  Created by Cloudzfy on 3/11/15.
//  Copyright (c) 2015 Cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MIN(a,b) (a)<(b)?(a):(b)
#define eps 1e-15
char S[2000];
int main(int argc, const char * argv[]) {
    int T;
    freopen("A-large.in.txt","r",stdin);
    freopen("A-large.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%s",S);
        string ans;
        for (int i = 0; S[i] != 0; i++) {
            if (ans.length() == 0 || ans[0] > S[i]) ans += S[i];
            else ans = S[i] + ans;
        }
        printf("Case #%d: %s\n",t,&ans[0]);
    }
    return 0;
}
