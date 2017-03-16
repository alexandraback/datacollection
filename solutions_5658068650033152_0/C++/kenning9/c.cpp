#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int TC, n, m, k, dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool grid[20][20];
int flood(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y]) return 0;
    grid[x][y] = 1;
    int ret = 1;
    for(int i = 0; i < 4; ++i){
        ret += flood(x+dir[i][0], y+dir[i][1]);
    }
    return ret;
}
int main(){
    cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        scanf("%d %d %d", &n, &m, &k);
        int ans = n*m;
        for(int i = 1; i < (1 <<(n*m)); ++i){
            int cnt = 0;
            for(int j = 0; j < n; ++j){
                for(int l = 0; l < m; ++l){
                    if(i&(1<<(j*m+l))) grid[j][l] = true, cnt++;
                    else grid[j][l] = false;
                }
            }
            int fc = 0;
            for(int j = 0; j < n; ++j){
                fc += flood(j, 0) + flood(j, m-1);
            }
            for(int j = 0; j < m; ++j){
                fc += flood(0, j) + flood(n-1, j);
            }
            if(n*m - fc >= k) ans = min(ans, cnt);
        }
        printf("Case #%d: %d\n", tc, ans);
    }
}
        
        
