//A

//
//  main.cpp
//  Contest
//
//  Created by User on 25.03.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <memory.h>
using namespace std;

int n;
vector<int> g[1010];
int was[1010];

bool dfs(int v) {
    was[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (was[u] == 0) {
            if (dfs(u))
                return true;
        }
        else if (was[u] == 2)
            return true;
    }
    was[v] = 2;
    return false;
}

int main (int argc, const char * argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; ++t) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            g[i].resize(0);
        memset(was, 0, sizeof(was));
        for (int v = 0; v < n; ++v) {
            int m;
            cin >> m;
            for (int i = 0; i < m; ++i) {
                int u;
                cin >> u;
                --u;
                g[v].push_back(u);
            }
        }
        bool res = false;
        for (int v = 0; v < n; ++v) {
            memset(was, 0, sizeof(was));
            if (dfs(v)) {
                res = true;
                break;
            }
        }
        printf("Case #%d: ", t + 1);
        if (res)
            printf("Yes\n");
        else
            printf("No\n");
    }
    
    
   
    return 0;
}

