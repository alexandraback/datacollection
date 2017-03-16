//
//  main.cpp
//  a
//
//  Created by 黄宇凡 on 16/4/16.
//  Copyright © 2016年 黄宇凡. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int T;

const int maxn = 1005;

string b;

char ans[maxn * 2];

int main(int argc, const char * argv[]) {
    freopen("A-large.in","r",stdin);
    freopen("lout","w",stdout);
    cin >> T;
    for(int kase = 1;kase <= T;kase++){
        cin >> b;
        int l = b.size();
        string t;
        for(int i = 0;i <l;i++){
            if(t + b[i] > b[i] + t){
                t+=b[i];
            }else{
                t = b[i] + t;
            }
        }
        printf("Case #%d: ",kase);
        cout << t << endl;
    }
    
    return 0;
}
