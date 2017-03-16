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

typedef long long LL;

vector<LL> a;

bool check(LL n){
    string s = "";
    while(n != 0){
        s = char(n % 10 + 48) + s;
        n /= 10;
    }
    int len = s.length();
    for(int i = 0; i < len / 2; i++){
        if(s[i] != s[len - i - 1]) return false;
    }
    return true;
}

void pre(){
    for(LL i = 1; i * i <= 1e14; i++){
        if(i > 10 && i % 10 > 2) continue;
        if(check(i) && check(i*i)){
            a.push_back(i*i); 
        }
    }
}

int solve(LL l, LL r){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++)
        if(l <= a[i] && a[i] <= r) cnt++;
    return cnt;
}


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    pre();
    int T;
    cin>>T;
    for(int i = 1; i <= T; i++){
        LL a, b;
        cin>>a>>b;
        int ans = solve(a, b);
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}
