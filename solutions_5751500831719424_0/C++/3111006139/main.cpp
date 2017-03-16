#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std ;
const int N = 110 ;
int n ;
char s[N][N] ;
char t[N][N] ;
int num[N][N] ;
bool v[N] ;

int abs(int x) {
    return x > 0 ? x : -x ;
}

void deal(int id) {
    int cur = 0 ;
    t[id][0] = s[id][0] ;
    num[id][0] = 1 ;
    for (int i = 1; s[id][i]; ++i) {
        if (s[id][i] != s[id][i-1]) {
            t[id][++cur] = s[id][i] ;
            num[id][cur] = 1 ;
        } else {
            num[id][cur]++ ;
        }
    }
    t[id][++cur] = 0 ;
}

int solve() {
    int res = 0 ;
    for (int i = 0; t[0][i]; ++i) {
        int tmp = 1 << 29 ;
        memset(v, 0, sizeof(v)) ;
        for (int j = 0; j < n; ++j) {
            int cnt = num[j][i] ;
            if (v[cnt]) continue ;
            int ans = 0 ;
            v[cnt] = 1 ;
            for (int k = 0; k < n; ++k)
                ans += abs(num[k][i] - cnt) ;
            tmp = min(tmp, ans) ;
        }
        res += tmp ;
    }
    return res ;
}

int main() {
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    int T, cas = 1 ;
    scanf("%d", &T) ;
    while (T--) {
        memset(num, 0, sizeof(num)) ;
        scanf("%d", &n) ;
        for (int i = 0; i < n; ++i) {
            scanf("%s", s[i]) ;
            deal(i) ;
        }
        bool flag = 1 ;
        for (int i = 1; i < n; ++i) {
            if (strcmp(t[i], t[i-1]) != 0) {
                flag = 0 ;
                break ;
            }
        }
        printf("Case #%d: ", cas++) ;
        if (!flag) {
            puts("Fegla Won") ;
        } else {
            printf("%d\n", solve()) ;
        }
    }
    return 0 ;
}
