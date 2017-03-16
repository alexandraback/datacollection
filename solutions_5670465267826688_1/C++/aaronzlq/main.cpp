//
//  main.cpp
//  Main
//
//  Created by AIdancer on 15/4/3.
//  Copyright (c) 2015年 AIdancer. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;

const int dict[8][8] = {
    {0,1,2,3,4,5,6,7},
    {1,4,3,6,5,0,7,2},
    {2,7,4,1,6,3,0,5},
    {3,2,5,4,7,6,1,0},
    {4,5,6,7,0,0,0,0},
    {5,0,7,2,0,0,0,0},
    {6,3,0,5,0,0,0,0},
    {7,6,1,0,0,0,0,0}
};
const int N = 10005;
int T, L, n;
LL X;

char str[N<<3], tmp[N];

string solve() {
    LL l, r;
    int pre = 0;
    l = r = -1;
    for(int i = 0; i < n; i++) {
        pre = dict[pre][str[i]-'0'];
        if(pre == 1) {
            l = i;
            break;
        }
    }
    pre = 0;
    for(int i = 1; i <= n; i++) {
        pre = dict[str[n-i]-'0'][pre];
        if(pre == 3) {
            r = L*X - i;
            break;
        }
    }
    if(l==-1 || r==-1 || l>=r)  return "NO";
    LL res = (r-1-l) % (L*4);
    pre = 0;
    for(int i = 1; i <= res; i++) {
        pre = dict[pre][str[l+i]-'0'];
    }
    if(pre != 2)  return "NO";
    return  "YES";
}

int main(int argc, const char * argv[]) {
    cin >> T;
    for(int Case = 1; Case <= T; Case++) {
        cin >> L >> X;
        cin >> tmp;
        for(int i = 0; i < L; i++) {
            if(tmp[i] == 'i')  tmp[i] = '1';
            else if(tmp[i] == 'j')  tmp[i] = '2';
            else if(tmp[i] == 'k')  tmp[i] = '3';
        }
        n = 0;
        LL tx = min(X, LL(8));
        while(tx) {
            for(int j = 0; j < L; j++)  str[n++] = tmp[j];
            tx--;
        }
        string ans = solve();
        printf("Case #%d: %s\n", Case, ans.c_str());
    }
    return 0;
}















