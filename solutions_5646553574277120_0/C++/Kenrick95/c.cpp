#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
#define INF 1000000007
#define INFLL 9223372036854775807LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/**
 * @problem 
 * @url    
 * @status  
 */

int T, t, c, d, v, cv[128], su[128 * 128], N;

bool can(int i, int vs, int vt) {
    if (i == N)
        return (vs == vt);
    else
        return can(i + 1, vs + cv[i], vt) || can(i + 1, vs, vt);
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &c, &d, &v);
        for (int i = 0 ; i < d; i++) {
            scanf("%d", &cv[i]);
        }
        sort(cv, cv + d);
        // assume c = 1 first (small)
        bool bisa = true, tbisa;
        int ans = 0;
        N = d;
        for (int i = 1; i <= v; i++) {
            tbisa = can(0, 0, i);
            // printf("%d: %d\n", i, tbisa);
            if (!tbisa) {
                ans++;
                cv[N++] = i;
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
