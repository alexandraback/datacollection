//
//  main.cpp
//  round3_1
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


int R;
int C;
int W;



int main() {
 
    freopen("/Users/wangdongfang/Myprogram/codejam2015/round3/round3_1/round3_1/sampledata", "r", stdin);
    
    int T;
    
    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> R >> C >> W;
        int num = R * (C / W) + W;
        if (C % W == 0)num--;
        cout << "Case #" << i << ": " << num << endl;
    }
    
    return 0;
}
