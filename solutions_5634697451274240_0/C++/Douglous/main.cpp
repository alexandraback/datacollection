//
//  main.cpp
//  B
//
//  Created by 黄宇凡 on 16/4/9.
//  Copyright © 2016年 黄宇凡. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int T;

const int maxn = 105;

char S[maxn];

int main(int argc, const char * argv[]) {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out","w",stdout);
    cin >> T;
    for(int kase = 1;kase <= T;kase++){
        scanf("%s",S + 1);
        int n = strlen(S + 1);
        int ans = 0;
        int en = 0;
        for(int i = n;i >= 1;i--){
            if(S[i] == '-'){
                en = i;
                break;
            }
        }
        for(int i = 1,j = 1;i <= en;i = j + 1,j = i){
            while(j < en && S[j + 1] == S[j]) j++;
            ans++;
        }
        printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}
