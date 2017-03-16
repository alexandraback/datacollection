#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
#include <bitset>
#include <ctime>
#include <cmath>
#define  inf  0XFFFFFFF
#define  N    2222222
#define  LL   long long
#define  mod  1000000007ll
#define  eps  1e-10
#define  file1

using namespace std;

#ifdef file
ifstream fi("input.txt");
#define  cin fi
ofstream fo("output.txt");
#define  cout fo
#endif
LL fun(LL v) {
    return v > 0 ? v : -v;
}
char ans[N];
LL x, y;
void dfs(LL xx, LL yy, int cnt) {
    LL deltx = fun(xx - x), delty = fun(yy - y);
    if (deltx == 0 && delty == 0) {
        ans[cnt] = 0;
        return;
    }
    if (deltx == 0) {

        return;
    }
    if (delty == 0) {

        return;
    }
    if (deltx < delty) {

    }
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n; scanf("%d", &n);
    for (int T=1; T<=n; T++) {
        scanf("%lld%lld", &x, &y);
        int cnt = 0;
        if (x > 0) {
            for (int i=0; i<x; i++) {
                ans[cnt++] = 'W';
                ans[cnt++] = 'E';
            }
        }
        else if (x < 0) {
            for (int i=0; i<-x; i++) {
                ans[cnt++] = 'E';
                ans[cnt++] = 'W';
            }
        }
        if (y > 0) {
            for (int i=0; i<y; i++) {
                ans[cnt++] = 'S';
                ans[cnt++] = 'N';
            }
        }
        else if (y < 0) {
            for (int i=0; i<-y; i++) {
                ans[cnt++] = 'N';
                ans[cnt++] = 'S';
            }
        }
        ans[cnt] = 0;
        printf("Case #%d: %s\n", T, ans);
    }
}
