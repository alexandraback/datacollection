#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std ;
const int N = 10 ;
int Map[N][N] ;
int n, m ;
string name[N] ;
string ans ;
bool flag ;
bool vis[N][N] ;
vector <int> v ;

bool dfs(int rt, int id, int num) {
    if (num == n)   return 1 ;
    for (int i = 0; i < num; ++i) {
        if (!vis[rt][v[i]] && Map[rt][v[i]]) {
            vis[rt][v[i]] = 1 ;
            if (dfs(v[i], i, num))   return 1 ;
            vis[rt][v[i]] = 0 ;
        }
    }

    if (!vis[rt][v[num]] && Map[rt][v[num]]) {
        vis[rt][v[num]] = 1 ;
        if (dfs(v[num], num, num + 1))   return 1 ;
        vis[rt][v[num]] = 0 ;
    }
    return 0 ;
}

bool can() {
    memset(vis, 0, sizeof(vis)) ;
    return dfs(v[0], 0, 1) ;
}

void deal() {


    string tmp ;
    if (!can()) {
        return ;
    }

    for (int i = 0; i < n; ++i)
        tmp = tmp.append(name[v[i]]) ;
    if (flag == 0)
        ans = tmp, flag = 1 ;
    else
        ans = min(ans, tmp) ;
}

int main() {
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    int T, cas = 1 ;
    scanf("%d", &T) ;

    while (T--) {
        while(v.size() != 0) {
            vector <int> tmp ;
            swap(tmp, v) ;
        }
        memset(Map, 0, sizeof(Map)) ;
        scanf("%d %d", &n, &m) ;
        int sum = 1 ;

        for (int i = 1; i <= n; ++i) {
            cin >> name[i] ;
            v.push_back(i) ;
            sum *= i ;
        }

        for (int i = 0; i < m; ++i) {
            int u, v ;
            scanf("%d %d", &u, &v) ;
            Map[u][v] = Map[v][u] = 1 ;
        }
        string tmp(n * 5, '9') ;
        ans = tmp ;
        flag = 0 ;


        for (int i = 0; i < sum; ++i) {
            deal() ;
            next_permutation(v.begin(), v.end()) ;
        }

        printf("Case #%d: ", cas++) ;
        cout << ans << endl ;
    }
    return 0 ;
}
