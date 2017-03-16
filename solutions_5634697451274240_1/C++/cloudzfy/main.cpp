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
bool check(char S[]) {
    for (int i = 0; S[i] != 0; i++) {
        if (S[i] == '-') return true;
    }
    return false;
}
void reverse(char S[], int begin, int end) {
    for (int i = begin; i < end; i++) {
        if (S[i] == '+') S[i] = '-';
        else S[i] = '+';
    }
}
int main(int argc, const char * argv[]) {
    int T;
    char S[200];
    freopen("B-large.in.txt","r",stdin);
    freopen("B-large.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%s",S);
        int ans = 0;
        int N = 0;
        while (S[N] != 0) N++;
        while (check(S)) {
            ans++;
            if (S[0] == '+') {
                for (int i = 0; S[i] != 0; i++) {
                    if (S[i] == '-') {
                        reverse(S, 0, i);
                        break;
                    }
                }
            } else {
                bool flag = true;
                for (int i = 0; S[i] != 0; i++) {
                    if (S[i] == '+') {
                        reverse(S, 0, i);
                        flag = false;
                        break;
                    }
                }
                if (flag) reverse(S, 0, N);
            }
        }
        printf("Case #%d: %d\n",t,ans);
        
    }
    return 0;
}
