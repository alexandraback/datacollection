//
//  main.cpp
//  C
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
int n,J;

const int maxn = 12;

long long check(int i,int base){
    long long ret = 1;
    for(int k = n - 2;k >= 1;k--){
        //cout << k << endl;
        ret = ret * base + ((i & (1 << (k - 1))) != 0);
        //cout << ret << endl;
    }
    ret = ret * base + 1;
    //cout << ret << endl;
    for(long long k = 2;k * k <= ret ;k++){
        if(ret % k == 0) return k;
    }
    return -1;
}

long long a[maxn];

int main(int argc, const char * argv[]) {
    freopen("C-small-attempt1.in","r",stdin);
    freopen("out","w",stdout);
    cin >> T;
    for(int kase = 1;kase <= T;kase++){
        cin >> n >> J;
        //check(13,2);
        //cout << check(13,2) << endl;
        printf("Case #%d:\n",kase);
        int cnt = 0;
        for(int i = 0;i < (1 << (n - 2));i++){
            bool flag = true;
            for(int j = 2;j <= 10;j++){
                long long ans = check(i,j);
                if(ans == -1){
                    flag = false;
                    break;
                }else{
                    a[j] = ans;
                }
            }
            if(flag){
                //cout << i << endl;
                cnt++;
                cout << 1;
                for(int j = n - 3;j >= 0;j--){
                    if(i & (1 << j)){
                        cout << 1;
                    }else{
                        cout << 0;
                    }
                }
                cout << 1;
                for(int j = 2;j <= 10;j++){
                    cout << ' '<< a[j];
                }
                cout << endl;
                if(cnt >= J) break;
            }else{
                continue;
            }
        }
    }
    return 0;
}
