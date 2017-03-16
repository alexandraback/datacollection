//
//  main.cpp
//  D
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

int main(int argc, const char * argv[]) {
    freopen("D-small-attempt0.in","r",stdin);
    freopen("out","w",stdout);
    cin >> T;
    for(int kase = 1;kase <= T;kase++){
        scanf("%d%d%d",&k,&c,&s);
        printf("Case #%d: ",kase);
        for(int i = 1;i <= k;i++){
            printf("%d%c",i,i == k ? '\n':' ');
        }
    }
    return 0;
}
