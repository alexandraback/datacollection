#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <queue>
#include <stack>
#define zero(x) (((x)>0?(x):-(x))<eps)
//#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof((a)))
#define lld long long
#define INF 0x3f3f3f3f
#define eps 1e-6

using namespace std;

int num1, num2, num3;
int d1[39], d2[39], d3[39];
long long dp[39][39];

long long dfs(int a, int status, bool f1, bool f2) {
    if(a == -1) return status != 0 ? 1 : 0;
    if(dp[a][status] != -1 && (!f1) && (!f2)) {
//        printf("%d %d %d %d %lld\n", a, status, f1, f2, dp[a][status]);
        return dp[a][status];
    }
    int up1 = f1 ? d1[a] : 1;
    int up2 = f2 ? d2[a] : 1;
    long long ret = 0;
    for(int i = 0; i <= up1; i++) {
        for(int j = 0; j <= up2; j++) {
            if(status == 0 && (d3[a] == 0) && (i + j == 2)) continue;
//            printf("#%d %d %d %d-> %d\n", status, i, j, d3[a], status | ((d3[a] == 1 && (i + j < 2)) ? 1 : 0));
            ret += dfs(a - 1, status | ((d3[a] == 1 && (i + j < 2)) ? 1 : 0), f1 && (i == up1), f2 && (j == up2));
        }
    }
    if(!f1 && !f2) dp[a][status] = ret;
//    printf("%d %d %d %d %lld\n", a, status, f1, f2, ret);
    return ret;
}

int MAIN() {
    scanf("%d%d%d", &num1, &num2, &num3);
    num1--;
    num2--;
    mem(d1, 0);
    mem(d2, 0);
    mem(d3, 0);
    for(int i = 0; i < 33; i++) {
        d1[i] = num1 % 2;
        num1 /= 2;
    }
    for(int i = 0; i < 33; i++) {
        d2[i] = num2 % 2;
        num2 /= 2;
    }
    for(int i = 0; i < 33; i++) {
        d3[i] = num3 % 2;
        num3 /= 2;
    }
    mem(dp, -1);
    long long rt = dfs(33, 0, true, true);
    cout << rt << endl;
    return 0;
}

int main() {
#ifdef LOCAL_TEST
    freopen("F:/ACMData.txt","r",stdin);
    freopen("F:/out.txt","w",stdout);
#endif
    int cases;
    scanf("%d", &cases);
    int cc = 1;
    while(cases--) {
        printf("Case #%d: ", cc++);
        MAIN();
    }
    return 0;
}
