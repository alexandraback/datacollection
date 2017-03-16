/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : C.cpp
*   Creation Time : 2013/04/27 10:08:05
*   Environment   : OS X 10.8 & Vim 7.3
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define sign(x) (x < 0 ? -1 : (x > 0))
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

int r, n, m, k;
int p[100], ans[100];

int main(){
    cout << "Case #1:" << endl;
    scanf("%*d%d%d%d%d", &r, &n, &m, &k);
    rep(i, r){
        rep(j, k)
            scanf("%d", &p[j]);

        for(int a1 = 2; a1 <= m; ++a1)
            for(int a2 = 2; a2 <= m; ++a2)
                for(int a3 = 2; a3 <= m; ++a3){
                    bool flag = 1;
                    rep(j, k)
                        if(p[j] != 1 && p[j] != a1 && p[j] != a2 && p[j] != a3
                                && p[j] != a1 * a2 && p[j] != a1 * a3 && p[j] != a2 * a3
                                && p[j] != a1 * a2 * a3){
                            flag = 0;
                            break;
                        }
                    if(flag){
                        printf("%d%d%d\n", a1, a2, a3);
                        goto next;
                    }
                }
next:{}
    }
    return 0;
}
