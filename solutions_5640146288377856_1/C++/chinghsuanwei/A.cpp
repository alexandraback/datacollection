//
//  main.cpp
//  1C
//
//  Created by CityEyes on 2015/5/10.
//  Copyright (c) 2015年 tw.com.miso. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T;
    cin >> T;
    for( int i=1; i<=T; i++){
        int answer;
        int R;
        int C;
        int W;
        cin >> R;
        cin >> C;
        cin >> W;
        
        if( W == C ){
            answer = W;
            answer += (R-1);
        } else if( W > C/2 ){
            answer = W + 1;
            answer += (R-1);
        } else {
            answer = (C-1)/W + W;
            answer += (R-1)*(C/W);
        }
        
        cout << "Case #" << i << ": " << answer << endl;
    
    }
    return 0;
}
