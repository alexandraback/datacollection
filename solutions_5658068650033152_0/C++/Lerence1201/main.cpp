#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
const int N = 20;
int way[4][2] = {0 , 1 , 0 , -1 , 1 , 0 , -1 , 0};
int s[1 << N] , a[20][20] , vis[N][N];
int n , m , k;
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);
#endif
    for (int i = 1 ; i < 1 << N ; i ++) {
        s[i] = s[i >> 1] + (i & 1);
    }
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        int ans = 20;
        scanf ("%d %d %d" , &n , &m , &k);
        for (int i = 0 ; i < (1 << (n * m)) ; i ++) {
            if (s[i] != k) continue;
            // if (i != 274892) continue;
             memset (a , 0 , sizeof (a));
            for (int j = 0 ; j < n * m ; j ++) {
                if (i & (1 << j))
                    a[j / m][j % m] = 1;
            }
            memset (vis , 0 , sizeof (vis));
            int ret = 0;
            for (int j = 0 ; j < n ; j ++) {
                for (int k = 0 ; k < m ; k ++) {
                    if (vis[j][k] == 0 && a[j][k] == 0) {
                        queue <pair <int , int > > que;
                        que.push (make_pair (j , k));
                        vis[j][k] = 1;
                        while (!que.empty ()) {
                            pair <int , int> u = que.front () , v;
                            que.pop ();
                            if (a[u.first][u.second]) {
                                ret ++;
                                continue;
                            }
                            for (int dir = 0 ; dir < 4 ; dir ++) {
                                v.first = u.first + way[dir][0];
                                v.second = u.second + way[dir][1];
                                if (v.first >= 0 && v.first < n && v.second >= 0 && v.second < m && vis[v.first][v.second] == 0) {
                                    vis[v.first][v.second] = 1;
                                    que.push (v);
                                }
                            }
                        }
                    }
                }
            }
            for (int x = 0 ; x < n ; x ++) {
                for (int y = 0 ; y < m ; y ++) {
                    if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
                        if (vis[x][y] == 0 && a[x][y]) {
                            ret ++;
                        }
                    }
                }
            }
            // if (ret == 5) {
            //     cout << i << endl;
            //     for (int x = 0 ; x < n ; x ++) {
            //         for (int y = 0 ; y < m ; y ++)
            //             cout << a[x][y];
            //         cout << endl;
            //     }
            //     cout << "here : ##########" << endl;
            // } 
            ans = min (ans , ret);

        }
        printf ("Case #%d: %d\n" , ++ cas , ans);
    }
    return 0;
}