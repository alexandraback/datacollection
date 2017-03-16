#include <stdio.h>
#include <string.h>
#include <iostream>
#include <set>
#include <stack>

using namespace std;

int solve() {
    int c, d, v, ans = 0;
    int val[100];
    scanf("%d%d%d", &c, &d, &v);
    for (int i = 0; i < d; i++) {
        scanf("%d", &val[i]);
    }
    for (int i = 1; i <= v; i++) {
        int flag = 0;
        for (int j = 0; j < (1<<d); j++) {
            int tmp = j, sum = 0, sp = 0;
            while(tmp) {
                if (tmp % 2) {
                    sum += val[sp];
                }
                tmp /= 2;
                sp++;
            }
            if (sum == i) {
                flag = 1;
            }
        }
        if (flag == 0) {
            ans++;
            val[d++] = i;
        }
    }
    return ans;
}

int main() {
    freopen("/Users/hc/Documents/project/c++ test/c++ test/out", "w", stdout);
//    freopen("/Users/hc/Documents/project/c++ test/c++ test/in", "r", stdin);
    freopen("/Users/hc/Downloads/C-small-attempt0.in", "r", stdin);
    int ncase;
    scanf("%d", &ncase);
    for (int i = 0; i < ncase; i++) {
        int ans = solve();
        printf("Case #%d: %d\n", i+1, ans);
    }
    return 0;
}