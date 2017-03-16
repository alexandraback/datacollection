//
//  main.cpp
//  codejam
//
//  Created by 李科 on 16/4/9.
//  Copyright © 2016年 李科. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

typedef long long int LL;


string getstring(int k, int n) {
    ostringstream s1;
    int d[30];
    for (int i = n; i >= 0; i--) {
        d[i] = k % 2;
        k = k / 2;
    }
    d[0] = d[n + 1] = 1;
    for (int i = 0; i <= n + 1; i++) {
        s1 << d[i];
    }
    return s1.str();
}


int f[1010];
int ans = 0;
int e[104][103];
bool vis[104];

void dfs(int i, int pre, int n, int t, int s) {
//    if (s == 1) {
//        cout << i << " " << pre << " " << t << endl;
//    }
    
    if (vis[i]) {
        if (i == s) {
            ans = max(ans, t);
        }
        return;
    }

    vis[i] = true;
    
    if (f[i] == pre) {
       // ans = max(ans, t + 1);
        for (int j = 1; j <= n; j++) {
            //if (!vis[j]) {
            //    vis[j] = true;
                dfs(j, i, n, t + 1, s);
            //    vis[j] = false;
           // }
        }
    }
    else {
        for (int j = 1; j <= n; j++) {
            if (e[i][j]) {
               // vis[j] = true;
                dfs(j, i, n, t + 1, s);
               // vis[j] = false;
            }
        }
    }
    vis[i] = false;
}



int main(int argc, const char * argv[]) {
    
    ifstream cin("/Users/like/Downloads/C-small-attempt0.in");
    ofstream cout("/Users/like/Desktop/Github/googlecodejam/codejam/codejam/C-small-attem.out");
    

    int t;
    cin >> t;
    
    for (int tt = 1; tt <= t; tt++) {
        
        int n;
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            cin >> f[i];
        }
        
        
        memset(e, 0, sizeof(e));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (f[i] == j) {
                    e[i][j] = 1;
                }
            }
        }
        
        memset(vis, 0, sizeof(vis));
        ans = 0;
        
        for (int i = 1; i <= n; i++) {
            vis[i] = true;
            dfs(f[i], i, n, 1, i);
            vis[i] = false;
           // cout << ans << endl;
        }
        
        cout << "Case #" << tt << ": " << ans << endl;
        
    }
    
    return 0;
}


