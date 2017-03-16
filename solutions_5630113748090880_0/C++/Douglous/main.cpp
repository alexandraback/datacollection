//
//  main.cpp
//  b
//
//  Created by 黄宇凡 on 16/4/16.
//  Copyright © 2016年 黄宇凡. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int T;

int n;

map<int,int> cnt;


int main(int argc, const char * argv[]) {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("small-out","w",stdout);
    cin >> T;
    for(int kase = 1;kase <= T;kase++){
        cin >> n;
        cnt.clear();
        for(int i = 1;i < 2 * n;i++){
            for(int j = 1;j <= n;j++){
                int k;
                cin >> k;
                cnt[k]++;
            }
        }
        vector<int> ans;
        ans.clear();
        for(int i = 1;i <= 2500;i++){
            if(cnt[i] & 1){
                ans.push_back(i);
            }
        }
        printf("Case #%d:",kase);
        for(int i = 0;i < ans.size() ;i++){
            printf(" %d",ans[i]);
        }
        cout << endl;
    }
    return 0;
}
