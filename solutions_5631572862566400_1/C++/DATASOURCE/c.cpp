/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2016-04-16 10:18
# Filename: 		c.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const int MAXN = 1100;

bool vis[MAXN];
int cnt[MAXN];
int rcnt[MAXN];
vector <int> vec[MAXN];
vector <int> rvec[MAXN];

int rdfs(int s){
    //cerr <<"rdfs: s = "<< s << endl;
    int ans = 0;
    //if(rcnt[s]) return rcnt[s];
    vis[s] = true;
    int end = rvec[s].size();
    for(int i = 0; i < end; i++){
        if(!vis[rvec[s][i]]) ans = max(ans, rdfs(rvec[s][i]));
    }
    vis[s] = false;
    //cerr <<"rdfs: s = "<< s <<", ans = "<< ans + 1 << endl;
    return rcnt[s] = ans + 1;
}

int dfs(int s){
    //cerr <<"dfs: s = "<< s << endl;
    int ans = 0;
    //if(cnt[s]) return cnt[s];
    vis[s] = true;
    int end = vec[s].size();
    for(int i = 0; i < end; i++){
        if(!vis[vec[s][i]]){
            int tmp = dfs(vec[s][i]);
            if(tmp == 1){
                ans = max(ans, tmp + rdfs(vec[s][i]) - 1);
                //cerr <<"dfs: s = "<< s <<", ans = "<< ans << endl;
            }else{
                ans = max(ans, dfs(vec[s][i]));
            }
        }
    }
    vis[s] = false;
    return cnt[s] = ans + 1;
}
 
int main(){
    int t, n, v;
    cin >> t;
    for(int Case = 1; Case <= t; Case++){
        cin >> n;
        for(int i = 0; i < MAXN; i++){
            vec[i].clear();
            rvec[i].clear();
        }
        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        memset(rcnt, 0, sizeof(rcnt));
        for(int i = 1; i <= n; i++){
            cin >> v;
            vec[i].push_back(v);
            rvec[v].push_back(i);
        }

        int ans = 0;

        for(int i = 1; i <= n; i++){
            //cerr <<"start = "<< i << endl;
            ans = max(ans, dfs(i));
        }
        cout <<"Case #"<< Case <<": "<< ans << endl;
    }
    return 0;
}

