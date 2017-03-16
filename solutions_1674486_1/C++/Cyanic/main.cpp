//
//  main.cpp
//  abcd
//
//  Created by cyanic MayDay on 12-4-14.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <map>
using namespace std;

vector<int> vec[1001];
int am[1001];
bool ok = false;

bool dfs(int in)
{
    if (am[in] == 1) {
        ok = true;
        return true;
    }
    am[in] = 1;
    for (int i = 0; i < vec[in].size(); i ++) {
        dfs(vec[in][i]);
        if (ok) {
            return true;
        }
    }
}



int main() {
    freopen("/Users/ccyanic/Downloads/A-large.in.txt", "r", stdin);
    freopen("/Users/ccyanic/Downloads/A-large.out.txt", "w", stdout);
    int T, N, M;
    scanf("%d", &T);
    for (int i = 0; i < T; i ++) {
        scanf("%d", &N);
        memset(am, 0, sizeof(am));
        ok = false;
        for (int j = 1; j <= N; j ++) {
            scanf("%d", &M);
            vec[j].clear();
            for (int m = 1; m <= M; m ++) {
                int temp;
                scanf("%d", &temp);
                vec[j].push_back(temp);
            }           
            
        }
        for (int x = 1; x <= N; x ++) {
            memset(am, 0, sizeof(am));
            dfs(x);
            if (ok) {
                break;
            }
        }
        
        if(ok)
            printf("Case #%d: Yes\n", i + 1);
        else {
            printf("Case #%d: No\n", i + 1);
        }
        
        
    }
    
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}











