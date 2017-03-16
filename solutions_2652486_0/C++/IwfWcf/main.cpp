//
//  main.cpp
//  C
//
//  Created by IwfWcf on 13-4-27.
//  Copyright (c) 2013年 IwfWcf. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#define N 20

using namespace std;

int n, m, k, a[N], d[N];

bool dfs(int dep)
{
    if (dep == n) {
        for (int i = 0; i < k; i++) {
            int flag = false;
            if (a[i] == 1) flag = true;
            if (n >= 1 && a[i] == d[0]) flag = true;
            if (n >= 2 && (a[i] == d[1] || a[i] == d[0] * d[1])) flag = true;
            if (n >= 3 && (a[i] == d[2] || a[i] == d[0] * d[2] || a[i] == d[1] * d[2] || a[i] == d[0] * d[1] * d[2])) flag = true;
            if (!flag) return false;
        }
        return true;
    }
    for (int i = 2; i <= m; i++) {
        d[dep] = i;
        if (dfs(dep + 1)) return true;
    }
    return false;
}

int main(int argc, const char * argv[])
{
    freopen("/Users/IwfWcf/Desktop/C/input.txt", "r", stdin);
    freopen("/Users/IwfWcf/Desktop/C/output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int cases = 1; cases <= t; cases++) {
        int r;
        scanf("%d%d%d%d", &r, &n, &m, &k);
        printf("Case #%d:\n", cases);
        for (int i = 0; i < r; i++) {
            for (int i = 0; i < k; i++) scanf("%d", &a[i]);
            dfs(0);
            for (int i = 0; i < n; i++) printf("%d", d[i]);
            printf("\n");
        }
    }
    return 0;
}

