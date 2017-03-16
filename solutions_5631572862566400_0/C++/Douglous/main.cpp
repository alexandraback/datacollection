//
//  main.cpp
//  b
//
//  Created by 黄宇凡 on 16/4/12.
//  Copyright © 2016年 黄宇凡. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int C;
int n,m;

const int maxm = 2005;
const int maxn = 2005;

vector<int> malt[maxm];
vector<int> unmalt[maxm];

int f[maxn];

bool solve(){
    for(int i = 1;i <= n + 1;i++){
        bool update = false;
        for(int j = 1;j <= m;j++){
            bool satisfied = false;
            if(malt[j].size() == 0){
                for(int k = 0;k < unmalt[j].size();k++){
                    if(f[unmalt[j][k]] == 0){
                        satisfied = true;
                        break;
                    }
                }
                if(satisfied) continue;
                else return false;
            }else{
                for(int k = 0;k < unmalt[j].size();k++){
                    if(f[unmalt[j][k]] == 0){
                        satisfied = true;
                        break;
                    }
                }
                if(satisfied) continue;
                else{
                    for(int k = 0;k <malt[j].size();k++){
                        if(f[malt[j][k]] == 1){
                            satisfied = true;
                            break;
                        }
                    }
                    if(satisfied) continue;
                    else{
                        f[malt[j][0]] = 1;
                        update = true;
                    }
                }
            }
        }
        if(!update){
            return true;
        }

    }
    return true;
}

int main(int argc, const char * argv[]) {
    freopen("B-large-practice.in","r",stdin);
    freopen("large-out","w",stdout);
    cin >> C;
    for(int kase = 1;kase <= C; kase++){
        cin >> n;
        cin >> m;
        for(int i = 1;i <= m;i++){
            malt[i].clear();
            unmalt[i].clear();
            int t;
            scanf("%d",&t);
            for(int j = 1;j <= t;j++){
                int x,y;
                scanf("%d%d",&x,&y);
                if(y == 0){
                    unmalt[i].push_back(x);
                }else{
                    malt[i].push_back(x);
                }
            }
        }
        for(int i = 1;i <= n;i++) f[i] = 0;
        printf("Case #%d: ",kase);
        if(!solve()) printf("IMPOSSIBLE\n");
        else{
            for(int i = 1;i <= n;i++){
                printf("%d%c",f[i],i == n ? '\n' : ' ');
            }
        }
    }
    return 0;
}
