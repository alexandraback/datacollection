#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <cstring>
using namespace std;
//bool mark[10001];
char key[10], target[10], now[10];
int s, cnt=0, l, k, x, m;
void dfs(int d) {
    if(d==s) {
        int c=0;
        for(int i=l-1, j; i<s; i++) {
            for(j=i-l+1; j<=i; j++)
                if(now[j]!=target[j-(i-l+1)]) break;
            if (j>i) cnt++, c++;

            if(c>m) m=c;
        }
        return;
    }
    for(int i=0; i<k; i++) {
        now[d]=key[i];
        dfs(d+1);
    }
}
int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int i, T, t;
    for(scanf("%d", &T), t=1; t<=T; t++) {
        scanf("%d%d%d", &k,&l,&s);
        scanf("%s%s", key, target);
        for(i=x=1; i<=s; i++) x*=k;
        dfs(cnt=m=0);
        printf("Case #%d: %lf\n", t,  m-cnt*1.0/x);
    }
    return 0;
}
