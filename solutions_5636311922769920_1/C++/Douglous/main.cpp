//
//  main.cpp
//  D-large
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

int k,c,s;

const int maxc = 105;

int p[maxc];

int main(int argc, const char * argv[]) {
    freopen("D-large.in","r",stdin);
    freopen("out","w",stdout);
    cin >> T;
    for(int kase = 1; kase <= T;kase++){
        cin >> k >> c >> s;
        printf("Case #%d:",kase);
        if(s * c < k){
            printf(" IMPOSSIBLE\n");
        }else{
            int ans = (k + c - 1)/c;
            for(int i = 1;i <= ans;i++){
                for(int j = (i - 1) * c + 1;j <= i * c;j++){
                    p[j - (i - 1) * c] = min(j,k);
                }
                long long base = k;
                long long ans = 0;
                for(int j = 1;j <= c;j++){
                    ans = ans * base + (p[j] - 1);
                }
                //for(int j = 1;j <= c;j++)
                //    printf("%d",p[j]);
                cout << ' ' << ans + 1;
            }
            cout << endl;
        }
    }
    return 0;
}
