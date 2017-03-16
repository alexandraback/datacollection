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

const int maxn = 100 + 1;
vector<int> x[maxn], y[maxn];
int a[maxn][maxn];
int b[maxn][maxn];
bool v[maxn][maxn];
int n, m, h;

bool cut(int xx, int yy, int h){
    bool rc = true, lc = true;
    for(int i = 0; i < n; i++)
        if(a[i][yy] > h) lc = false;
    for(int j = 0; j < m; j++)
        if(a[xx][j] > h) rc = false;
    
    if(!lc && !rc) return false;
    if(lc)
        for(int i = 0; i < n; i++){
            b[i][yy] = h;
        }
    if(rc)
        for(int j = 0; j < m; j++){
            b[xx][j] = h;
        }
    return true;
}

bool solve(){
    for(int i = 1; i <= 100; i++){
        x[i].clear();
        y[i].clear();
    }
    cin>>n>>m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin>>h;
            a[i][j] = h;
            b[i][j] = 100;
            x[h].push_back(i);
            y[h].push_back(j);
        }
    for(int h = 2; h >= 1; h--){
        for(int k = 0; k < x[h].size(); k++){
            int xx = x[h][k], yy = y[h][k];
            if(!cut(xx, yy, h)) return false;
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(a[i][j] != b[i][j]) return false;
        }
    return true;
}

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    cin>>T;
    for(int i = 1; i <= T; i++){
        if(solve()) cout<<"Case #"<<i<<": YES"<<endl;
        else cout<<"Case #"<<i<<": NO"<<endl;
    }
    return 0;
}