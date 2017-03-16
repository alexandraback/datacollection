//
//  main.cpp
//  round3_3
//
//  Created by wangdongfang on 15/5/10.
//  Copyright (c) 2015年 _. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>



using namespace std;
typedef pair<int, int> Pair;


int C;
int D;
int V;

int coin[10000];

bool dp[10000][100];

int new_D;

bool find(int value) {
   
    dp[0][coin[0]] = true;
    dp[0][0] = true;
    for (int i = 1; i < new_D; i++) {
        dp[i][0] = true;
        for (int j = 1; j <= value; j++ ) {
            dp[i][j] = dp[i - 1][j - coin[i]] || dp[i-1][j];
        }
    }
    return dp[new_D - 1][value];
}

void solve(int round) {
    for (int i = 1; i <= V; i++) {
        bool can_find = find(i);
        if (can_find == false) {
            
            coin[new_D] = i;
   //         cout << "add " << i << endl;
            new_D++;
        }
    }
    cout << "Case #" << round << ": " << (new_D - D) << endl;
}



int main() {
    
 //   freopen("/Users/wangdongfang/Myprogram/codejam2015/round3/round3_3/round3_3/sampledata", "r", stdin);
    
    int T;
    
    cin >> T;
    
    for (int i = 1; i <= T; i++) {
        cin >> C >> D >> V;
        new_D = D;
        for (int i = 0; i < D; i++) {
            for (int j = 0; j <= V; j++) {
                dp[i][j] = false;
            }
        }
        for (int j = 0; j < D; j++) {
            cin >> coin[j];
        }
        solve(i);
    }
    
    return 0;
}
