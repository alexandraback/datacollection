//
//  main.cpp
//  GCJ
//
//  Created by 祝风翔 on 14-5-11.
//  Copyright (c) 2014年 祝风翔. All rights reserved.
//

#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
const int N = 100 + 5;
int n;
string car[N];
int num[30];
vector<int>s[N];
const LL Mod = 1000000007;
vector<int>E[30];
int deg[30];
LL ans = 1;
int all[30 + 5];
int cur[30 + 5];
LL cal(int n) {
    LL a = 1;
    for(int i = 1;i <= n;i++) {
        a = a * i;
        a = a % Mod;
    }
    return a;
}
bool can() {
    ans = 1;
    memset(all,0,sizeof(all));
    memset(cur,0,sizeof(cur));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < car[i].length();j++){
            cur[car[i][j] - 'a'] = 1;
        }
        if(car[i][0] == car[i][car[i].length()-1]) {
            int x = car[i][0];
            for(int j = 0;j < car[i].length();j++)
                if(car[i][j] != x) return false;
            all[x - 'a']++;
        }else{
            for(int j = 0;j < car[i].length();j++) {
                if(j + 1 < car[i].length() && car[i][j+1] != car[i][j]) {
                    deg[car[i][j] - 'a']++;
                    E[car[i][j] - 'a'].push_back(car[i][j+1] - 'a');
                }
                if(j - 1 >= 0 && car[i][j-1] != car[i][j]) {
                    deg[car[i][j] - 'a']++;
                    E[car[i][j] - 'a'].push_back(car[i][j-1] - 'a');
                }
            }
        }
    }
    /*for(int i = 0;i < 26;i++){
        if(E[i].size() == 0) continue;
        printf("%c:",'a'+i);
        for(int j = 0;j < E[i].size();j++){
            printf("%c ",'a' + E[i][j]);
        }
        printf("\n");
    }*/
    for(int i = 0;i < 26;i++) {
        if(deg[i] > 2) return false;
        ans = ans * cal(all[i]);
        ans = ans % Mod;
    }
    for(int i = 0;i < 26;i++) {
        if(E[i].size() == 2 && E[i][0] == E[i][1])
            return false;
    }
    //printf("ans:%lld\n",ans);
    return true;
}
int used[30];
bool dfs(int R,int prep) {
    used[R] = 1;
    for(int i = 0;i < E[R].size();i++) {
        int p = E[R][i];
        if(p == prep) continue;
        if(used[p] == 1) return false;
        if(dfs(p,R) == false) return false;
    }
    return true;
}
int main(int argc, const char * argv[])
{

    // insert code here...
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int t,cas = 0;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        for(int i = 0;i < n;i++) {
            cin>>car[i];
        }
        for(int i = 0;i < 26;i++){
            E[i].clear();
            deg[i] = 0;
        }
        if(!can()) {
            printf("Case #%d: 0\n",++cas);
            continue;
        }else{
            int cnt = 0;
            memset(used,0,sizeof(used));
            int f = 0;
            for(int i = 0;i < 26;i++) {
                if(cur[i] == 0) continue;
                if(used[i] == 0) {
                    cnt++;
                    if(dfs(i,-1) == false) {
                        f = 1;
                        break;
                    }
                }
            }
            if(f == 1){
                printf("Case #%d: 0\n",++cas);
                continue;
            }
            ans = ans * cal(cnt);
            ans = ans % Mod;
            printf("Case #%d: %lld\n",++cas,ans);
        }
    }
    return 0;
}

