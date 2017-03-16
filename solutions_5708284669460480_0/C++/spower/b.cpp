#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
char str[10], key[10], target[10];
int k, l, s, cnt, b, mx;
void bana() {
    int cnt = 0;
    for(int i = 0; i <= s-l; i++) {
        bool flag = true;
        for(int j = 0; j < l; j++)
            if(str[i+j] != target[j]){
                flag = false;
                break;
            }
        cnt += flag;
    }
    mx = max(mx, cnt);
    b += cnt;
}
void genstr(int x) {
    if(x >= s) {
        cnt++;
        bana();
        return;
    }
    for(int i = 0; i < k; i++) {
        str[x] = key[i];
        genstr(x+1);
    }
}
int main() {
   freopen("B-small-attempt0.in", "r", stdin);
   freopen("b-small.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++) {
        scanf("%d%d%d", &k, &l, &s);
        scanf("%s", key);
        scanf("%s", target);
        str[s] = '\0';
        cnt = b = mx = 0;
        genstr(0);
        if(b == 0)
            printf("Case #%d: 0\n", cas);
        else
            printf("Case #%d: %0.6lf\n", cas, mx - (double)b / (double)cnt);
    }
    return 0;
}
