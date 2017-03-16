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
int height[2501];
int main(int argc, const char * argv[]) {
    int T,N;
    freopen("B-small-attempt0.in.txt","r",stdin);
    freopen("B-small-attempt0.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d", &N);
        memset(height, 0, sizeof(height));
        for (int i = 0; i < 2 * N - 1; i++) {
            for (int j = 0; j < N; j++) {
                int tmp;
                scanf("%d",&tmp);
                height[tmp]++;
            }
        }
        vector<int> ans;
        for (int i = 1; i <= 2500; i++) {
            if (height[i] % 2) ans.push_back(i);
        }
        printf("Case #%d:",t);
        for (int i = 0; i < ans.size(); i++) {
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
