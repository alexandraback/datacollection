//
//  main.cpp
//  GCJ
//
//  Created by 陶源 on 4/9/16.
//  Copyright © 2016 daisynowhere. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <set>
#include <string>
using namespace std;
int vis[1001];
int NN[1001];
int N;
int dfs(int now, int max, int p);
int main() {
    int T, max, temp;  //num of Test
    freopen("/Users/daisy/Documents/C-small-attempt1.in","r",stdin);
    freopen("/Users/daisy/Documents/C-small-attempt1.out","w",stdout);
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        for (int j = 1; j <= 1000; j++) {
            vis[j] = 0;
            NN[1000] = 0;
        }
        max = 0;
        cin >> N;
        for (int j = 1; j <= N; ++j) {
            cin >> NN[j];
        }
        for (int j = 1; j <= N; ++j) {
            temp = dfs(j, 0, 0);
            if (temp > max)
                max = temp;
        }
        printf("Case #%d: %d", i, max);
        cout << endl;
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}


int dfs(int now, int max, int p){
    int t;
    p++;
    if (max < p) {
        max = p;
    }
    vis[now] = max;
    if (!vis[NN[now]]) {
        t = dfs(NN[now], max, p);
        if(t > max)
            max = t;
    }
    for(int i = 1; i < N; i++){
        if (NN[i] == now && !vis[i]) {
            t = dfs(i, max, p);
            if(t > max)
                max = t;
        }
    }
    return max;
}