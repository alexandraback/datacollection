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
using namespace std;
#define MIN(a,b) (a)<(b)?(a):(b)
#define eps 1e-15
bool check(bool num[]) {
    for (int i = 0; i < 10; i++) {
        if (!num[i]) return false;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int T;
    int N;
    bool num[10];
    freopen("A-large.in.txt","r",stdin);
    freopen("A-large.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        memset(num, 0, sizeof(num));
        scanf("%d", &N);
        if (N == 0) {
            printf("Case #%d: INSOMNIA\n",t);
            continue;
        }
        int ans = 0;
        int tmp = 0;
        while(true) {
            ans += N;
            tmp = ans;
            while (tmp) {
                num[tmp % 10] = 1;
                tmp /= 10;
            }
            if (check(num)) break;
        }
        if (check(num)) {
            printf("Case #%d: %d\n",t,ans);
        }
    }
    return 0;
}
