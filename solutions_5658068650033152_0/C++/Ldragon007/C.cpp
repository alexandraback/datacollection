#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int n, m, q;
bool vis[20][20];

int check(int t) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n * m; i ++ )
        if (t & (1 << i)) vis[i / m][i % m] = true;
    int cnt = 0;
    for (int i = 1; i < n - 1; i ++ )
        for (int j = 1; j < m - 1; j ++ )
            if (vis[i][j] && vis[i - 1][j] && vis[i][j - 1] && vis[i + 1][j] && vis[i][j + 1]) cnt ++ ;
    return cnt;
}

int bfs() {
    int ans = 0;
    for (int i = 0; i < (1 << (n * m)); i ++ ) {
        int ct = 0;
        for (int j = 0; j < n * m; j ++ )
            if (i & (1 << j)) ct ++ ;
        if (ct == q) ans = max(ans, check(i));
    }
    return ans;
}

int main() {
    freopen("C0.in", "r", stdin);
    freopen("C0.out", "w", stdout);
    int T;
    cin>>T;
    for (int ca = 1; ca <= T; ca ++ ) {
        cin>>n>>m>>q;
        cout<<"Case #"<<ca<<": "<<q - bfs()<<endl;
    }
    return 0;
}

