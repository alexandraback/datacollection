//
//  main.cpp
//  2008Round1A
//
//  Created by 黄宇凡 on 16/4/12.
//  Copyright © 2016年 黄宇凡. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    //freopen("A-large-practice.in","r",stdin);
    //freopen("out","w",stdout);
    int T;
    cin >> T;
    int n;
    vector<int> a;
    vector<int> b;
    for(int kase = 1;kase <= T;kase++){
        a.clear();
        b.clear();
        cin >> n;
        int x,y;
        for(int i = 1;i <= n;i++){
            scanf("%d",&x);
            a.push_back(x);
        }
        for(int i = 1;i <= n;i++){
            scanf("%d",&y);
            b.push_back(y);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        long long ans = 0;
        for(int i = 0;i < n;i++){
            ans += (long long)a[i] * b[n - 1 - i];
        }
        printf("Case #%d: ",kase);
        cout << ans << endl;
    }
    return 0;
}
