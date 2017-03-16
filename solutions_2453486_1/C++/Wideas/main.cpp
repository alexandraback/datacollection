//
//  main.cpp
//  CodeJam
//
//  Created by Dingsheng Yu on 4/13/13.
//  Copyright (c) 2013 Dingsheng Yu. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
#include <string>
using namespace std;

string w[10];

int count(string s, char ch){
    int cnt = 0;
    for(int i = 0; i < s.length(); i++)
        if(s[i] == ch) cnt++;
    return cnt;
}

string solve(){
    for(int i = 0; i < 4; i++){
        cin>>w[i];
    }
    for(int i = 4; i < 8; i++){
        w[i] = "";
        for(int j = 0; j < 4; j++)
            w[i] += w[j][i - 4];
    }
    w[8] = w[9] = "";
    w[8] = w[8] + w[0][0] + w[1][1] + w[2][2] + w[3][3];
    w[9] = w[9] + w[3][0] + w[2][1] + w[1][2] + w[0][3];
    for(int i = 0; i < 10; i++){
        if(count(w[i], 'X') + count(w[i], 'T') == 4) return "X won";
    }
    for(int i = 0; i < 10; i++){
        if(count(w[i], 'O') + count(w[i], 'T') == 4) return "O won";
    }
    int countPoint = 0;
    for(int i = 0; i < 4; i++){
        countPoint += count(w[i],'.');
    }
    if(countPoint == 0) return "Draw";
    return "Game has not completed";
    
    
        
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for(int i = 1; i <= T; i++){
        string ans = solve();
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}
