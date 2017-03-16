#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int e, r, n, v[100];
int ans;

void dfs(int ene, int val, int x) {
    //printf("%d %d %d\n", ene, val, x);
    if(x == n) {
        if(val > ans) ans = val;
        return ;
    }
    int ene1;
    for(int i=0; i<=ene; i++) {
        ene1 = ene - i + r;
        if(ene1 > e) ene1 = e;
        dfs(ene1, val+i*(v[x]), x+1);
    }
}

int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++) {
        scanf("%d%d%d", &e, &r, &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }

        ans = 0;
        dfs(e, 0, 0);
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}
